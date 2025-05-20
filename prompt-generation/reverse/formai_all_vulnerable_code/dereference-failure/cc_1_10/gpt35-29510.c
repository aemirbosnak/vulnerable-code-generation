//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of characters for strings
#define MAX_CHARS 100

// Struct for storing budget categories and expenses
typedef struct {
    char category[MAX_CHARS];
    double budget;
    double spent;
} Expense;

// Function to calculate total budget and total spent
void calculateTotal(Expense expenses[], int count, double *totalBudget, double *totalSpent) {
    *totalBudget = 0;
    *totalSpent = 0;
    for (int i = 0; i < count; i++) {
        *totalBudget += expenses[i].budget;
        *totalSpent += expenses[i].spent;
    }
}

// Function to print all budget categories and data
void printExpenses(Expense expenses[], int count, double totalBudget, double totalSpent) {
    printf("%-20s %-20s %-20s\n", "Category", "Budget", "Spent");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20.2f %-20.2f\n", expenses[i].category, expenses[i].budget, expenses[i].spent);
    }
    printf("%-20s %-20.2f %-20.2f\n", "Total", totalBudget, totalSpent);
}

int main() {
    int count;
    double totalBudget, totalSpent;
    char answer[MAX_CHARS];

    // Prompt user for number of budget categories
    printf("How many budget categories do you have?\n");
    scanf("%d", &count);

    // Allocate memory for array of Expenses
    Expense *expenses = malloc(count * sizeof(Expense));

    // Prompt user for budget category names and amounts
    for (int i = 0; i < count; i++) {
        printf("What is the name of budget category %d?\n", i+1);
        scanf("%s", expenses[i].category);
        printf("What is the budget for category %d?\n", i+1);
        scanf("%lf", &expenses[i].budget);
        expenses[i].spent = 0;
    }

    // Calculate total budget and total spent
    calculateTotal(expenses, count, &totalBudget, &totalSpent);

    // Print initial expense report
    printf("\nInitial Expense Report:\n");
    printExpenses(expenses, count, totalBudget, totalSpent);

    // Prompt user for expenses until they say they are done
    while (1) {
        printf("Do you have an expense to add? (Yes/No):\n");
        scanf("%s", answer);

        // Check if user is done adding expenses
        if (strcmp(answer, "No") == 0) {
            break;
        }

        // If user wants to add expense, prompt for relevant information
        printf("What is the name of the expense category?\n");
        scanf("%s", answer);

        // Search for matching budget category
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(expenses[i].category, answer) == 0) {
                printf("What is the amount of the expense?\n");
                scanf("%lf", &expenses[i].spent);
                found = 1;
                break;
            }
        }

        // If matching budget category not found, ask user if they want to create a new one
        if (!found) {
            printf("Budget category not found. Do you want to create a new one? (Yes/No):\n");
            scanf("%s", answer);

            // If user wants to create new budget category, prompt for relevant information
            if (strcmp(answer, "Yes") == 0) {
                count++;
                expenses = realloc(expenses, count * sizeof(Expense));
                printf("What is the budget category's name?\n");
                scanf("%s", expenses[count-1].category);
                printf("What is the budget for this category?\n");
                scanf("%lf", &expenses[count-1].budget);
                printf("What is the amount of the expense?\n");
                scanf("%lf", &expenses[count-1].spent);
            }
        }

        // Calculate total budget and total spent
        calculateTotal(expenses, count, &totalBudget, &totalSpent);

        // Print updated expense report
        printf("Updated Expense Report:\n");
        printExpenses(expenses, count, totalBudget, totalSpent);
    }

    // Free dynamically allocated memory
    free(expenses);

    return 0;
}