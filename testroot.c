#include <math.h>

double froot11 (double x)
{
    return x * x;
}

double froot12 (double x)
{
    return x + 2;
}

double froot21 (double x)
{
    return -x;
}

double froot22 (double x)
{
    return x * x * x;
}

double froot31 (double x)
{
    return sqrt (x);
}

double froot32 (double x)
{
    return pow (2, x) - 14;
}
