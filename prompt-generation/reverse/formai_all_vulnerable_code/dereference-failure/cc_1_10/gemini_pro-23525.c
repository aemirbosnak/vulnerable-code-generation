//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: portable
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
    char name[50];
    double balance;
    int num_transactions;
    transaction transactions[MAX_TRANSACTIONS];
} personal_finance_planner;

// Function to create a new personal finance planner
personal_finance_planner *create_planner(char *name) {
    personal_finance_planner *planner = malloc(sizeof(personal_finance_planner));
    strcpy(planner->name, name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Function to add a transaction to a personal finance planner
void add_transaction(personal_finance_planner *planner, transaction *transaction) {
    planner->transactions[planner->num_transactions] = *transaction;
    planner->num_transactions++;
    if (transaction->type == 'I') {
        planner->balance += transaction->amount;
    } else if (transaction->type == 'E') {
        planner->balance -= transaction->amount;
    }
}

// Function to print the transactions of a personal finance planner
void print_transactions(personal_finance_planner *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s\t%.2f\t%c\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Function to free the memory allocated to a personal finance planner
void free_planner(personal_finance_planner *planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner *planner = create_planner("John Doe");

    // Add some transactions to the planner
    transaction transaction1 = {"Salary", 1000.0, 'I'};
    add_transaction(planner, &transaction1);
    transaction transaction2 = {"Rent", -500.0, 'E'};
    add_transaction(planner, &transaction2);
    transaction transaction3 = {"Groceries", -100.0, 'E'};
    add_transaction(planner, &transaction3);

    // Print the transactions
    print_transactions(planner);

    // Free the memory allocated to the planner
    free_planner(planner);

    return 0;
}