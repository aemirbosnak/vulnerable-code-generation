//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *description;
    float amount;
    char *date;
    char *category;
} Expense;

typedef struct {
    int num_expenses;
    Expense **expenses;
} ExpenseTracker;

ExpenseTracker *create_expense_tracker() {
    ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
    tracker->num_expenses = 0;
    tracker->expenses = NULL;
    return tracker;
}

void add_expense(ExpenseTracker *tracker, char *description, float amount, char *date, char *category) {
    tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(Expense *));
    tracker->expenses[tracker->num_expenses] = malloc(sizeof(Expense));
    tracker->expenses[tracker->num_expenses]->description = malloc(strlen(description) + 1);
    strcpy(tracker->expenses[tracker->num_expenses]->description, description);
    tracker->expenses[tracker->num_expenses]->amount = amount;
    tracker->expenses[tracker->num_expenses]->date = malloc(strlen(date) + 1);
    strcpy(tracker->expenses[tracker->num_expenses]->date, date);
    tracker->expenses[tracker->num_expenses]->category = malloc(strlen(category) + 1);
    strcpy(tracker->expenses[tracker->num_expenses]->category, category);
    tracker->num_expenses++;
}

void print_expense_tracker(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: %f, %s, %s\n", tracker->expenses[i]->description, tracker->expenses[i]->amount, tracker->expenses[i]->date, tracker->expenses[i]->category);
    }
}

int main() {
    ExpenseTracker *tracker = create_expense_tracker();
    add_expense(tracker, "Groceries", 100.00, "2023-02-01", "Food");
    add_expense(tracker, "Gas", 50.00, "2023-02-02", "Transportation");
    add_expense(tracker, "Rent", 1200.00, "2023-02-03", "Housing");
    add_expense(tracker, "Utilities", 200.00, "2023-02-04", "Utilities");
    add_expense(tracker, "Entertainment", 50.00, "2023-02-05", "Entertainment");
    print_expense_tracker(tracker);
    return 0;
}