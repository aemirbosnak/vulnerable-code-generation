//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
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
    double balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner;

// Function to create a new personal finance planner
personal_finance_planner* create_personal_finance_planner() {
    personal_finance_planner* planner = (personal_finance_planner*)malloc(sizeof(personal_finance_planner));
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Function to add a new transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, const char* description, double amount, char type) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->transactions[planner->num_transactions].type = type;
    planner->num_transactions++;

    if (type == 'I') {
        planner->balance += amount;
    } else if (type == 'E') {
        planner->balance -= amount;
    }
}

// Function to print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
    printf("Personal Finance Planner\n");
    printf("=======================\n");
    printf("Balance: $%.2f\n", planner->balance);
    printf("\nTransactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  - %s: $%.2f (%c)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Function to destroy the personal finance planner
void destroy_personal_finance_planner(personal_finance_planner* planner) {
    free(planner);
}

int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 2000.0, 'I');
    add_transaction(planner, "Groceries", -100.0, 'E');
    add_transaction(planner, "Rent", -500.0, 'E');
    add_transaction(planner, "Utilities", -150.0, 'E');
    add_transaction(planner, "Savings", 200.0, 'I');

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Destroy the personal finance planner
    destroy_personal_finance_planner(planner);

    return 0;
}