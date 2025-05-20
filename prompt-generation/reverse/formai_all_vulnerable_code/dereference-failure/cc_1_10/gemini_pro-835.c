//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char description[100];
    float amount;
    int date;
} expense_t;

// Define the structure of the expense tracker
typedef struct expense_tracker {
    int num_expenses;
    expense_t expenses[MAX_EXPENSES];
} expense_tracker_t;

// Create a new expense tracker
expense_tracker_t* create_expense_tracker() {
    expense_tracker_t* expense_tracker = malloc(sizeof(expense_tracker_t));
    expense_tracker->num_expenses = 0;
    return expense_tracker;
}

// Add an expense to the expense tracker
void add_expense(expense_tracker_t* expense_tracker, char* description, float amount, int date) {
    if (expense_tracker->num_expenses < MAX_EXPENSES) {
        strcpy(expense_tracker->expenses[expense_tracker->num_expenses].description, description);
        expense_tracker->expenses[expense_tracker->num_expenses].amount = amount;
        expense_tracker->expenses[expense_tracker->num_expenses].date = date;
        expense_tracker->num_expenses++;
    } else {
        printf("Error: The expense tracker is full.\n");
    }
}

// Print the expenses in the expense tracker
void print_expenses(expense_tracker_t* expense_tracker) {
    for (int i = 0; i < expense_tracker->num_expenses; i++) {
        printf("%s: $%.2f (%d)\n", expense_tracker->expenses[i].description, expense_tracker->expenses[i].amount, expense_tracker->expenses[i].date);
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
    add_expense(expense_tracker, "Groceries", 100.00, 20230301);
    add_expense(expense_tracker, "Gas", 50.00, 20230302);
    add_expense(expense_tracker, "Entertainment", 25.00, 20230303);

    // Print the expenses in the expense tracker
    print_expenses(expense_tracker);

    // Free the memory allocated for the expense tracker
    free_expense_tracker(expense_tracker);

    return 0;
}