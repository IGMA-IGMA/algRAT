#include "sorting.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

template <typename SortFunc>
double measureTime(SortFunc sortFunc, vector<int> data)
{
    auto start = chrono::high_resolution_clock::now();
    sortFunc(data);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main()
{
    vector<int> sizes = {
        1000, 2000, 3000, 4000, 5000,
        6000, 7000, 8000, 9000, 10000};
    mt19937 rng(42);
    uniform_int_distribution<int> dist(0, 10000);

    cout << fixed << setprecision(6);
    cout << "Size\t\tRadixSort\tBubbleSort\tQuickSort\n";

    for (int size : sizes)
    {
        vector<int> original(size);
        for (int i = 0; i < size; ++i)
        {
            original[i] = dist(rng);
        }

        double tRadix = measureTime([](vector<int> &v)
                                    { radixSort(v); }, original);
        double tBubble = measureTime([](vector<int> &v)
                                     { bubbleSort(v); }, original);
        double tQuick = measureTime([](vector<int> &v)
                                    { quickSort(v, 0, (int)v.size() - 1); }, original);

        cout << size << "\t\t" << tRadix << "\t\t" << tBubble << "\t\t" << tQuick << "\n";
    }

    return 0;
}