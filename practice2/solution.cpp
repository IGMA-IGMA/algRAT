#include "solution.h"
#include <cmath>
#include <iostream>

double simpson_rule(const std::function<double(double)> &f, double a, double b, int n)
{
    if (n % 2 == 1)
        n++;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 4.0 * f(x);
    }

    for (int i = 2; i < n - 1; i += 2)
    {
        double x = a + i * h;
        sum += 2.0 * f(x);
    }

    return (h / 3.0) * sum;
}

double func_y1(double x)
{
    return std::pow(x, 3) - 12.0 * std::pow(x, 2) + 4.0;
}

double func_y2(double x)
{
    return -std::pow(x, 3) + std::pow(x, 2) - 4.0;
}

double diff(double x)
{
    return func_y2(x) - func_y1(x);
}

double area(double a, double b, int n)
{
    return std::abs(simpson_rule(diff, a, b, n));
}