//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char *description;
    float amount;
    char *category;
    char *date;
} Expense;

// Create an array of expenses
Expense expenses[MAX_EXPENSES];

// Initialize the number of expenses to 0
int numExpenses = 0;

// Get the user's input
void getExpenses() {
    char input[100];
    printf("Enter an expense (description, amount, category, date): ");
    fgets(input, 100, stdin);
    while (strcmp(input, "quit\n") != 0) {
        // Parse the input
        char *description = strtok(input, ",");
        char *amount = strtok(NULL, ",");
        char *category = strtok(NULL, ",");
        char *date = strtok(NULL, ",");

        // Create a new expense
        Expense expense;
        expense.description = malloc(strlen(description) + 1);
        strcpy(expense.description, description);
        expense.amount = atof(amount);
        expense.category = malloc(strlen(category) + 1);
        strcpy(expense.category, category);
        expense.date = malloc(strlen(date) + 1);
        strcpy(expense.date, date);

        // Add the expense to the array
        expenses[numExpenses] = expense;
        numExpenses++;

        // Get the next input
        printf("Enter an expense (description, amount, category, date): ");
        fgets(input, 100, stdin);
    }
}

// Print the expenses
void printExpenses() {
    for (int i = 0; i < numExpenses; i++) {
        printf("%s, %f, %s, %s\n", expenses[i].description, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

// Free the memory allocated for the expenses
void freeExpenses() {
    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i].description);
        free(expenses[i].category);
        free(expenses[i].date);
    }
}

// Main function
int main() {
    // Get the user's input
    getExpenses();

    // Print the expenses
    printExpenses();

    // Free the memory allocated for the expenses
    freeExpenses();

    return 0;
}