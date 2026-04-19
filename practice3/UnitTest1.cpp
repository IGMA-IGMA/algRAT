#include "pch.h"
#include "CppUnitTest.h"
#include "../practice3/sorting.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(QuickSortTests){
        public :
            TEST_METHOD(TestQuickSort_RegularArray){
                std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> expected = {11, 12, 22, 25, 34, 64, 90};
    quickSort(arr, 0, (int)arr.size() - 1);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestQuickSort_AlreadySorted)
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(arr, 0, (int)arr.size() - 1);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestQuickSort_ReverseSorted)
{
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(arr, 0, (int)arr.size() - 1);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestQuickSort_AllEqual)
{
    std::vector<int> arr = {5, 5, 5, 5, 5, 5};
    std::vector<int> expected = {5, 5, 5, 5, 5, 5};
    quickSort(arr, 0, (int)arr.size() - 1);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestQuickSort_SingleElement)
{
    std::vector<int> arr = {42};
    std::vector<int> expected = {42};
    quickSort(arr, 0, 0);
    Assert::AreEqual(expected[0], arr[0]);
}

TEST_METHOD(TestQuickSort_EmptyArray)
{
    std::vector<int> arr = {};
    Assert::AreEqual((size_t)0, arr.size());
}

TEST_METHOD(TestQuickSort_TwoElements)
{
    std::vector<int> arr = {2, 1};
    std::vector<int> expected = {1, 2};
    quickSort(arr, 0, 1);
    Assert::AreEqual(expected[0], arr[0]);
    Assert::AreEqual(expected[1], arr[1]);
}
}
;

TEST_CLASS(RadixSortTests){
    public :
        TEST_METHOD(TestRadixSort_RegularArray){
            std::vector<int> arr = {170, 45, 75, 90, 2, 802, 24, 66};
std::vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};
radixSort(arr);
Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestRadixSort_ReverseSorted)
{
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    radixSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestRadixSort_WithNegative)
{
    std::vector<int> arr = {-5, -2, -8, 0, 3, -1};
    std::vector<int> expected = {-8, -5, -2, -1, 0, 3};
    radixSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestRadixSort_AllEqual)
{
    std::vector<int> arr = {5, 5, 5, 5, 5, 5};
    std::vector<int> expected = {5, 5, 5, 5, 5, 5};
    radixSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestRadixSort_SingleElement)
{
    std::vector<int> arr = {42};
    std::vector<int> expected = {42};
    radixSort(arr);
    Assert::AreEqual(expected[0], arr[0]);
}

TEST_METHOD(TestRadixSort_EmptyArray)
{
    std::vector<int> arr = {};
    radixSort(arr);
    Assert::AreEqual((size_t)0, arr.size());
}

TEST_METHOD(TestRadixSort_TwoElements)
{
    std::vector<int> arr = {2, 1};
    std::vector<int> expected = {1, 2};
    radixSort(arr);
    Assert::AreEqual(expected[0], arr[0]);
    Assert::AreEqual(expected[1], arr[1]);
}
}
;

TEST_CLASS(BubbleSortTests){
    public :
        TEST_METHOD(TestBubbleSort_RegularArray){
            std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
std::vector<int> expected = {11, 12, 22, 25, 34, 64, 90};
bubbleSort(arr);
Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestBubbleSort_AlreadySorted)
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestBubbleSort_ReverseSorted)
{
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestBubbleSort_AllEqual)
{
    std::vector<int> arr = {5, 5, 5, 5, 5, 5};
    std::vector<int> expected = {5, 5, 5, 5, 5, 5};
    bubbleSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestBubbleSort_SingleElement)
{
    std::vector<int> arr = {42};
    std::vector<int> expected = {42};
    bubbleSort(arr);
    Assert::AreEqual(expected[0], arr[0]);
}

TEST_METHOD(TestBubbleSort_EmptyArray)
{
    std::vector<int> arr = {};
    bubbleSort(arr);
    Assert::AreEqual((size_t)0, arr.size());
}

TEST_METHOD(TestBubbleSort_TwoElements)
{
    std::vector<int> arr = {2, 1};
    std::vector<int> expected = {1, 2};
    bubbleSort(arr);
    Assert::AreEqual(expected[0], arr[0]);
    Assert::AreEqual(expected[1], arr[1]);
}

TEST_METHOD(TestBubbleSort_WithNegativeNumbers)
{
    std::vector<int> arr = {-5, -2, -8, 0, 3, -1};
    std::vector<int> expected = {-8, -5, -2, -1, 0, 3};
    bubbleSort(arr);
    Assert::AreEqual(expected, arr);
}

TEST_METHOD(TestBubbleSort_WithDuplicates)
{
    std::vector<int> arr = {5, 2, 8, 2, 9, 1, 5, 5};
    std::vector<int> expected = {1, 2, 2, 5, 5, 5, 8, 9};
    bubbleSort(arr);
    Assert::AreEqual(expected, arr);
}
}
;
}