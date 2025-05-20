//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions that can be stored
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    double amount;
    int type; // 0 for expense, 1 for income
} transaction_t;

// Define the structure of the personal finance planner
typedef struct {
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double balance;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    planner->num_transactions = 0;
    planner->balance = 0.0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, transaction_t transaction) {
    if (planner->num_transactions < MAX_TRANSACTIONS) {
        planner->transactions[planner->num_transactions++] = transaction;
        planner->balance += transaction.type ? transaction.amount : -transaction.amount;
    } else {
        printf("Error: Too many transactions. Maximum number of transactions is %d.\n", MAX_TRANSACTIONS);
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
    printf("Personal Finance Planner:\n");
    printf("  Number of transactions: %d\n", planner->num_transactions);
    printf("  Balance: %.2f\n", planner->balance);
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  Transaction %d:\n", i + 1);
        printf("    Description: %s\n", planner->transactions[i].description);
        printf("    Amount: %.2f\n", planner->transactions[i].amount);
        printf("    Type: %s\n", planner->transactions[i].type ? "Income" : "Expense");
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner();

    // Add some sample transactions to the personal finance planner
    transaction_t transaction1 = {"Salary", 1000.0, 1};
    add_transaction(planner, transaction1);
    transaction_t transaction2 = {"Groceries", -100.0, 0};
    add_transaction(planner, transaction2);
    transaction_t transaction3 = {"Rent", -500.0, 0};
    add_transaction(planner, transaction3);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}