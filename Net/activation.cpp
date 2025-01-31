#include "activation.h"
#include <QtMath>


double relu(double in)
{
    return qMax(in, 0.);
}

double leakyrelu(double in)
{
    double k = 0.01;
    return in < 0 ? in * k : in;
}

double sigmoid(double in)
{
    return 1 / (1 + qExp(-in));
}
