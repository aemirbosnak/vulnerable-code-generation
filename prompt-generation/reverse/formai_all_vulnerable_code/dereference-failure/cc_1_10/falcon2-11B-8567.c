//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    float amount;
    char category[MAX_LEN];
} Expense;

int main(void) {
    int n, i;
    char choice;
    char *name;
    float amount;
    char *category;

    // Initialize the list of expenses
    Expense expenses[100];

    // Loop until the user decides to quit
    while (1) {
        printf("\nWelcome to the Expense Tracker!\n");
        printf("1. Add Expense\n2. View Expenses\n3. Quit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &n);

        // Check for a valid choice
        if (n == 1) {
            // Get the expense details
            printf("Enter expense name: ");
            gets(name);
            name[strlen(name)-1] = '\0'; // Remove trailing newline

            printf("Enter expense amount: ");
            scanf("%f", &amount);

            printf("Enter expense category: ");
            gets(category);
            category[strlen(category)-1] = '\0'; // Remove trailing newline

            // Create a new expense
            Expense newExpense;
            strcpy(newExpense.name, name);
            newExpense.amount = amount;
            strcpy(newExpense.category, category);

            // Add the expense to the list
            for (i = 0; i < n; i++) {
                if (strcmp(expenses[i].name, newExpense.name) == 0) {
                    printf("Error: Expense name already exists\n");
                    continue;
                }
            }
            expenses[n] = newExpense;
            n++;

            // Update the maximum number of expenses
            if (n > 100) {
                n = 100;
            }
        } else if (n == 2) {
            printf("\nHere are your expenses:\n");

            for (i = 0; i < n; i++) {
                printf("%s - $%.2f (%s)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            }
        } else if (n == 3) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}