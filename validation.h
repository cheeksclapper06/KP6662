//
// Created by User on 05.12.2024.
//

#ifndef KP6_VALIDATION_H
#define KP6_VALIDATION_H

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include "customization .h"

unsigned validate_integer_size(const char *message)
{
    bool InvalidInput;
    unsigned value = 0;
    printf("%s", message);
    do
    {
        if (scanf("%u", &value) != 1 || value < 2 || value > 100)
        {
            setTextColor(LIGHT_RED);
            printf("Please enter a value in given range\n");
            setTextColor(RESET_COLOR);
            fflush(stdin);
            InvalidInput = true;
        }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while (InvalidInput);
    return value;
}

double validate_floating_value()
{
    bool InvalidInput;
    double value = 0;
    do
    {
        if (scanf("%lf", &value) != 1 || value < -100 || value > 100)
        {
            setTextColor(LIGHT_RED);
            printf("Please enter a floating value\n");
            setTextColor(RESET_COLOR);
            fflush(stdin);
            InvalidInput = true;
        }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while (InvalidInput);
    return value;
}

double validate_precision()
{
    bool InvalidInput;
    double value = 0;
    do
    {
        if (scanf("%lf", &value) != 1 || value < 1e-15 || value > 1e-1)
        {
            setTextColor(LIGHT_RED);
            printf("Please enter precision in a given range\n");
            setTextColor(RESET_COLOR);
            fflush(stdin);
            InvalidInput = true;
        }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while (InvalidInput);
    return value;
}

char validate_input_getch(const char *message, const unsigned option1, const unsigned option2)
{
    printf("%s", message);
    char input = getch();
    do
    {
        if (input != option1 && input != option2)
        {
            setTextColor(LIGHT_RED);
            printf("Please enter a number in given range\n");
            setTextColor(RESET_COLOR);
            fflush(stdin);
            input = getch();
        }
        else
        {
            fflush(stdin);
            return input;
        }
    }
    while (input != option1 && input != option2);
}
bool validate_diagonally_dominant_matrix(double **a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                sum += fabs(a[i][j]);
            }
        }
        if (fabs(a[i][i]) <= sum)
        {
            setTextColor(LIGHT_RED);
            printf("The matrix is not diagonally dominant\n");
            setTextColor(RESET_COLOR);
            fflush(stdin);
            return false;
        }
    }
    return true;
}
#endif //KP6_VALIDATION_H
