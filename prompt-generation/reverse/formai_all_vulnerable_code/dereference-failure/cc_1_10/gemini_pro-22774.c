//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct transaction {
    char* date;
    char* description;
    double amount;
} transaction_t;

// Define the structure of a personal finance planner
typedef struct personal_finance_planner {
    char* name;
    double balance;
    int num_transactions;
    transaction_t transactions[MAX_TRANSACTIONS];
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner(char* name) {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    planner->name = strdup(name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a new transaction to a personal finance planner
void add_transaction(personal_finance_planner_t* planner, char* date, char* description, double amount) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    transaction_t* transaction = &planner->transactions[planner->num_transactions++];
    transaction->date = strdup(date);
    transaction->description = strdup(description);
    transaction->amount = amount;

    planner->balance += amount;
}

// Print the transactions of a personal finance planner
void print_transactions(personal_finance_planner_t* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        transaction_t* transaction = &planner->transactions[i];
        printf("%s\t%s\t%f\n", transaction->date, transaction->description, transaction->amount);
    }
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].date);
        free(planner->transactions[i].description);
    }
    free(planner->name);
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner("John Doe");

    // Add some transactions to the planner
    add_transaction(planner, "2023-01-01", "Salary", 2000.00);
    add_transaction(planner, "2023-01-05", "Rent", -1000.00);
    add_transaction(planner, "2023-01-10", "Groceries", -200.00);
    add_transaction(planner, "2023-01-15", "Gas", -50.00);

    // Print the transactions
    print_transactions(planner);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}