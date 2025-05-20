//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *description;
    float amount;
};

struct expense_tracker {
    struct expense *expenses;  // Array of expenses
    int num_expenses;          // Number of expenses
};

// Create a new expense tracker
struct expense_tracker *create_expense_tracker() {
    struct expense_tracker *tracker = (struct expense_tracker *)malloc(sizeof(struct expense_tracker));
    tracker->expenses = NULL;
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the tracker
void add_expense(struct expense_tracker *tracker, char *description, float amount) {
    struct expense *new_expense = (struct expense *)malloc(sizeof(struct expense));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    tracker->expenses = (struct expense *)realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(struct expense));
    tracker->expenses[tracker->num_expenses++] = *new_expense;
    free(new_expense);
}

// Print the expenses in the tracker
void print_expenses(struct expense_tracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

// Get the total amount of expenses
float get_total_expenses(struct expense_tracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

// Free the memory used by the tracker
void free_expense_tracker(struct expense_tracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        free(tracker->expenses[i].description);
    }
    free(tracker->expenses);
    free(tracker);
}

int main() {
    // Create a new expense tracker
    struct expense_tracker *tracker = create_expense_tracker();

    // Add some expenses to the tracker
    add_expense(tracker, "Groceries", 50.00);
    add_expense(tracker, "Gas", 25.00);
    add_expense(tracker, "Entertainment", 10.00);

    // Print the expenses in the tracker
    print_expenses(tracker);

    // Get the total amount of expenses
    float total = get_total_expenses(tracker);
    printf("Total expenses: $%.2f\n", total);

    // Free the memory used by the tracker
    free_expense_tracker(tracker);

    return 0;
}