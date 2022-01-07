#include <stdlib.h>
#include <math.h>

double integral (double f (double), double a, double b, double eps2)
{
    double summ = 0.5 * (f (a) + f (b));
    double int1 = 0.0, int2 = 0.0;
    double h = (b - a) / 20.0;
    for (int i = 1; i < 20; i++)
      {
        summ += f (a + i * h);
      }
    int2 = summ * h;
    // I_n = h * (0,5 * f_0 + f_1 + ... + 0,5 * f_n), f_i = f(a + i * h)
    for (int j = 1; ; j *= 2)
      {
        int1 = int2;
        for (int i = 0; i < 20 * j; i++)
          {
            summ += f (a + h / 2 + (double)i * h);
          }
        h = h / 2.0;
        int2 = summ * h;
        /*
          |I - I_n| ~= p * |I_n - I_2n|, p = 1 / 3
          Правило Рунге
        */
        if (fabs ((int1 - int2) / 3 ) < eps2)
          {
            break;
          }
      }
    return int2;
}
