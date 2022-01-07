#include <stdlib.h>
#include <stdio.h>

int count = 0;

double root (double f(double), double g(double), double a, double b, double eps1)
{
    // F(x) = f(x) - g(x)
    double Fa = f(a) - g(a);
    double Fb = f(b) - g(b);
    double Fmid = f ((a + b) / 2.0) - g ((a + b) / 2.0); // F((a + b) / 2)
    double c = (a * Fb - b * Fa) / (Fb - Fa);
    double Fc = f(c) - g(c);
    // функция возрастает и график ниже хорды или функция убывает и график выше хорды
    if ((Fa < 0.0 && Fmid < (Fa + Fb) / 2.0) || (Fa > 0.0 && Fmid > (Fa + Fb) / 2.0))
      {
        double Fcplus = f (c + eps1) - g (c + eps1); // F(c + eps1)
        if (Fc * Fcplus > 0.0) // одинаковый знак у функции F(x) на отрезке [c, c + eps1]
          {
            count++;
            return root (f, g, c, b, eps1);
          }
        count++;
        return c + eps1 / 2.0; // разный знак => корень на отрезке
      }
    // функция возрастает и график выше хорды или функция убывает и график ниже хорды
    else
      {
        double Fcminus = f (c - eps1) - g (c - eps1); // F(c - eps1)
        if (Fc * Fcminus > 0.0) // одинаковый знак у функции F(x) на отрезке [c - eps1, c]
          {
            count++;
            return root (f, g, a, c, eps1);
          }
        count++;
        return c - eps1 / 2.0; // разный знак => корень на отрезке
      }
}
