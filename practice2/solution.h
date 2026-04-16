#ifndef SOLUTION_H
#define SOLUTION_H

#include <functional>

double simpson_rule(const std::function<double(double)> &f, double a, double b, int n);
double func_y1(double x);
double func_y2(double x);
double diff(double x);
double area(double a, double b, int n);

#endif