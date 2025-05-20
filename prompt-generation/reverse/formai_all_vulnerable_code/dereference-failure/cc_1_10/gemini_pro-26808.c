//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char *description;
    double amount;
    char *category;
    char *date;
} Expense;

// Define the structure of the expense tracker
typedef struct {
    Expense expenses[MAX_EXPENSES];
    int num_expenses;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *new_expense_tracker() {
    ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the tracker
void add_expense(ExpenseTracker *tracker, Expense expense) {
    if (tracker->num_expenses < MAX_EXPENSES) {
        tracker->expenses[tracker->num_expenses] = expense;
        tracker->num_expenses++;
    }
}

// Print the expenses in the tracker
void print_expenses(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: $%.2f (%s - %s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].category, tracker->expenses[i].date);
    }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        free(tracker->expenses[i].description);
        free(tracker->expenses[i].category);
        free(tracker->expenses[i].date);
    }
    free(tracker);
}

// Main function
int main() {
    // Create a new expense tracker
    ExpenseTracker *tracker = new_expense_tracker();

    // Add some expenses to the tracker
    Expense expense1 = {"Groceries", 100.00, "Food", "2023-01-01"};
    add_expense(tracker, expense1);
    Expense expense2 = {"Rent", 1200.00, "Housing", "2023-01-05"};
    add_expense(tracker, expense2);
    Expense expense3 = {"Car payment", 500.00, "Transportation", "2023-01-10"};
    add_expense(tracker, expense3);

    // Print the expenses in the tracker
    print_expenses(tracker);

    // Free the memory allocated for the expense tracker
    free_expense_tracker(tracker);

    return 0;
}