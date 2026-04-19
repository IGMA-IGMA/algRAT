#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

const int INSERTION_LIMIT = 32;
const int MIN_PARALLEL_SIZE = 1024;

void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    return mid;
}

int partition(vector<int>& arr, int low, int high) {
    int pivotIdx = medianOfThree(arr, low, high);
    swap(arr[pivotIdx], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (high - low + 1 <= INSERTION_LIMIT) {
        insertionSort(arr, low, high);
        return;
    }
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void parallelSort(vector<int>& arr, int low, int high, int num_threads) {
    if (low >= high) return;
    int size = high - low + 1;
    if (num_threads <= 1 || size <= MIN_PARALLEL_SIZE) {
        quickSort(arr, low, high);
        return;
    }
    int pivot = partition(arr, low, high);
    int left_threads = num_threads / 2;
    int right_threads = num_threads - left_threads;
    thread left_thread([&]() {
        parallelSort(arr, low, pivot - 1, left_threads);
    });
    parallelSort(arr, pivot + 1, high, right_threads);
    left_thread.join();
}

int main() {
    const int SIZE = 20000000;
    vector<int> numbers(SIZE);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, SIZE);
    for (auto& num : numbers) num = dist(gen);
    cout << "Sorting " << SIZE << " numbers..." << endl;
    auto start = chrono::high_resolution_clock::now();
    int num_threads = thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;
    parallelSort(numbers, 0, numbers.size() - 1, num_threads);
    auto end = chrono::high_resolution_clock::now();
    bool ok = is_sorted(numbers.begin(), numbers.end());
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Sorted: " << (ok ? "yes" : "no") << endl;
    cout << "Time: " << elapsed << " ms" << endl;
    cout << "CPU cores: " << num_threads << endl;
    return 0;
}