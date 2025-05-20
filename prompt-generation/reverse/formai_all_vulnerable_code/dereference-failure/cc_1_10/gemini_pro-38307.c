//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a transaction
typedef struct transaction {
    char *description;
    double amount;
    int type; // 0 for expense, 1 for income
} transaction;

// Function to create a new transaction
transaction *new_transaction(char *description, double amount, int type) {
    transaction *t = malloc(sizeof(transaction));
    t->description = strdup(description);
    t->amount = amount;
    t->type = type;
    return t;
}

// Function to print a transaction
void print_transaction(transaction *t) {
    printf("%s: $%.2f (%s)\n", t->description, t->amount, t->type == 0 ? "Expense" : "Income");
}

// Function to compare two transactions by date
int compare_transactions(const void *a, const void *b) {
    const transaction *ta = *(const transaction **)a;
    const transaction *tb = *(const transaction **)b;
    return strcmp(ta->description, tb->description);
}

// Main function
int main() {
    // Create an array of transactions
    transaction *transactions[] = {
        new_transaction("Salary", 2000.00, 1),
        new_transaction("Rent", -1200.00, 0),
        new_transaction("Groceries", -200.00, 0),
        new_transaction("Entertainment", -100.00, 0),
        new_transaction("Savings", 200.00, 1),
        new_transaction("Investment", 100.00, 1),
    };

    // Sort the transactions by date
    qsort(transactions, sizeof(transactions) / sizeof(transactions[0]), sizeof(transactions[0]), compare_transactions);

    // Print the transactions
    for (int i = 0; i < sizeof(transactions) / sizeof(transactions[0]); i++) {
        print_transaction(transactions[i]);
    }

    // Free the memory allocated for the transactions
    for (int i = 0; i < sizeof(transactions) / sizeof(transactions[0]); i++) {
        free(transactions[i]->description);
        free(transactions[i]);
    }

    return 0;
}