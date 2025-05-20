//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void calculate_expenses(int **expenses, int *total_expenses);
void calculate_savings(int **savings, int *total_savings);

int main()
{
    int **expenses = NULL;
    int **savings = NULL;
    int total_expenses = 0;
    int total_savings = 0;

    expenses = (int *)malloc(MAX * sizeof(int));
    savings = (int *)malloc(MAX * sizeof(int));

    // Input expenses and savings
    printf("Enter your monthly expenses: ");
    scanf("%d", &expenses[0]);

    printf("Enter your monthly savings: ");
    scanf("%d", &savings[0]);

    // Calculate total expenses and savings
    calculate_expenses(expenses, &total_expenses);
    calculate_savings(savings, &total_savings);

    // Display total expenses and savings
    printf("Total expenses: $%d\n", total_expenses);
    printf("Total savings: $%d\n", total_savings);

    // Free memory
    free(expenses);
    free(savings);

    return 0;
}

void calculate_expenses(int **expenses, int *total_expenses)
{
    int i = 0;
    *total_expenses = 0;

    for (i = 0; expenses[i] != NULL; i++)
    {
        *total_expenses += expenses[i];
    }
}

void calculate_savings(int **savings, int *total_savings)
{
    int i = 0;
    *total_savings = 0;

    for (i = 0; savings[i] != NULL; i++)
    {
        *total_savings += savings[i];
    }
}