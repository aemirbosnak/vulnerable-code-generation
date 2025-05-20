//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char date[11];
} expense_t;

// Define the structure of the expense tracker
typedef struct {
    expense_t expenses[MAX_EXPENSES];
    int num_expenses;
} expense_tracker_t;

// Create a new expense tracker
expense_tracker_t* create_expense_tracker() {
    expense_tracker_t* expense_tracker = malloc(sizeof(expense_tracker_t));
    expense_tracker->num_expenses = 0;
    return expense_tracker;
}

// Add an expense to the expense tracker
void add_expense(expense_tracker_t* expense_tracker, char* description, float amount, char* date) {
    // Check if the expense tracker is full
    if (expense_tracker->num_expenses == MAX_EXPENSES) {
        printf("Error: Expense tracker is full.\n");
        return;
    }

    // Copy the expense data into the expense tracker
    strcpy(expense_tracker->expenses[expense_tracker->num_expenses].description, description);
    expense_tracker->expenses[expense_tracker->num_expenses].amount = amount;
    strcpy(expense_tracker->expenses[expense_tracker->num_expenses].date, date);

    // Increment the number of expenses
    expense_tracker->num_expenses++;
}

// Print the expenses in the expense tracker
void print_expenses(expense_tracker_t* expense_tracker) {
    // Iterate over the expenses
    for (int i = 0; i < expense_tracker->num_expenses; i++) {
        // Print the expense data
        printf("%s: $%.2f (%s)\n", expense_tracker->expenses[i].description, expense_tracker->expenses[i].amount, expense_tracker->expenses[i].date);
    }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(expense_tracker_t* expense_tracker) {
    free(expense_tracker);
}

// Main function
int main() {
    // Create a new expense tracker
    expense_tracker_t* expense_tracker = create_expense_tracker();

    // Add some expenses to the expense tracker
    add_expense(expense_tracker, "Groceries", 50.00, "2023-01-01");
    add_expense(expense_tracker, "Gas", 20.00, "2023-01-05");
    add_expense(expense_tracker, "Entertainment", 30.00, "2023-01-10");

    // Print the expenses in the expense tracker
    print_expenses(expense_tracker);

    // Free the memory allocated for the expense tracker
    free_expense_tracker(expense_tracker);

    return 0;
}