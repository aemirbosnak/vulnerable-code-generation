//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
#define INCOME 1
#define EXPENSE 2

// Define the transaction categories
#define CATEGORY_FOOD 1
#define CATEGORY_RENT 2
#define CATEGORY_UTILITIES 3
#define CATEGORY_ENTERTAINMENT 4
#define CATEGORY_OTHER 5

// Define the transaction struct
typedef struct {
    int type;
    int category;
    double amount;
    char* description;
} transaction_t;

// Define the personal finance planner struct
typedef struct {
    double income;
    double expenses;
    double balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    planner->income = 0.0;
    planner->expenses = 0.0;
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, transaction_t transaction) {
    if (planner->num_transactions < MAX_TRANSACTIONS) {
        planner->transactions[planner->num_transactions] = transaction;
        planner->num_transactions++;
        if (transaction.type == INCOME) {
            planner->income += transaction.amount;
        } else if (transaction.type == EXPENSE) {
            planner->expenses += transaction.amount;
        }
        planner->balance = planner->income - planner->expenses;
    } else {
        printf("Error: Maximum number of transactions reached.\n");
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
    printf("Income: $%.2f\n", planner->income);
    printf("Expenses: $%.2f\n", planner->expenses);
    printf("Balance: $%.2f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        transaction_t transaction = planner->transactions[i];
        printf("  - %s: $%.2f\n", transaction.description, transaction.amount);
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].description);
    }
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner();

    // Add some transactions to the planner
    transaction_t transaction1 = { INCOME, CATEGORY_FOOD, 100.0, "Groceries" };
    add_transaction(planner, transaction1);
    transaction_t transaction2 = { EXPENSE, CATEGORY_RENT, 1200.0, "Rent" };
    add_transaction(planner, transaction2);
    transaction_t transaction3 = { EXPENSE, CATEGORY_UTILITIES, 150.0, "Utilities" };
    add_transaction(planner, transaction3);
    transaction_t transaction4 = { EXPENSE, CATEGORY_ENTERTAINMENT, 50.0, "Movie tickets" };
    add_transaction(planner, transaction4);
    transaction_t transaction5 = { INCOME, CATEGORY_OTHER, 200.0, "Freelance income" };
    add_transaction(planner, transaction5);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}