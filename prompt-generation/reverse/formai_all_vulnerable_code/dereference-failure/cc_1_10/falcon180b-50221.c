//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_ROWS 1000
#define MAX_COLS 1000

int main()
{
    int rows, cols;
    double mortgage_amount, interest_rate, term_years, monthly_payment, total_payment;
    double **matrix;

    printf("Welcome to the Futuristic Mortgage Calculator!\n");
    printf("Please enter the following information:\n");

    printf("Mortgage amount: ");
    scanf("%lf", &mortgage_amount);

    printf("Interest rate (%): ");
    scanf("%lf", &interest_rate);

    printf("Term in years: ");
    scanf("%lf", &term_years);

    matrix = (double **)malloc(MAX_ROWS * sizeof(double *));
    for (int i = 0; i < MAX_ROWS; i++)
    {
        matrix[i] = (double *)malloc(MAX_COLS * sizeof(double));
    }

    rows = 0;
    cols = 0;

    while (rows < MAX_ROWS && cols < MAX_COLS)
    {
        monthly_payment = mortgage_amount * interest_rate / (12 * 100) * pow(1 + (interest_rate / 12), term_years * 12);
        total_payment = monthly_payment * term_years * 12;

        matrix[rows][cols] = monthly_payment;
        matrix[rows][cols + 1] = total_payment;

        rows++;
        cols += 2;
    }

    printf("Monthly payment: $%.2lf\n", matrix[0][0]);
    printf("Total payment: $%.2lf\n", matrix[0][1]);

    for (int i = 1; i < rows; i++)
    {
        printf("Monthly payment for %d years: $%.2lf\n", i * 12, matrix[i][0]);
        printf("Total payment for %d years: $%.2lf\n", i * 12, matrix[i][1]);
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}