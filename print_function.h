//
// Created by User on 07.12.2024.

#ifndef PRINT_FUNCTION_H
#define PRINT_FUNCTION_H

#include "customization .h"

void print_SLAE_coefficients(double **a, double *b, const unsigned n, const char *message)
{
    setTextColor(LIGHT_RED);
    printf("WARNING "),
    setTextColor(RESET_COLOR);
    printf("diagonally dominant matrix is required\n"
           "Otherwise the entering process will be restarted\n");
    setTextColor(LIGHT_BLUE);
    printf("%s\n", message);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == n)
            {
                printf("%.1lf * x[%d] ", a[i][j], j + 1);
            }
            else
            {
                printf("+ %.1lf * x[%d] ", a[i][j], j + 1);
            }

        }
        printf("| b[%d] = %.1lf\n", i + 1, b[i]);
    }
    setTextColor(RESET_COLOR);
}

void print_SLAE_elements(double *x, const unsigned n, const double e, const char *message)
{
    setTextColor(LIGHT_YELLOW);
    printf("\n%s\n", message);
    for (int j = 0; j < n; j++)
    {
        printf("x[%d] = %.*lf\n", j + 1,(int)-log10(e), x[j]);
    }
    setTextColor(RESET_COLOR);
}

void print_result_SLAE(double **a, double *b, double *x, const unsigned n, const double e, const char *message)
{
    setTextColor(LIGHT_GREEN);
    printf("\n%s\n", message);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == n)
            {
                printf("%.1lf * %.*lf ", a[i][j], (int)-log10(e), x[j]);
            }
            else
            {
                printf("+ %.1lf * %.*lf", a[i][j], (int)-log10(e), x[j]);
            }
        }
        printf("| b[%d] = %.1lf\n", i + 1, b[i]);
    }
    setTextColor(RESET_COLOR);
}
#endif //PRINT_FUNCTION_H
