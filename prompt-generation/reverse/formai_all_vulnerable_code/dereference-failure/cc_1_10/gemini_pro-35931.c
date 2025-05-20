//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    double amount;
    int type; // 1 for income, -1 for expense
} transaction_t;

// Define the structure of a personal finance planner
typedef struct {
    char name[50];
    double balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner(char* name) {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    strcpy(planner->name, name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner_t* planner, transaction_t* transaction) {
    planner->transactions[planner->num_transactions] = *transaction;
    planner->num_transactions++;
    planner->balance += transaction->amount * transaction->type;
}

// Print the transactions of a personal finance planner
void print_transactions(personal_finance_planner_t* planner) {
    printf("Transactions for %s:\n", planner->name);
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Print the balance of a personal finance planner
void print_balance(personal_finance_planner_t* planner) {
    printf("Balance: $%.2f\n", planner->balance);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner("John Doe");

    // Add some transactions to the planner
    transaction_t transaction1 = {"Salary", 2000.0, 1};
    add_transaction(planner, &transaction1);
    transaction_t transaction2 = {"Rent", -1000.0, -1};
    add_transaction(planner, &transaction2);
    transaction_t transaction3 = {"Groceries", -200.0, -1};
    add_transaction(planner, &transaction3);

    // Print the transactions
    print_transactions(planner);

    // Print the balance
    print_balance(planner);

    return 0;
}