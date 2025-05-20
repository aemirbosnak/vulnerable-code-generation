//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A transaction represents a single expense or income
typedef struct {
    char *description;      // A brief description of the transaction
    double amount;           // The amount of the transaction, in dollars
    int date;                // The date of the transaction, in the format YYYYMMDD
    int category;           // The category of the transaction (e.g., "Food", "Transportation", "Entertainment")
} Transaction;

// An expense tracker is a collection of transactions
typedef struct {
    Transaction *transactions;  // An array of transactions
    int num_transactions;      // The number of transactions in the array
    double total_expenses;      // The total amount of expenses in the array
    double total_income;       // The total amount of income in the array
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *new_expense_tracker() {
    ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
    tracker->transactions = malloc(0);
    tracker->num_transactions = 0;
    tracker->total_expenses = 0;
    tracker->total_income = 0;
    return tracker;
}

// Add a new transaction to an expense tracker
void add_transaction(ExpenseTracker *tracker, Transaction transaction) {
    tracker->transactions = realloc(tracker->transactions, (tracker->num_transactions + 1) * sizeof(Transaction));
    tracker->transactions[tracker->num_transactions] = transaction;
    tracker->num_transactions++;

    if (transaction.amount < 0) {
        tracker->total_expenses += transaction.amount;
    } else {
        tracker->total_income += transaction.amount;
    }
}

// Print the transactions in an expense tracker
void print_transactions(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_transactions; i++) {
        Transaction transaction = tracker->transactions[i];
        printf("%s: $%.2f (date: %d, category: %d)\n", transaction.description, transaction.amount, transaction.date, transaction.category);
    }
}

// Calculate the total expenses in an expense tracker
double calculate_total_expenses(ExpenseTracker *tracker) {
    double total_expenses = 0;
    for (int i = 0; i < tracker->num_transactions; i++) {
        Transaction transaction = tracker->transactions[i];
        if (transaction.amount < 0) {
            total_expenses += transaction.amount;
        }
    }
    return total_expenses;
}

// Calculate the total income in an expense tracker
double calculate_total_income(ExpenseTracker *tracker) {
    double total_income = 0;
    for (int i = 0; i < tracker->num_transactions; i++) {
        Transaction transaction = tracker->transactions[i];
        if (transaction.amount > 0) {
            total_income += transaction.amount;
        }
    }
    return total_income;
}

// Get a transaction by its index
Transaction get_transaction_by_index(ExpenseTracker *tracker, int index) {
    return tracker->transactions[index];
}

// Update a transaction
void update_transaction(ExpenseTracker *tracker, int index, Transaction transaction) {
    tracker->transactions[index] = transaction;
}

// Delete a transaction
void delete_transaction(ExpenseTracker *tracker, int index) {
    for (int i = index; i < tracker->num_transactions - 1; i++) {
        tracker->transactions[i] = tracker->transactions[i + 1];
    }
    tracker->num_transactions--;
}

// Free the memory allocated to an expense tracker
void free_expense_tracker(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_transactions; i++) {
        free(tracker->transactions[i].description);
    }
    free(tracker->transactions);
    free(tracker);
}

// Example usage
int main() {
    // Create a new expense tracker
    ExpenseTracker *tracker = new_expense_tracker();

    // Add some transactions to the expense tracker
    Transaction transaction1 = {"Groceries", -50.00, 20230101, 1};
    Transaction transaction2 = {"Movie tickets", -20.00, 20230102, 3};
    Transaction transaction3 = {"Paycheck", 1000.00, 20230105, 0};
    add_transaction(tracker, transaction1);
    add_transaction(tracker, transaction2);
    add_transaction(tracker, transaction3);

    // Print the transactions in the expense tracker
    print_transactions(tracker);

    // Calculate the total expenses and income in the expense tracker
    double total_expenses = calculate_total_expenses(tracker);
    double total_income = calculate_total_income(tracker);

    // Print the total expenses and income
    printf("Total expenses: $%.2f\n", total_expenses);
    printf("Total income: $%.2f\n", total_income);

    // Update one of the transactions
    Transaction transaction4 = {"Gas", -30.00, 20230103, 2};
    update_transaction(tracker, 1, transaction4);

    // Delete one of the transactions
    delete_transaction(tracker, 2);

    // Print the transactions in the expense tracker again
    print_transactions(tracker);

    // Free the memory allocated to the expense tracker
    free_expense_tracker(tracker);

    return 0;
}