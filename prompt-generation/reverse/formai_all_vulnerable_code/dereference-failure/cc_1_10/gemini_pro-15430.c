//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];  // Description of the transaction
    double amount;         // Amount of the transaction
    char type;            // Type of the transaction (I for income, E for expense)
} transaction;

// Define the structure of the personal finance planner
typedef struct {
    transaction transactions[MAX_TRANSACTIONS];  // Array of transactions
    int num_transactions;                     // Number of transactions
    double balance;                           // Current balance
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->num_transactions = 0;
    planner->balance = 0.0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction t) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }
    planner->transactions[planner->num_transactions] = t;
    planner->num_transactions++;
    if (t.type == 'I') {
        planner->balance += t.amount;
    } else if (t.type == 'E') {
        planner->balance -= t.amount;
    }
}

// Print the personal finance planner
void print_planner(personal_finance_planner* planner) {
    printf("Personal Finance Planner\n");
    printf("------------------------\n");
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s: $%.2f (%c)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
    printf("Balance: $%.2f\n", planner->balance);
}

// Free the memory allocated for the personal finance planner
void free_planner(personal_finance_planner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_planner();

    // Add some transactions to the planner
    transaction t1 = {"Salary", 2000.00, 'I'};
    add_transaction(planner, t1);
    transaction t2 = {"Rent", -1000.00, 'E'};
    add_transaction(planner, t2);
    transaction t3 = {"Groceries", -200.00, 'E'};
    add_transaction(planner, t3);
    transaction t4 = {"Savings", 500.00, 'I'};
    add_transaction(planner, t4);

    // Print the personal finance planner
    print_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_planner(planner);

    return 0;
}