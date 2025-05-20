//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 1000

// Define the structure of a transaction
typedef struct {
    char *description;
    double amount;
    time_t date;
} Transaction;

// Define the structure of a personal finance planner
typedef struct {
    char *name;
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} PersonalFinancePlanner;

// Create a new personal finance planner
PersonalFinancePlanner *create_personal_finance_planner(char *name) {
    PersonalFinancePlanner *planner = malloc(sizeof(PersonalFinancePlanner));
    planner->name = strdup(name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(PersonalFinancePlanner *planner, char *description, double amount, time_t date) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached\n");
        return;
    }

    Transaction transaction;
    transaction.description = strdup(description);
    transaction.amount = amount;
    transaction.date = date;

    planner->transactions[planner->num_transactions++] = transaction;
}

// Print the transactions of a personal finance planner
void print_transactions(PersonalFinancePlanner *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        Transaction transaction = planner->transactions[i];
        printf("%s: %.2f - %s\n", ctime(&transaction.date), transaction.amount, transaction.description);
    }
}

// Free the memory used by a personal finance planner
void free_personal_finance_planner(PersonalFinancePlanner *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].description);
    }
    free(planner->name);
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    PersonalFinancePlanner *planner = create_personal_finance_planner("John Doe");

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 1000.0, time(NULL));
    add_transaction(planner, "Rent", -500.0, time(NULL));
    add_transaction(planner, "Groceries", -100.0, time(NULL));
    add_transaction(planner, "Savings", 200.0, time(NULL));

    // Print the transactions in the planner
    print_transactions(planner);

    // Free the memory used by the planner
    free_personal_finance_planner(planner);

    return 0;
}