//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the struct for a transaction
typedef struct {
    char description[50];
    double amount;
    char type[10]; // Income or Expense
} transaction;

// Define the struct for the personal finance planner
typedef struct {
    double income;
    double expenses;
    double balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_planner() {
    personal_finance_planner* planner = (personal_finance_planner*)malloc(sizeof(personal_finance_planner));
    planner->income = 0;
    planner->expenses = 0;
    planner->balance = 0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction t) {
    // Check if the planner is full
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: The personal finance planner is full.\n");
        return;
    }

    // Add the transaction to the planner
    planner->transactions[planner->num_transactions] = t;
    planner->num_transactions++;

    // Update the planner's balance
    if (strcmp(t.type, "Income") == 0) {
        planner->income += t.amount;
        planner->balance += t.amount;
    } else if (strcmp(t.type, "Expense") == 0) {
        planner->expenses += t.amount;
        planner->balance -= t.amount;
    } else {
        printf("Error: Invalid transaction type.\n");
    }
}

// Print the personal finance planner
void print_planner(personal_finance_planner* planner) {
    printf("Personal Finance Planner\n");
    printf("Income: $%.2f\n", planner->income);
    printf("Expenses: $%.2f\n", planner->expenses);
    printf("Balance: $%.2f\n", planner->balance);
    printf("\nTransactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s\t$%.2f\t%s\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Free the memory allocated for the personal finance planner
void free_planner(personal_finance_planner* planner) {
    free(planner);
}

int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_planner();

    // Add some transactions to the planner
    transaction t1 = {"Salary", 2000, "Income"};
    add_transaction(planner, t1);
    transaction t2 = {"Rent", 1000, "Expense"};
    add_transaction(planner, t2);
    transaction t3 = {"Groceries", 200, "Expense"};
    add_transaction(planner, t3);
    transaction t4 = {"Entertainment", 100, "Expense"};
    add_transaction(planner, t4);
    transaction t5 = {"Savings", 500, "Income"};
    add_transaction(planner, t5);

    // Print the personal finance planner
    print_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_planner(planner);

    return 0;
}