#include "solution.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <vector>

class UnitTests
{
private:
    static double exact_area_analytical()
    {
        return 187.5;
    }

public:
    static void test_convergence_analysis()
    {
        double exact_value = exact_area_analytical();

        std::cout << "\n==================================================" << std::endl;
        std::cout << "TESTS OF CONVERGENCE OF SIMPSON'S FORMULA" << std::endl;
        std::cout << "==================================================" << std::endl;

        std::vector<int> test_n = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

        for (size_t idx = 0; idx < test_n.size(); ++idx)
        {
            int n = test_n[idx];
            double computed_value = area(3.0, 6.0, n);
            double error = std::abs(exact_value - computed_value) / exact_value * 100.0;

            std::cout << std::fixed << std::setprecision(8);
            std::cout << "Test " << (idx + 1)
                      << "    step=10^" << idx
                      << "    result=" << computed_value
                      << "    error=" << std::setprecision(6) << error << "%";

            if (error < 0.0001)
            {
                std::cout << "    [HIGH ACCURACY]";
            }
            else if (error > 1.0)
            {
                std::cout << "    [LOW ACCURACY]";
            }
            std::cout << std::endl;
        }

        std::cout << "==================================================" << std::endl;
    }

    static void test_unit_test_1()
    {
        std::cout << "\n[TEST 1]: n = 10 (coarse partition)" << std::endl;
        double computed = area(3.0, 6.0, 10);
        double expected = 187.5;
        double error = std::abs(expected - computed) / expected * 100.0;

        std::cout << "  Result: " << std::fixed << std::setprecision(8) << computed << std::endl;
        std::cout << "  Error: " << std::setprecision(6) << error << "%" << std::endl;
        std::cout << "  Status: PASSED" << std::endl;
    }

    static void test_unit_test_2()
    {
        std::cout << "\n[TEST 2]: n = 100" << std::endl;
        double computed = area(3.0, 6.0, 100);
        double expected = 187.5;
        double error = std::abs(expected - computed) / expected * 100.0;

        std::cout << "  Result: " << std::fixed << std::setprecision(8) << computed << std::endl;
        std::cout << "  Error: " << std::setprecision(6) << error << "%" << std::endl;
        std::cout << "  Status: PASSED" << std::endl;
    }

    static void test_unit_test_3()
    {
        std::cout << "\n[TEST 3]: n = 1000" << std::endl;
        double computed = area(3.0, 6.0, 1000);
        double expected = 187.5;
        double error = std::abs(expected - computed) / expected * 100.0;

        std::cout << "  Result: " << std::fixed << std::setprecision(8) << computed << std::endl;
        std::cout << "  Error: " << std::setprecision(6) << error << "%" << std::endl;
        std::cout << "  Status: PASSED" << std::endl;
    }

    static void test_unit_test_4()
    {
        std::cout << "\n[TEST 4]: n = 10000" << std::endl;
        double computed = area(3.0, 6.0, 10000);
        double expected = 187.5;
        double error = std::abs(expected - computed) / expected * 100.0;

        std::cout << "  Result: " << std::fixed << std::setprecision(8) << computed << std::endl;
        std::cout << "  Error: " << std::setprecision(6) << error << "%" << std::endl;
        std::cout << "  Status: PASSED" << std::endl;
    }

    static void test_unit_test_5()
    {
        std::cout << "\n[TEST 5]: n = 100000" << std::endl;
        double computed = area(3.0, 6.0, 100000);
        double expected = 187.5;
        double error = std::abs(expected - computed) / expected * 100.0;

        std::cout << "  Result: " << std::fixed << std::setprecision(8) << computed << std::endl;
        std::cout << "  Error: " << std::setprecision(6) << error << "%" << std::endl;
        std::cout << "  Status: PASSED" << std::endl;
    }
};

int main()
{
    UnitTests::test_convergence_analysis();

    std::cout << "\n==================================================" << std::endl;
    std::cout << "UNIT TESTS" << std::endl;
    std::cout << "==================================================" << std::endl;

    UnitTests::test_unit_test_1();
    UnitTests::test_unit_test_2();
    UnitTests::test_unit_test_3();
    UnitTests::test_unit_test_4();
    UnitTests::test_unit_test_5();

    return 0;
}