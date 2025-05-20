//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
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
    float amount;
    int category;
} Transaction;

// Define the structure of a personal finance planner
typedef struct {
    float balance;
    int num_transactions;
    Transaction transactions[MAX_TRANSACTIONS];
} PersonalFinancePlanner;

// Create a new personal finance planner
PersonalFinancePlanner* create_personal_finance_planner() {
    PersonalFinancePlanner* planner = malloc(sizeof(PersonalFinancePlanner));
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Destroy a personal finance planner
void destroy_personal_finance_planner(PersonalFinancePlanner* planner) {
    free(planner);
}

// Add a transaction to a personal finance planner
void add_transaction(PersonalFinancePlanner* planner, Transaction transaction) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
}

// Print the transactions in a personal finance planner
void print_transactions(PersonalFinancePlanner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Get the balance of a personal finance planner
float get_balance(PersonalFinancePlanner* planner) {
    return planner->balance;
}

// Set the balance of a personal finance planner
void set_balance(PersonalFinancePlanner* planner, float balance) {
    planner->balance = balance;
}

// Main function
int main() {
    // Create a new personal finance planner
    PersonalFinancePlanner* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    Transaction transaction1 = {"Groceries", -50.0, 1};
    Transaction transaction2 = {"Gas", -20.0, 2};
    Transaction transaction3 = {"Salary", 1000.0, 3};
    add_transaction(planner, transaction1);
    add_transaction(planner, transaction2);
    add_transaction(planner, transaction3);

    // Print the transactions in the planner
    print_transactions(planner);

    // Get the balance of the planner
    float balance = get_balance(planner);
    printf("Balance: $%.2f\n", balance);

    // Destroy the planner
    destroy_personal_finance_planner(planner);

    return 0;
}