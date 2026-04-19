#include "sorting.h"
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

static std::vector<int> mergeBuckets(const std::vector<std::list<int>> &buckets)
{
    std::vector<int> mergedArray;
    for (const auto &bucket : buckets)
    {
        for (int value : bucket)
        {
            mergedArray.push_back(value);
        }
    }
    return mergedArray;
}

static void sortByDigit(std::vector<int> &arr, int digit)
{
    if (arr.empty())
        return;
    std::vector<std::list<int>> buckets(10);
    for (int number : arr)
    {
        int bucketIndex = (std::abs(number) / digit) % 10;
        buckets[bucketIndex].push_back(number);
    }
    arr = mergeBuckets(buckets);
}

void radixSort(std::vector<int> &arr)
{
    if (arr.empty())
        return;
    int minVal = *std::min_element(arr.begin(), arr.end());
    int shift = 0;
    if (minVal < 0)
    {
        shift = -minVal;
        for (int &x : arr)
            x += shift;
    }
    int maxVal = *std::max_element(arr.begin(), arr.end());
    for (int digit = 1; maxVal / digit > 0; digit *= 10)
    {
        sortByDigit(arr, digit);
    }
    if (shift > 0)
    {
        for (int &x : arr)
            x -= shift;
    }
}

static int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void bubbleSort(std::vector<int> &arr)
{
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}