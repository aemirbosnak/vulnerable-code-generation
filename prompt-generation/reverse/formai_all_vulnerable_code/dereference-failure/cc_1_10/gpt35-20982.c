//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char *category;
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

// Function prototypes
void addExpense();
void viewExpenses();

int main() {
    char option;
    do {
        printf("Welcome to the Paranoid Expense Tracker Program!\n");
        printf("Please choose an option:\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. Exit\n");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                addExpense();
                break;
            case '2':
                viewExpenses();
                break;
            case '3':
                printf("Exiting Paranoid Expense Tracker Program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != '3');

    return 0;
}

void addExpense() {
    char category[20];
    float amount;

    printf("Enter expense category: ");
    scanf("%s", category);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    // check for suspicious keywords in category name
    if (strstr(category, "hack") != NULL || strstr(category, "steal") != NULL) {
        printf("Error: suspicious category name detected!\n");
        return;
    }

    Expense expense;
    expense.category = malloc(strlen(category) + 1);
    strcpy(expense.category, category);
    expense.amount = amount;

    expenses[numExpenses++] = expense;

    printf("Expense added successfully.\n");
}

void viewExpenses() {
    if (numExpenses == 0) {
        printf("No expenses to show.\n");
        return;
    }

    printf("----------------------------------------------\n");
    printf("| %-20s | %10s |\n", "Category", "Amount");
    printf("----------------------------------------------\n");

    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        Expense expense = expenses[i];

        // check for suspicious category names
        if (strstr(expense.category, "hack") != NULL || strstr(expense.category, "steal") != NULL) {
            printf("Error: suspicious category name detected!\n");
            return;
        }
        
        printf("| %-20s | $%9.2f |\n", expense.category, expense.amount);
        total += expense.amount;
    }

    printf("----------------------------------------------\n");
    printf("| %-20s | $%9.2f |\n", "Total", total);
    printf("----------------------------------------------\n");
}