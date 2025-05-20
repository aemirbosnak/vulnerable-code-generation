//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char *description;
    float amount;
    char *category;
    char *date;
} expense;

// Define the structure of the expense tracker
typedef struct expense_tracker {
    expense expenses[MAX_EXPENSES];
    int num_expenses;
} expense_tracker;

// Create a new expense tracker
expense_tracker *new_expense_tracker() {
    expense_tracker *tracker = malloc(sizeof(expense_tracker));
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the expense tracker
void add_expense(expense_tracker *tracker, expense *expense) {
    tracker->expenses[tracker->num_expenses++] = *expense;
}

// Print the expenses in the expense tracker
void print_expenses(expense_tracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: %f (%s) - %s\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].category, tracker->expenses[i].date);
    }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(expense_tracker *tracker) {
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
    expense_tracker *tracker = new_expense_tracker();

    // Add some expenses to the expense tracker
    expense expense1 = {"Groceries", 50.00, "Food", "2023-03-08"};
    add_expense(tracker, &expense1);

    expense expense2 = {"Gas", 25.00, "Transportation", "2023-03-10"};
    add_expense(tracker, &expense2);

    expense expense3 = {"Entertainment", 10.00, "Entertainment", "2023-03-12"};
    add_expense(tracker, &expense3);

    // Print the expenses in the expense tracker
    print_expenses(tracker);

    // Free the memory allocated for the expense tracker
    free_expense_tracker(tracker);

    return 0;
}