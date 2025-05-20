//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[100];
    float amount;
    time_t date;
} Expense;

// Define the structure of the expense tracker
typedef struct {
    Expense expenses[MAX_EXPENSES];
    int numExpenses;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker* createExpenseTracker() {
    ExpenseTracker* tracker = malloc(sizeof(ExpenseTracker));
    tracker->numExpenses = 0;
    return tracker;
}

// Add an expense to the tracker
void addExpense(ExpenseTracker* tracker, char* description, float amount) {
    // Check if the tracker is full
    if (tracker->numExpenses >= MAX_EXPENSES) {
        printf("Error: The expense tracker is full.\n");
        return;
    }

    // Create a new expense
    Expense expense;
    strcpy(expense.description, description);
    expense.amount = amount;
    time(&expense.date);

    // Add the expense to the tracker
    tracker->expenses[tracker->numExpenses++] = expense;
}

// Print the expenses in the tracker
void printExpenses(ExpenseTracker* tracker) {
    // Loop through the expenses
    for (int i = 0; i < tracker->numExpenses; i++) {
        Expense expense = tracker->expenses[i];

        // Print the expense
        printf("%s: $%.2f (%s)\n", 
            expense.description, 
            expense.amount, 
            ctime(&expense.date));
    }
}

// Get the total amount of expenses in the tracker
float getTotalExpenses(ExpenseTracker* tracker) {
    // Initialize the total to 0
    float total = 0;

    // Loop through the expenses
    for (int i = 0; i < tracker->numExpenses; i++) {
        Expense expense = tracker->expenses[i];

        // Add the expense amount to the total
        total += expense.amount;
    }

    // Return the total
    return total;
}

// Free the memory allocated to the expense tracker
void freeExpenseTracker(ExpenseTracker* tracker) {
    free(tracker);
}

// Test the expense tracker
int main() {
    // Create an expense tracker
    ExpenseTracker* tracker = createExpenseTracker();

    // Add some expenses to the tracker
    addExpense(tracker, "Groceries", 100.00);
    addExpense(tracker, "Rent", 1200.00);
    addExpense(tracker, "Utilities", 200.00);
    addExpense(tracker, "Entertainment", 100.00);

    // Print the expenses in the tracker
    printExpenses(tracker);

    // Get the total amount of expenses in the tracker
    float total = getTotalExpenses(tracker);

    // Print the total
    printf("Total expenses: $%.2f\n", total);

    // Free the memory allocated to the expense tracker
    freeExpenseTracker(tracker);

    return 0;
}