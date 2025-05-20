//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
#define EXPENSE 0
#define INCOME 1

// Define the transaction categories
#define FOOD 0
#define HOUSING 1
#define TRANSPORTATION 2
#define ENTERTAINMENT 3
#define OTHER 4

// Define the transaction structure
typedef struct {
    int type;
    int category;
    float amount;
    char *description;
} Transaction;

// Create a new transaction
Transaction* create_transaction(int type, int category, float amount, char *description) {
    Transaction *transaction = malloc(sizeof(Transaction));
    transaction->type = type;
    transaction->category = category;
    transaction->amount = amount;
    transaction->description = strdup(description);
    return transaction;
}

// Free a transaction
void free_transaction(Transaction *transaction) {
    free(transaction->description);
    free(transaction);
}

// Add a transaction to the list of transactions
void add_transaction(Transaction **transactions, int *num_transactions, Transaction *transaction) {
    if (*num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Too many transactions.\n");
        return;
    }
    transactions[*num_transactions] = transaction;
    (*num_transactions)++;
}

// Print the list of transactions
void print_transactions(Transaction **transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        Transaction *transaction = transactions[i];
        printf("%s\t%s\t%.2f\t%s\n",
            transaction->type == EXPENSE ? "Expense" : "Income",
            transaction->category == FOOD ? "Food" :
            transaction->category == HOUSING ? "Housing" :
            transaction->category == TRANSPORTATION ? "Transportation" :
            transaction->category == ENTERTAINMENT ? "Entertainment" : "Other",
            transaction->amount,
            transaction->description);
    }
}

// Calculate the total expenses
float calculate_total_expenses(Transaction **transactions, int num_transactions) {
    float total_expenses = 0;
    for (int i = 0; i < num_transactions; i++) {
        Transaction *transaction = transactions[i];
        if (transaction->type == EXPENSE) {
            total_expenses += transaction->amount;
        }
    }
    return total_expenses;
}

// Calculate the total income
float calculate_total_income(Transaction **transactions, int num_transactions) {
    float total_income = 0;
    for (int i = 0; i < num_transactions; i++) {
        Transaction *transaction = transactions[i];
        if (transaction->type == INCOME) {
            total_income += transaction->amount;
        }
    }
    return total_income;
}

// Calculate the net worth
float calculate_net_worth(Transaction **transactions, int num_transactions) {
    float total_expenses = calculate_total_expenses(transactions, num_transactions);
    float total_income = calculate_total_income(transactions, num_transactions);
    return total_income - total_expenses;
}

// Main function
int main() {
    // Create an array of transactions
    Transaction *transactions[MAX_TRANSACTIONS];

    // Initialize the number of transactions to 0
    int num_transactions = 0;

    // Add some transactions to the array
    add_transaction(transactions, &num_transactions, create_transaction(EXPENSE, FOOD, 100, "Groceries"));
    add_transaction(transactions, &num_transactions, create_transaction(EXPENSE, HOUSING, 500, "Rent"));
    add_transaction(transactions, &num_transactions, create_transaction(EXPENSE, TRANSPORTATION, 200, "Gas"));
    add_transaction(transactions, &num_transactions, create_transaction(EXPENSE, ENTERTAINMENT, 100, "Movie tickets"));
    add_transaction(transactions, &num_transactions, create_transaction(INCOME, OTHER, 1000, "Salary"));

    // Print the list of transactions
    printf("Transactions:\n");
    print_transactions(transactions, num_transactions);

    // Calculate the total expenses
    float total_expenses = calculate_total_expenses(transactions, num_transactions);

    // Calculate the total income
    float total_income = calculate_total_income(transactions, num_transactions);

    // Calculate the net worth
    float net_worth = calculate_net_worth(transactions, num_transactions);

    // Print the financial summary
    printf("\nFinancial Summary:\n");
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Total Income: %.2f\n", total_income);
    printf("Net Worth: %.2f\n", net_worth);

    // Free the transactions
    for (int i = 0; i < num_transactions; i++) {
        free_transaction(transactions[i]);
    }

    return 0;
}