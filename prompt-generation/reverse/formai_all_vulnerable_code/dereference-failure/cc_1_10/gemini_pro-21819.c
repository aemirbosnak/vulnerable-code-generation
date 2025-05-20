//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    float amount;
} Expense;

typedef struct {
    Expense *expenses;
    int num_expenses;
} ExpenseTracker;

// Function prototypes
ExpenseTracker *new_expense_tracker();
void add_expense(ExpenseTracker *tracker, char *name, float amount);
void print_expenses(ExpenseTracker *tracker);
void free_expense_tracker(ExpenseTracker *tracker);

// Main function
int main() {
    // Initialize the expense tracker
    ExpenseTracker *tracker = new_expense_tracker();

    // Add some expenses
    add_expense(tracker, "Food", 100.00);
    add_expense(tracker, "Rent", 500.00);
    add_expense(tracker, "Utilities", 150.00);
    add_expense(tracker, "Entertainment", 50.00);

    // Print the expenses
    print_expenses(tracker);

    // Free the expense tracker
    free_expense_tracker(tracker);

    return 0;
}

// Function definitions
ExpenseTracker *new_expense_tracker() {
    ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
    tracker->expenses = NULL;
    tracker->num_expenses = 0;
    return tracker;
}

void add_expense(ExpenseTracker *tracker, char *name, float amount) {
    // Allocate memory for the new expense
    Expense *expense = malloc(sizeof(Expense));

    // Copy the name and amount into the new expense
    expense->name = malloc(strlen(name) + 1);
    strcpy(expense->name, name);
    expense->amount = amount;

    // Add the new expense to the tracker
    tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(Expense));
    tracker->expenses[tracker->num_expenses++] = *expense;
}

void print_expenses(ExpenseTracker *tracker) {
    printf("Expenses:\n");
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("  %s: $%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

void free_expense_tracker(ExpenseTracker *tracker) {
    // Free the memory allocated for the expenses
    for (int i = 0; i < tracker->num_expenses; i++) {
        free(tracker->expenses[i].name);
    }
    free(tracker->expenses);

    // Free the memory allocated for the tracker
    free(tracker);
}