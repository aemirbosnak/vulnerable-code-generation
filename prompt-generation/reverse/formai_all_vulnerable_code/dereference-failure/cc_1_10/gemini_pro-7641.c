//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
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

// Define the structure of the personal finance planner
typedef struct {
    float balance;
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

// Function to add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction t) {
    if (planner->num_transactions < MAX_TRANSACTIONS) {
        planner->transactions[planner->num_transactions] = t;
        planner->num_transactions++;
        if (t.type == 'I') {
            planner->balance += t.amount;
        } else if (t.type == 'E') {
            planner->balance -= t.amount;
        }
    } else {
        printf("Error: Cannot add more transactions. Maximum number of transactions reached.\n");
    }
}

// Function to print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
    printf("Balance: $%.2f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: $%.2f (%c)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    transaction t1 = {"Salary", 1000.0, 'I'};
    add_transaction(planner, t1);
    transaction t2 = {"Rent", -500.0, 'E'};
    add_transaction(planner, t2);
    transaction t3 = {"Groceries", -100.0, 'E'};
    add_transaction(planner, t3);
    transaction t4 = {"Entertainment", -50.0, 'E'};
    add_transaction(planner, t4);
    transaction t5 = {"Bonus", 500.0, 'I'};
    add_transaction(planner, t5);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    return 0;
}