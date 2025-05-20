//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the maximum length of a transaction description
#define MAX_DESCRIPTION_LENGTH 50

// Define the structure of a transaction
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    int type; // 1 for income, -1 for expense
} transaction;

// Define the structure of the personal finance planner
typedef struct {
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double balance;
} personal_finance_planner;

// Function to create a new personal finance planner
personal_finance_planner* create_personal_finance_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->num_transactions = 0;
    planner->balance = 0.0;
    return planner;
}

// Function to add a transaction to a personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
    planner->transactions[planner->num_transactions++] = *transaction;
    planner->balance += transaction->amount * transaction->type;
}

// Function to print the transactions in a personal finance planner
void print_transactions(personal_finance_planner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Function to print the balance of a personal finance planner
void print_balance(personal_finance_planner* planner) {
    printf("Balance: $%.2f\n", planner->balance);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    transaction transaction1 = {"Salary", 1000.0, 1};
    transaction transaction2 = {"Rent", -500.0, -1};
    transaction transaction3 = {"Groceries", -100.0, -1};
    transaction transaction4 = {"Savings", 200.0, 1};
    add_transaction(planner, &transaction1);
    add_transaction(planner, &transaction2);
    add_transaction(planner, &transaction3);
    add_transaction(planner, &transaction4);

    // Print the transactions
    print_transactions(planner);

    // Print the balance
    print_balance(planner);

    // Free the memory allocated for the planner
    free(planner);

    return 0;
}