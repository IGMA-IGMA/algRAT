#include <vector>
#include <list>


std::vector<int> mergeBuckets(const std::vector<std::list<int>>& buckets) {
    std::vector<int> mergedArray;
    for (int i = 0; i < buckets.size(); i++) {
        std::list<int> bucket = buckets[i];
        for (int value : bucket) {
            mergedArray.push_back(value);
        }
    }
    return mergedArray;
}

void sortByDigit(std::vector<int>& arr, int digit) {
    if (arr.empty()) return;
    std::vector<std::list<int>> buckets(10);
    for (int number : arr) {
        int bucketIndex = (number / digit) % 10;
        buckets[bucketIndex].push_back(number);
    }
    arr = mergeBuckets(buckets);
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int maxNumber = arr[0];
    int i = 1;
    while (maxNumber / i > 0) {
        sortByDigit(arr, i);
        i = i * 10;
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr,int low,int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    return 0;
}