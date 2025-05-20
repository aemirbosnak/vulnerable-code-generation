//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
typedef enum {
    INCOME,
    EXPENSE
} transaction_type;

// Define the transaction struct
typedef struct {
    char *description;
    double amount;
    transaction_type type;
} transaction;

// Create a new transaction
transaction *new_transaction(char *description, double amount, transaction_type type) {
    transaction *t = malloc(sizeof(transaction));
    t->description = strdup(description);
    t->amount = amount;
    t->type = type;
    return t;
}

// Free a transaction
void free_transaction(transaction *t) {
    free(t->description);
    free(t);
}

// Add a transaction to the list of transactions
void add_transaction(transaction **transactions, int *num_transactions, transaction *t) {
    transactions[*num_transactions] = t;
    (*num_transactions)++;
}

// Print the list of transactions
void print_transactions(transaction **transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f\n", transactions[i]->description, transactions[i]->amount);
    }
}

// Calculate the total income and expenses
void calculate_totals(transaction **transactions, int num_transactions, double *total_income, double *total_expenses) {
    *total_income = 0;
    *total_expenses = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i]->type == INCOME) {
            *total_income += transactions[i]->amount;
        } else {
            *total_expenses += transactions[i]->amount;
        }
    }
}

// Print the totals
void print_totals(double total_income, double total_expenses) {
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
}

// Main function
int main() {
    // Create an array of transactions
    transaction *transactions[MAX_TRANSACTIONS];

    // Initialize the number of transactions to 0
    int num_transactions = 0;

    // Add some sample transactions
    add_transaction(transactions, &num_transactions, new_transaction("Salary", 2000, INCOME));
    add_transaction(transactions, &num_transactions, new_transaction("Rent", 1000, EXPENSE));
    add_transaction(transactions, &num_transactions, new_transaction("Groceries", 200, EXPENSE));
    add_transaction(transactions, &num_transactions, new_transaction("Utilities", 150, EXPENSE));
    add_transaction(transactions, &num_transactions, new_transaction("Entertainment", 100, EXPENSE));

    // Print the list of transactions
    printf("Transactions:\n");
    print_transactions(transactions, num_transactions);

    // Calculate the total income and expenses
    double total_income, total_expenses;
    calculate_totals(transactions, num_transactions, &total_income, &total_expenses);

    // Print the totals
    printf("\nTotals:\n");
    print_totals(total_income, total_expenses);

    // Free the transactions
    for (int i = 0; i < num_transactions; i++) {
        free_transaction(transactions[i]);
    }

    return 0;
}