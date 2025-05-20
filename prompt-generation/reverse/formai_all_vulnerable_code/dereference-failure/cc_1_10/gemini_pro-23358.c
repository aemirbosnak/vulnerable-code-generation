//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    float amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

// Define the structure of a personal finance planner
typedef struct {
    float balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
    planner->transactions[planner->num_transactions] = *transaction;
    planner->num_transactions++;
    if (transaction->type == 'I') {
        planner->balance += transaction->amount;
    } else if (transaction->type == 'E') {
        planner->balance -= transaction->amount;
    }
}

// Print the transactions in a personal finance planner
void print_transactions(personal_finance_planner* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f (%c)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Print the balance of a personal finance planner
void print_balance(personal_finance_planner* planner) {
    printf("Balance: $%.2f\n", planner->balance);
}

// Free the memory allocated for a personal finance planner
void free_planner(personal_finance_planner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_planner();

    // Add some transactions to the planner
    transaction transaction1 = {"Salary", 2000.0, 'I'};
    add_transaction(planner, &transaction1);
    transaction transaction2 = {"Rent", 1000.0, 'E'};
    add_transaction(planner, &transaction2);
    transaction transaction3 = {"Groceries", 200.0, 'E'};
    add_transaction(planner, &transaction3);
    transaction transaction4 = {"Savings", 500.0, 'I'};
    add_transaction(planner, &transaction4);

    // Print the transactions in the planner
    print_transactions(planner);

    // Print the balance of the planner
    print_balance(planner);

    // Free the memory allocated for the planner
    free_planner(planner);

    return 0;
}