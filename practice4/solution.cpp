#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

const int INSERTION_LIMIT = 32;

void insertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int medianOfThree(vector<int> &arr, int low, int high)
{
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    return mid;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivotIdx = medianOfThree(arr, low, high);
    swap(arr[pivotIdx], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (high - low + 1 <= INSERTION_LIMIT)
    {
        insertionSort(arr, low, high);
        return;
    }

    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void parallelSort(vector<int> &arr, int low, int high, int depth)
{
    if (low >= high)
        return;

    if (high - low + 1 <= INSERTION_LIMIT * 2 || depth <= 0)
    {
        quickSort(arr, low, high);
        return;
    }

    int pivot = partition(arr, low, high);

    auto leftTask = async(launch::async, [&]()
                          { parallelSort(arr, low, pivot - 1, depth - 1); });

    parallelSort(arr, pivot + 1, high, depth - 1);
    leftTask.get();
}

void smartSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int cores = thread::hardware_concurrency();
    int maxDepth = max(1, cores * 2);

    parallelSort(arr, 0, arr.size() - 1, maxDepth);
}

int main()
{
    const int SIZE = 20000000;
    vector<int> numbers(SIZE);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, SIZE);

    for (auto &num : numbers)
    {
        num = dist(gen);
    }

    cout << "Sorting " << SIZE << " numbers..." << endl;

    auto start = chrono::high_resolution_clock::now();
    smartSort(numbers);
    auto end = chrono::high_resolution_clock::now();

    bool ok = is_sorted(numbers.begin(), numbers.end());
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Sorted: " << (ok ? "yes" : "no") << endl;
    cout << "Time: " << elapsed << " ms" << endl;
    cout << "CPU cores: " << thread::hardware_concurrency() << endl;

    return 0;
}