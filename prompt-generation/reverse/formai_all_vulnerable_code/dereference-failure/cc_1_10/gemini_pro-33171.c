//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Data structures
typedef struct Expense {
    char *description;
    double amount;
    struct Expense *next;
} Expense;

typedef struct ExpenseTracker {
    Expense *head;
    Expense *tail;
    int size;
} ExpenseTracker;

// Function prototypes
ExpenseTracker *new_expense_tracker();
void free_expense_tracker(ExpenseTracker *tracker);
void add_expense(ExpenseTracker *tracker, char *description, double amount);
void print_expense_tracker(ExpenseTracker *tracker);
double calculate_total_expenses(ExpenseTracker *tracker);

// Main function
int main() {
    // Create a new expense tracker
    ExpenseTracker *tracker = new_expense_tracker();

    // Add some expenses to the tracker
    add_expense(tracker, "Groceries", 100.00);
    add_expense(tracker, "Rent", 1200.00);
    add_expense(tracker, "Utilities", 200.00);

    // Print the expense tracker
    print_expense_tracker(tracker);

    // Calculate the total expenses
    double total_expenses = calculate_total_expenses(tracker);
    printf("Total expenses: $%.2f\n", total_expenses);

    // Free the expense tracker
    free_expense_tracker(tracker);

    return 0;
}

// Function definitions

// Creates a new expense tracker
ExpenseTracker *new_expense_tracker() {
    ExpenseTracker *tracker = (ExpenseTracker *)malloc(sizeof(ExpenseTracker));
    tracker->head = NULL;
    tracker->tail = NULL;
    tracker->size = 0;
    return tracker;
}

// Frees the expense tracker and all of its expenses
void free_expense_tracker(ExpenseTracker *tracker) {
    // Free each expense in the tracker
    Expense *current = tracker->head;
    while (current != NULL) {
        Expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }

    // Free the tracker itself
    free(tracker);
}

// Adds an expense to the expense tracker
void add_expense(ExpenseTracker *tracker, char *description, double amount) {
    // Create a new expense
    Expense *expense = (Expense *)malloc(sizeof(Expense));
    expense->description = (char *)malloc(strlen(description) + 1);
    strcpy(expense->description, description);
    expense->amount = amount;
    expense->next = NULL;

    // If the tracker is empty, set the head and tail to the new expense
    if (tracker->size == 0) {
        tracker->head = expense;
        tracker->tail = expense;
    } else {
        // Add the new expense to the end of the list
        tracker->tail->next = expense;
        tracker->tail = expense;
    }

    // Increment the size of the tracker
    tracker->size++;
}

// Prints the expense tracker
void print_expense_tracker(ExpenseTracker *tracker) {
    // Iterate over the expenses in the tracker
    Expense *current = tracker->head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Calculates the total expenses in the expense tracker
double calculate_total_expenses(ExpenseTracker *tracker) {
    // Iterate over the expenses in the tracker and add the amounts
    double total = 0.0;
    Expense *current = tracker->head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }

    return total;
}