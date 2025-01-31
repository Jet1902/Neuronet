#ifndef ACTIVATION_H
#define ACTIVATION_H

typedef double (*activation_func)(double);

double relu(double in);
double leakyrelu(double in);
double sigmoid(double in);

#endif // ACTIVATION_H
