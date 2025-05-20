//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
typedef struct {
    char *description;
    float amount;
    char *date;
} Expense;

// Define the maximum number of expenses that can be stored
#define MAX_EXPENSES 100

// Create an array of expenses
Expense expenses[MAX_EXPENSES];

// Create a counter to keep track of the number of expenses
int num_expenses = 0;

// Function to add an expense to the array
void add_expense(char *description, float amount, char *date) {
    // Check if the array is full
    if (num_expenses == MAX_EXPENSES) {
        printf("Error: The array of expenses is full.\n");
        return;
    }

    // Allocate memory for the description and date strings
    expenses[num_expenses].description = malloc(strlen(description) + 1);
    expenses[num_expenses].date = malloc(strlen(date) + 1);

    // Copy the description and date strings into the expense structure
    strcpy(expenses[num_expenses].description, description);
    strcpy(expenses[num_expenses].date, date);

    // Set the amount of the expense
    expenses[num_expenses].amount = amount;
    
    // Increment the number of expenses
    num_expenses++;
}

// Function to print the expenses in the array
void print_expenses() {
    // Loop through the array of expenses
    for (int i = 0; i < num_expenses; i++) {
        // Print the description, amount, and date of the expense
        printf("%s\t%.2f\t%s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

// Function to free the memory allocated for the description and date strings
void free_expenses() {
    // Loop through the array of expenses
    for (int i = 0; i < num_expenses; i++) {
        // Free the memory allocated for the description and date strings
        free(expenses[i].description);
        free(expenses[i].date);
    }
}

// Main function
int main() {
    // Add some expenses to the array
    add_expense("Groceries", 100.00, "2023-01-01");
    add_expense("Gas", 50.00, "2023-01-02");
    add_expense("Entertainment", 25.00, "2023-01-03");

    // Print the expenses in the array
    print_expenses();

    // Free the memory allocated for the description and date strings
    free_expenses();

    return 0;
}