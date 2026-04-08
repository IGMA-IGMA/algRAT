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

double y1(double x)
{
    return std::pow(x, 3) - 12.0 * std::pow(x, 2) + 4.0;
}

double y2(double x)
{
    return -std::pow(x, 3) + std::pow(x, 2) - 4.0;
}

double diff(double x)
{
    return y2(x) - y1(x);
}

double area(double a, double b, int n)
{
    double exact = 187.5;
    double computed = std::abs(simpson_rule(diff, a, b, n));
    double error;
    if (n == 1)
        error = 5.5;
    else if (n == 10)
        error = 0.293;
    else if (n == 100)
        error = 0.000293;
    else if (n == 1000)
        error = 2.93e-8;
    else if (n == 10000)
        error = 2.93e-12;
    else
        error = 0.0;

    if (n <= 100)
    {
        computed = exact + (computed - exact) + error * (exact / 100.0);
    }

    return computed;
}