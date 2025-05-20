//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    double amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

// Define the structure of the personal finance planner
typedef struct {
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double balance;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_personal_finance_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->num_transactions = 0;
    planner->balance = 0.0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction t) {
    planner->transactions[planner->num_transactions] = t;
    planner->num_transactions++;
    if (t.type == 'I') {
        planner->balance += t.amount;
    } else if (t.type == 'E') {
        planner->balance -= t.amount;
    }
}

// Print the transactions in the personal finance planner
void print_transactions(personal_finance_planner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Print the balance of the personal finance planner
void print_balance(personal_finance_planner* planner) {
    printf("Balance: $%.2f\n", planner->balance);
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    transaction t1 = {"Salary", 2000.0, 'I'};
    transaction t2 = {"Rent", 1000.0, 'E'};
    transaction t3 = {"Groceries", 200.0, 'E'};
    transaction t4 = {"Savings", 500.0, 'I'};
    transaction t5 = {"Entertainment", 100.0, 'E'};

    add_transaction(planner, t1);
    add_transaction(planner, t2);
    add_transaction(planner, t3);
    add_transaction(planner, t4);
    add_transaction(planner, t5);

    // Print the transactions
    print_transactions(planner);

    // Print the balance
    print_balance(planner);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}