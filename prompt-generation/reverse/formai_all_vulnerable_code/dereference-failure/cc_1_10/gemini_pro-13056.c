//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense structure
typedef struct expense {
    char *description;
    float amount;
    struct expense *next;
} expense;

// Define the expense tracker structure
typedef struct expense_tracker {
    expense *head;
    expense *tail;
    int num_expenses;
} expense_tracker;

// Create a new expense
expense *create_expense(char *description, float amount) {
    expense *new_expense = malloc(sizeof(expense));
    new_expense->description = malloc(strlen(description) + 1);
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

// Add an expense to the tracker
void add_expense(expense_tracker *tracker, expense *new_expense) {
    if (tracker->head == NULL) {
        tracker->head = new_expense;
        tracker->tail = new_expense;
    } else {
        tracker->tail->next = new_expense;
        tracker->tail = new_expense;
    }
    tracker->num_expenses++;
}

// Print the expenses in the tracker
void print_expenses(expense_tracker *tracker) {
    expense *current_expense = tracker->head;
    while (current_expense != NULL) {
        printf("%s: $%.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

// Free the memory allocated for the expenses
void free_expenses(expense_tracker *tracker) {
    expense *current_expense = tracker->head;
    while (current_expense != NULL) {
        expense *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

// Main function
int main() {
    // Create a new expense tracker
    expense_tracker tracker = { NULL, NULL, 0 };

    // Add some expenses to the tracker
    add_expense(&tracker, create_expense("Groceries", 100.00));
    add_expense(&tracker, create_expense("Entertainment", 50.00));
    add_expense(&tracker, create_expense("Transportation", 200.00));

    // Print the expenses in the tracker
    print_expenses(&tracker);

    // Free the memory allocated for the expenses
    free_expenses(&tracker);

    return 0;
}