//
// Created by User on 07.12.2024.
//

#ifndef CALCULATION_H
#define CALCULATION_H

#include "math.h"
#define MAX_ITERATION 100
void calculate_SLAE(double **a, double *b, double *x, double *xp, const unsigned int n, const double e)
{
    int iteration = 0;
    double max_delta = 0;
    do
    {
        for(int i = 0; i < n; i++){
            xp[i] = 0.0;
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    xp[i] = xp[i] + (a[i][j] * x[j]);
                }
            }
            xp[i] = (b[i] - xp[i]) / a[i][i];
        }

        max_delta = 0;

        for(int i = 0; i < n; i++)
        {
            if (fabs(x[i] - xp[i]) > max_delta)
            {
                max_delta = fabs(x[i] - xp[i]);
            }
            x[i] = xp[i];
        }
        iteration++;
    }
    while (max_delta > e && iteration <= MAX_ITERATION);
    printf("\nNumber of iterations: ");
    setTextColor(GREEN);
    printf("%d\n", iteration);
    setTextColor(RESET_COLOR);
}
#endif //CALCULATION_H
