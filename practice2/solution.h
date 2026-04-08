#ifndef SOLUTION_H
#define SOLUTION_H

#include <functional>
#include <iostream>

double simpson_rule(const std::function<double(double)> &f, double a, double b, int n);
double y1(double x);
double y2(double x);
double diff(double x);
double area(double a, double b, int n);

#endif