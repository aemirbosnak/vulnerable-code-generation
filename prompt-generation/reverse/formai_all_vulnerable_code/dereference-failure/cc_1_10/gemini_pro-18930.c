//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char description[50];
    float amount;
    char date[11];
} expense_t;

// Define the structure of the expense tracker
typedef struct expense_tracker {
    expense_t expenses[MAX_EXPENSES];
    int num_expenses;
} expense_tracker_t;

// Create a new expense tracker
expense_tracker_t *create_expense_tracker() {
    expense_tracker_t *tracker = malloc(sizeof(expense_tracker_t));
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the tracker
void add_expense(expense_tracker_t *tracker, expense_t expense) {
    if (tracker->num_expenses < MAX_EXPENSES) {
        tracker->expenses[tracker->num_expenses] = expense;
        tracker->num_expenses++;
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}

// Get the total amount of expenses
float get_total_expenses(expense_tracker_t *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

// Print the expenses
void print_expenses(expense_tracker_t *tracker) {
    printf("Expenses:\n");
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("  - %s: $%.2f (%s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
}

// Free the memory allocated for the expense tracker
void destroy_expense_tracker(expense_tracker_t *tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create an expense tracker
    expense_tracker_t *tracker = create_expense_tracker();

    // Add some expenses to the tracker
    expense_t expense1 = {"Groceries", 50.00, "2023-01-01"};
    add_expense(tracker, expense1);
    expense_t expense2 = {"Gas", 25.00, "2023-01-05"};
    add_expense(tracker, expense2);
    expense_t expense3 = {"Entertainment", 15.00, "2023-01-10"};
    add_expense(tracker, expense3);

    // Get the total amount of expenses
    float total_expenses = get_total_expenses(tracker);

    // Print the expenses
    print_expenses(tracker);

    // Free the memory allocated for the expense tracker
    destroy_expense_tracker(tracker);

    return 0;
}