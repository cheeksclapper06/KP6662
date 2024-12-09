//
// Created by User on 07.12.2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include "validation.h"

void manual_SLAE_input(double **a, double *b, const unsigned n)
{
    do
        {
        for (int i = 0; i < n; i++)
        {
            printf("Enter coefficients of the row %d [-100; 100]\n", i + 1);
            for (int j = 0; j < n; j++)
            {
                printf("a[%d][%d] = ", i + 1, j + 1);
                a[i][j] = validate_floating_value();
            }
            printf("Enter the free term of the row %d\n", i + 1);
            printf("b[%d] = ", i + 1);
            b[i] = validate_floating_value();
        }
    }
    while (!validate_diagonally_dominant_matrix(a, n));
}

void random_SLAE_input(double **a, double *b, const unsigned n, const double min, const double max)
{
    const double range = max - min;
    const double div = RAND_MAX / range;
    for (int i = 0; i < n; i++)
    {
        double row_sum = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                a[i][j] = min + rand() / div;
                row_sum += fabs(a[i][j]);
            }
        }
        a[i][i] = row_sum + (min + rand() / div * (10.0 - 1.0) + 1.0);
        b[i] = min + rand() / div;
    }
}

void free_arrays(double **a, double *b, double *x, double *xp, const unsigned n)
{
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);
    free(xp);
}
#endif //FUNCTION_H
