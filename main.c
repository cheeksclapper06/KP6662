#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "function.h"
#include "print_function.h"
#include "calculation.h"
#include "validation.h"
#include "customization .h"

#define ENTER 13

int main()
{
    srand(time(NULL));
    do
    {
        printf("\nThis program calculates SLAE (system of linear algebraic equations)\n");
        printf ("\na[1][1] * x[1] + a[1][2] * x[2] + ... + a[1][n] * x[n] = b[11]\n"
                "a[2][1] * x[1] + a[2][2] * x[2] + ... + a[2][n] * x[n] = b[12]\n"
                "...................................................................\n"
                "a[n][1] * x[11] + a[n][2] * x[12] + ... + a[n][n] * x[n] = b[n]\n\n");
        unsigned n = 0;
        n = validate_integer_size("Enter the size of the SlAE [2 - 100]:\n");

        printf("Enter precision [1e-15; 1e-1]:\n");
        const double e = validate_precision();

        double **a = malloc(n * sizeof(double *));
        double *b = malloc(n * sizeof(double));
        double *x = malloc(n * sizeof(double));
        double *xp = malloc(n * sizeof(double));

        for (int i = 0; i < n; i++)
        {
            a[i] = malloc(n * sizeof(double));
            if (a[i] == NULL)
            {
                setTextColor(LIGHT_RED);
                printf("Memory allocation error\n");
                setTextColor(RESET_COLOR);
                free_arrays(a, b, x, xp, n);
                exit(0);
            }
        }

        if (a == NULL || b == NULL || x == NULL || xp == NULL)
        {
            setTextColor(LIGHT_RED);
            printf("Memory allocation error\n");
            setTextColor(RESET_COLOR);
            free_arrays(a, b, x, xp, n);
            exit(0);
        }
        printf("How do you want to enter the elements of the SLAE?\n");

        const char input_choice = validate_input_getch("1 - Manually\n2 - Randomly\n", 49, 50);

        switch (input_choice)
        {
            case 49:
                manual_SLAE_input(a, b, n);
                print_SLAE_coefficients(a, b, n, "\nManual input SLAE coefficients:\n");
                break;

            case 50:
                random_SLAE_input(a, b, n, -100, 100);
                print_SLAE_coefficients(a, b, n, "\nRandom input SLAE coefficients:\n");
                break;

            default:
                setTextColor(LIGHT_RED);
                printf("Please enter 1 or 2\n");
                setTextColor(RESET_COLOR);
                break;
            }

        calculate_SLAE(a, b, x, xp, n, e);
        print_SLAE_elements(x, n, e,"Found elements of the system:\n");
        printf("Do you want to see how SLAE looks with all coefficients and found elements?\n");
        const char output_choice = validate_input_getch("1 - Yes\n2 - No\n", 49, 50);
        switch (output_choice)
        {
            case 49:
                print_result_SLAE(a, b, x, n, e, "Result SLAE:\n");
                break;

            case 50:
                break;

            default:
                setTextColor(LIGHT_RED);
                printf("Please enter 1 or 2\n");
                setTextColor(RESET_COLOR);
                break;
        }
        free_arrays(a, b, x, xp, n);

        printf("To continue press ");
        setTextColor(GREEN);
        printf("ENTER, ");
        setTextColor(RESET_COLOR);
        printf("to exit press any key\n");
    }
    while (getch() == ENTER);
    return 0;
}
