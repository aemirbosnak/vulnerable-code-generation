//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define a function to calculate total expenses
int calculateTotalExpenses(int **expenses)
{
    int totalExpenses = 0;
    for (int i = 0; expenses[i] != NULL; i++)
    {
        totalExpenses += expenses[i];
    }
    return totalExpenses;
}

// Define a function to calculate total income
int calculateTotalIncome(int **income)
{
    int totalIncome = 0;
    for (int i = 0; income[i] != NULL; i++)
    {
        totalIncome += income[i];
    }
    return totalIncome;
}

int main()
{
    // Define an array of expenses
    int **expenses = NULL;
    expenses = malloc(sizeof(int *) * 3);
    expenses[0] = 50;
    expenses[1] = 20;
    expenses[2] = NULL;

    // Define an array of income
    int **income = NULL;
    income = malloc(sizeof(int *) * 2);
    income[0] = 100;
    income[1] = NULL;

    // Calculate total expenses
    int totalExpenses = calculateTotalExpenses(expenses);

    // Calculate total income
    int totalIncome = calculateTotalIncome(income);

    // Print total income and expenses
    printf("Total income: %d\n", totalIncome);
    printf("Total expenses: %d\n", totalExpenses);

    // Free memory
    free(expenses);
    free(income);

    return 0;
}