//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the expense structure
typedef struct {
    char *description;
    float amount;
    char *category;
    int month;
    int year;
} expense;

// Define the expense tracker structure
typedef struct {
    expense expenses[MAX_EXPENSES];
    int num_expenses;
} expense_tracker;

// Create a new expense tracker
expense_tracker *new_expense_tracker() {
    expense_tracker *tracker = malloc(sizeof(expense_tracker));
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the tracker
void add_expense(expense_tracker *tracker, expense *ex) {
    tracker->expenses[tracker->num_expenses] = *ex;
    tracker->num_expenses++;
}

// Print the expenses in the tracker
void print_expenses(expense_tracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: $%.2f (%s) [%d/%d]\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].category, tracker->expenses[i].month, tracker->expenses[i].year);
    }
}

// Free the memory allocated for the tracker
void free_expense_tracker(expense_tracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        free(tracker->expenses[i].description);
        free(tracker->expenses[i].category);
    }
    free(tracker);
}

// Main function
int main() {
    // Create a new expense tracker
    expense_tracker *tracker = new_expense_tracker();

    // Add some expenses to the tracker
    expense ex1 = {"Coffee", 3.50, "Food", 1, 2023};
    add_expense(tracker, &ex1);
    expense ex2 = {"Gas", 20.00, "Transportation", 1, 2023};
    add_expense(tracker, &ex2);
    expense ex3 = {"Rent", 1200.00, "Housing", 1, 2023};
    add_expense(tracker, &ex3);

    // Print the expenses in the tracker
    print_expenses(tracker);

    // Free the memory allocated for the tracker
    free_expense_tracker(tracker);

    return 0;
}