#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"
#include "testroot.h"
#include "testintegral.h"

/*
  f1 = 3 / ((x - 1) ^ 2 + 1)
  f2 = sqrt (x + 0.5)
  f3 = e ^ (-x)
*/

double integral(double f (double), double a, double b, double eps2);
double root (double f(double), double g(double), double a, double b, double eps1);
int count;

int main (int argc, char **argv)
{
    double eps1 = 0.0001;
    double eps2 = 0.00005;
    if (argc == 1)
      {
        printf ("Please, enter commands. Enter '-help' to see available options.\n");
        return 0;
      }
    if (!strncmp(argv[1], "-help", sizeof("-help")))
      {
        printf("Commands:\n"
               " print abscissae \n"
               " print iterations \n"
               " print function \n"
               " print ordinates \n"
               " result \n"
               " test root 1 1 3 0.001 \n"
               " test integral 1 0.0 4.0 0.001 \n");
        return 0;
      }
    if (!strncmp(argv[1], "print", sizeof("print")))
      {
        if (!strncmp(argv[2], "abscissae", sizeof("abscissae")))  // печатаются абсциссы точек пересечения кривых
          {
            printf ("the abscissa of the intersection f1 and f2 is %.4lf\n", root (f1, f2, 1.0, 2.0, eps1));
            printf ("the abscissa of the intersection f2 and f3 is %.4lf\n", root (f2, f3, 0.0, 1.0, eps1));
            printf ("the abscissa of the intersection f1 and f3 is %.4lf\n", root (f1, f3, -1.0, 0.0, eps1));
            return 0;
          }
        if (!strncmp(argv[2], "iterations", sizeof("iterations"))) // печататеся число итераций root
          {
            root (f1, f2, 1.0, 2.0, eps1);
            printf ("%d\n", count);
            count = 0;
            root (f2, f3, 0.0, 1.0, eps1);
            printf ("%d\n", count);
            count = 0;
            root (f1, f3, -1.0, 0.0, eps1);
            printf ("%d\n", count);
            count = 0;
            return 0;
          }
        if (!strncmp(argv[2], "function", sizeof("function"))) // печатается набор заданных функций
          {
            printf ("f1 = 3 / ((x - 1) ^ 2 + 1) \n"
                    "f2 = sqrt (x + 0.5) \n"
                    "f3 = e ^ (-x) \n");
            return 0;
          }
        if (!strncmp(argv[2], "ordinates", sizeof("ordinates"))) // печатается набор заданных функций
          {
            printf ("the ordinate of the intersection f1 and f2 is %.4lf\n", f1 (root (f1, f2, 1.0, 2.0, eps1)));
            printf ("the ordinate of the intersection f2 and f3 is %.4lf\n", f2 (root (f2, f3, 0.0, 1.0, eps1)));
            printf ("the ordinate of the intersection f1 and f3 is %.4lf\n", f3 (root (f1, f3, -1.0, 0.0, eps1)));
            return 0;
          }
      }
    if (!strncmp(argv[1], "test", sizeof("test")))
      {
        if (argc != 7)
          {
            printf ("Wrong number of arguments");
            return -1;
          }
        int numb;
        double a, b, epst;
        sscanf(argv[3], "%d", &numb);
        sscanf(argv[4], "%lf", &a);
        sscanf(argv[5], "%lf", &b);
        sscanf(argv[6], "%lf", &epst);
        if (!strncmp(argv[2], "root", sizeof("root"))) // тестировка root
          {
            if (numb == 1)
              {
                printf ("x^2 crosses x+2 in point %.4lf\n", root (froot11, froot12, a, b, epst));
              }
            if (numb == 2)
              {
                printf ("-x crosses x^3 in point %.4lf\n", root (froot21, froot22, a, b, epst));
              }
            if (numb == 3)
              {
                printf ("sqrt(x) crosses 2^x-14 in point %.4lf\n", root (froot31, froot32, a, b, epst));
              }
            return 0;
          }
        if (!strncmp(argv[2], "integral", sizeof("integral"))) // тестировка integral
          {
            if (numb == 1)
              {
                printf ("square under x^2 from %.10g to %.10g: %.4lf\n", a, b, integral (fint1, a, b, epst));
              }
            if (numb == 2)
              {
                printf ("square under sin(x) from %.10g to %.10g: %.4lf\n", a, b, integral (fint2, a, b, epst));
              }
            if (numb == 3)
              {
                printf ("square under sqrt(x) from %.10g to %.10g: %.4lf\n", a, b, integral (fint3, a, b, epst));
              }
            return 0;
          }
      }
    if (!strncmp(argv[1], "result", sizeof("result"))) // выводим площадь заданной фигуры
      {
        double x1 = root (f1, f2, 1.0, 2.0, eps1);
        double x2 = root (f2, f3, 0.0, 1.0, eps1);
        double x3 = root (f1, f3, -1.0, 0.0, eps1);

        double i1 = integral (f1, x3, x1, eps2);
        double i2 = integral (f2, x2, x1, eps2);
        double i3 = integral (f3, x3, x2, eps2);
        printf ("square of area: %.3lf\n", i1 - i2 - i3);
        return 0;
      }
    printf("Unknown command \n");
    return -1;
}
