//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char* description;
    float amount;
    char* category;
    char* date;
} Expense;

// Create an array of expenses
Expense expenses[MAX_EXPENSES];

// Initialize the number of expenses to 0
int num_expenses = 0;

// Function to add an expense
void add_expense(char* description, float amount, char* category, char* date) {
    // Check if the number of expenses has reached the maximum
    if (num_expenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    // Allocate memory for the description
    expenses[num_expenses].description = malloc(strlen(description) + 1);

    // Copy the description into the array
    strcpy(expenses[num_expenses].description, description);

    // Set the amount
    expenses[num_expenses].amount = amount;

    // Allocate memory for the category
    expenses[num_expenses].category = malloc(strlen(category) + 1);

    // Copy the category into the array
    strcpy(expenses[num_expenses].category, category);

    // Allocate memory for the date
    expenses[num_expenses].date = malloc(strlen(date) + 1);

    // Copy the date into the array
    strcpy(expenses[num_expenses].date, date);

    // Increment the number of expenses
    num_expenses++;
}

// Function to print the expenses
void print_expenses() {
    // Loop through the expenses
    for (int i = 0; i < num_expenses; i++) {
        // Print the description, amount, category, and date
        printf("%s %.2f %s %s\n", expenses[i].description, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

// Function to free the memory allocated for the expenses
void free_expenses() {
    // Loop through the expenses
    for (int i = 0; i < num_expenses; i++) {
        // Free the memory allocated for the description
        free(expenses[i].description);

        // Free the memory allocated for the category
        free(expenses[i].category);

        // Free the memory allocated for the date
        free(expenses[i].date);
    }
}

// Main function
int main() {
    // Add some expenses
    add_expense("Groceries", 50.00, "Food", "2023-01-01");
    add_expense("Gas", 20.00, "Transportation", "2023-01-02");
    add_expense("Rent", 1000.00, "Housing", "2023-01-03");

    // Print the expenses
    print_expenses();

    // Free the memory allocated for the expenses
    free_expenses();

    return 0;
}