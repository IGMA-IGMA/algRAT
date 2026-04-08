#include <iostream>
#include <array>
#include <chrono>

template <typename T, size_t N>
size_t len_massive(const std::array<T, N> &arr)
{
    size_t i = 0;
    for (const auto &_ : arr)
    {
        i++;
    }
    return i;
}

template <typename Func, typename... Args>
auto measure_execution_time(Func &&func, Args &&...args)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = func(std::forward<Args>(args)...);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return std::make_pair(result, duration.count());
}

std::array<int, 10> test1;
std::array<int, 100> test2;
std::array<int, 1000> test3;
std::array<int, 10000> test4;
std::array<int, 100000> test5;
std::array<long long, 1000000> test6;

int main()
{
    for (int i = 0; i < 10; i++)
        test1[i] = i;
    for (int i = 0; i < 100; i++)
        test2[i] = i;
    for (int i = 0; i < 1000; i++)
        test3[i] = i;
    for (int i = 0; i < 10000; i++)
        test4[i] = i;
    for (int i = 0; i < 100000; i++)
        test5[i] = i;
    for (long long i = 0; i < 1000000; i++)
        test6[i] = i;

    auto [result1, time1] = measure_execution_time(len_massive<int, 10>, test1);
    std::cout << "Function: len_massive" << std::endl;
    std::cout << "Data size: " << test1.size() << std::endl;
    std::cout << "Time: " << time1 << " microseconds" << std::endl;
    std::cout << "Result: " << result1 << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    auto [result2, time2] = measure_execution_time(len_massive<int, 100>, test2);
    std::cout << "Function: len_massive" << std::endl;
    std::cout << "Data size: " << test2.size() << std::endl;
    std::cout << "Time: " << time2 << " microseconds" << std::endl;
    std::cout << "Result: " << result2 << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    auto [result3, time3] = measure_execution_time(len_massive<int, 1000>, test3);
    std::cout << "Function: len_massive" << std::endl;
    std::cout << "Data size: " << test3.size() << std::endl;
    std::cout << "Time: " << time3 << " microseconds" << std::endl;
    std::cout << "Result: " << result3 << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    auto [result4, time4] = measure_execution_time(len_massive<int, 10000>, test4);
    std::cout << "Function: len_massive" << std::endl;
    std::cout << "Data size: " << test4.size() << std::endl;
    std::cout << "Time: " << time4 << " microseconds" << std::endl;
    std::cout << "Result: " << result4 << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    auto [result5, time5] = measure_execution_time(len_massive<int, 100000>, test5);
    std::cout << "Function: len_massive" << std::endl;
    std::cout << "Data size: " << test5.size() << std::endl;
    std::cout << "Time: " << time5 << " microseconds" << std::endl;
    std::cout << "Result: " << result5 << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    auto [result6, time6] = measure_execution_time(len_massive<long long, 1000000>, test6);
    std::cout << "Function: len_massive" << std::endl;
    std::cout << "Data size: " << test6.size() << std::endl;
    std::cout << "Time: " << time6 << " microseconds" << std::endl;
    std::cout << "Result: " << result6 << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}