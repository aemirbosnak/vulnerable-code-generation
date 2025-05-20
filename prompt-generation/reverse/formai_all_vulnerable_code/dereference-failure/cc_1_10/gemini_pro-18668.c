//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char *description;
    float amount;
    struct Expense *next;
};

struct ExpenseTracker {
    struct Expense *head;
    int num_expenses;
};

void add_expense(struct ExpenseTracker *tracker, char *description, float amount) {
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = tracker->head;
    tracker->head = new_expense;
    tracker->num_expenses++;
}

void print_expenses(struct ExpenseTracker *tracker) {
    struct Expense *current_expense = tracker->head;
    while (current_expense != NULL) {
        printf("%s: $%.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

void free_expense_tracker(struct ExpenseTracker *tracker) {
    struct Expense *current_expense = tracker->head;
    while (current_expense != NULL) {
        struct Expense *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

int main() {
    struct ExpenseTracker tracker;
    tracker.head = NULL;
    tracker.num_expenses = 0;

    add_expense(&tracker, "Groceries", 100.00);
    add_expense(&tracker, "Gas", 50.00);
    add_expense(&tracker, "Rent", 1200.00);
    add_expense(&tracker, "Utilities", 200.00);
    add_expense(&tracker, "Entertainment", 100.00);

    print_expenses(&tracker);

    free_expense_tracker(&tracker);

    return 0;
}