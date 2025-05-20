//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100  // maximum number of expenses
#define MAX_NAME_LEN 20   // maximum length of name for expense category

struct Expense {
    char category[MAX_NAME_LEN];
    float amount;
};

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;    // keep track of number of expenses added
    float totalExpenses = 0.0;

    // loop for user input
    while (1) {
        char input[100];
        printf("\nEnter an expense (or 'done' to stop): ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';  // remove newline character

        // stop loop when user inputs 'done'
        if (strcmp(input, "done") == 0) {
            break;
        }

        // split input by comma
        char *category = strtok(input, ",");
        char *amountStr = strtok(NULL, ",");

        // convert amount string to float
        float amount = atof(amountStr);

        // check if expense array is full
        if (numExpenses == MAX_EXPENSES) {
            printf("\nExpense tracker full. Cannot add more expenses.");
            break;  // stop loop
        }

        // add expense to array
        struct Expense newExpense;
        strcpy(newExpense.category, category);
        newExpense.amount = amount;
        expenses[numExpenses++] = newExpense;

        printf("Expense added: %s, %.2f\n", category, amount);
    }

    // print out all expenses
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s $%.2f\n", expenses[i].category, expenses[i].amount);
        totalExpenses += expenses[i].amount;
    }

    // print out total expenses
    printf("\nTotal Expenses: $%.2f", totalExpenses);

    return 0;
}