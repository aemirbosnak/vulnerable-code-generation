//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct transaction {
    char *description;
    double amount;
    int type; // 1 for income, -1 for expense
} transaction_t;

// Define the structure of a personal finance planner
typedef struct personal_finance_planner {
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double balance;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
    personal_finance_planner_t *planner = malloc(sizeof(personal_finance_planner_t));
    planner->num_transactions = 0;
    planner->balance = 0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner_t *planner, char *description, double amount, int type) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Too many transactions. Cannot add new transaction.\n");
        return;
    }

    transaction_t *transaction = &planner->transactions[planner->num_transactions];
    transaction->description = strdup(description);
    transaction->amount = amount;
    transaction->type = type;
    planner->num_transactions++;
    planner->balance += amount * type;
}

// Print the transactions in a personal finance planner
void print_transactions(personal_finance_planner_t *planner) {
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        transaction_t *transaction = &planner->transactions[i];
        printf("  %s: $%.2f\n", transaction->description, transaction->amount);
    }
}

// Print the balance in a personal finance planner
void print_balance(personal_finance_planner_t *planner) {
    printf("Balance: $%.2f\n", planner->balance);
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner_t *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].description);
    }
    free(planner);
}

int main() {
    // Create a new personal finance planner
    personal_finance_planner_t *planner = create_personal_finance_planner();

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 2000, 1);
    add_transaction(planner, "Rent", -1000, -1);
    add_transaction(planner, "Groceries", -200, -1);
    add_transaction(planner, "Entertainment", -100, -1);

    // Print the transactions
    print_transactions(planner);

    // Print the balance
    print_balance(planner);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}