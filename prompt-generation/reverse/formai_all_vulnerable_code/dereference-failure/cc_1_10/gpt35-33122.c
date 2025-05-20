//FormAI DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    float amount;
    char* description;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float totalExpenses = 0;

    printf("Welcome to the Happy Expense Tracker! Let's start tracking your expenses!\n");

    while (1) {
        printf("\nEnter the amount of an expense or type 'q' to quit: $");
        char input[100];
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q') {
            break;
        }

        float expenseAmount = atof(input);

        printf("Enter a description for this expense: ");
        char* expenseDescription = malloc(sizeof(char) * 100);
        fgets(expenseDescription, 100, stdin);

        Expense newExpense = {expenseAmount, expenseDescription};
        expenses[numExpenses] = newExpense;

        numExpenses++;
        totalExpenses += expenseAmount;

        printf("Expense added successfully!\n");
    }

    printf("\n\n*****************\n");
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Number of Expenses: %d\n", numExpenses);

    printf("\n\nHere are your expenses: \n\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("Expense #%d - $%.2f - %s\n", i+1, expenses[i].amount, expenses[i].description);
    }

    printf("\n\nHappy saving! Goodbye!\n");

    return 0;
}