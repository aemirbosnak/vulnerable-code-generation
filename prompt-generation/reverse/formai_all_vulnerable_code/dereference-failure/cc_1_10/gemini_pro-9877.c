//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    double amount;
} Expense;

typedef struct {
    Expense* expenses;
    int num_expenses;
} ExpenseTracker;

ExpenseTracker* create_expense_tracker() {
    ExpenseTracker* tracker = malloc(sizeof(ExpenseTracker));
    if (tracker == NULL) {
        return NULL;
    }

    tracker->expenses = NULL;
    tracker->num_expenses = 0;

    return tracker;
}

void add_expense(ExpenseTracker* tracker, char* name, double amount) {
    tracker->expenses = realloc(tracker->expenses, sizeof(Expense) * (tracker->num_expenses + 1));
    if (tracker->expenses == NULL) {
        free(tracker);
        return;
    }

    tracker->expenses[tracker->num_expenses].name = malloc(strlen(name) + 1);
    if (tracker->expenses[tracker->num_expenses].name == NULL) {
        free(tracker->expenses);
        free(tracker);
        return;
    }

    strcpy(tracker->expenses[tracker->num_expenses].name, name);
    tracker->expenses[tracker->num_expenses].amount = amount;

    tracker->num_expenses++;
}

void print_expenses(ExpenseTracker* tracker) {
    printf("Expenses:\n");
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

void free_expense_tracker(ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        free(tracker->expenses[i].name);
    }

    free(tracker->expenses);
    free(tracker);
}

int main() {
    // Create an expense tracker
    ExpenseTracker* tracker = create_expense_tracker();

    // Add some expenses
    add_expense(tracker, "Food", 100.0);
    add_expense(tracker, "Entertainment", 50.0);
    add_expense(tracker, "Transportation", 200.0);

    // Print the expenses
    print_expenses(tracker);

    // Free the expense tracker
    free_expense_tracker(tracker);

    return 0;
}