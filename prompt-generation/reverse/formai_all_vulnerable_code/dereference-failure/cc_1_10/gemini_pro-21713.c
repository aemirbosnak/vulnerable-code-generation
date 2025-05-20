//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char *description;
    float amount;
    char *date;
} expense_t;

// Create an array of expenses
expense_t expenses[MAX_EXPENSES];

// Get the current number of expenses
int num_expenses = 0;

// Add a new expense to the array
void add_expense(char *description, float amount, char *date) {
    // Check if the array is full
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: The array of expenses is full.\n");
        return;
    }

    // Allocate memory for the new expense
    expenses[num_expenses].description = malloc(strlen(description) + 1);
    expenses[num_expenses].date = malloc(strlen(date) + 1);

    // Copy the description, amount, and date into the new expense
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].date, date);

    // Increment the number of expenses
    num_expenses++;
}

// Print the expenses in the array
void print_expenses() {
    // Loop through the expenses
    for (int i = 0; i < num_expenses; i++) {
        // Print the description, amount, and date of the expense
        printf("%s\t%.2f\t%s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

// Free the memory allocated for the expenses
void free_expenses() {
    // Loop through the expenses
    for (int i = 0; i < num_expenses; i++) {
        // Free the memory allocated for the description and date
        free(expenses[i].description);
        free(expenses[i].date);
    }
}

// Main function
int main() {
    // Add some expenses to the array
    add_expense("Groceries", 100.00, "2023-01-01");
    add_expense("Rent", 1200.00, "2023-01-05");
    add_expense("Utilities", 200.00, "2023-01-10");
    add_expense("Entertainment", 100.00, "2023-01-15");
    add_expense("Transportation", 200.00, "2023-01-20");

    // Print the expenses
    print_expenses();

    // Free the memory allocated for the expenses
    free_expenses();

    return 0;
}