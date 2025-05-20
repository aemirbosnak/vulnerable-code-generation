//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structure to store expense data
typedef struct {
    double amount;
    char category[20];
    char note[100];
    time_t date;
} Expense;

// Define function to add an expense
void addExpense(Expense *expenses, int *numExpenses) {
    printf("Enter the amount of the expense: ");
    scanf("%lf", &(expenses[*numExpenses].amount));

    printf("Enter the category of the expense: ");
    scanf("%s", expenses[*numExpenses].category);

    printf("Enter any notes for the expense: ");
    scanf("%s", expenses[*numExpenses].note);

    expenses[*numExpenses].date = time(NULL);
    (*numExpenses)++;

    printf("Expense added successfully!\n\n");
}

// Define function to print all expenses
void printExpenses(Expense *expenses, int *numExpenses) {
    printf("All Expenses:\n");
    printf("------------------------------------------------------------\n");
    printf("%-12s%-12s%-12s%s\n", "Date", "Amount", "Category", "Note");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < *numExpenses; i++) {
        printf("%-12s%-12.2lf%-12s%s\n", ctime(&(expenses[i].date)), expenses[i].amount, expenses[i].category, expenses[i].note);
    }

    printf("------------------------------------------------------------\n");
}

int main(void) {
    // Declare variables
    Expense *expenses = NULL;
    int numExpenses = 0;
    int choice;

    // Print menu and get user choice
    do {
        printf("Expense Tracker\n");
        printf("================\n");
        printf("1. Add Expense\n");
        printf("2. Print All Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                // Allocate memory for a new expense
                expenses = (Expense *) realloc(expenses, (numExpenses + 1) * sizeof(Expense));
                if (expenses == NULL) {
                    printf("Failed to allocate memory for the expense!\n\n");
                } else {
                    addExpense(expenses, &numExpenses);
                }
                break;
            case 2:
                if (numExpenses == 0) {
                    printf("No expenses to print!\n\n");
                } else {
                    printExpenses(expenses, &numExpenses);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again...\n\n");
        }
    } while (choice != 3);

    // Free dynamically allocated memory
    free(expenses);

    return 0;
}