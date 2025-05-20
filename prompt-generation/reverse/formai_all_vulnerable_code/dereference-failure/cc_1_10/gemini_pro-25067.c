//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: genius
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

// Define the structure of a personal finance planner
typedef struct {
    char name[50];
    double balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_personal_finance_planner(char* name) {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    strcpy(planner->name, name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
    if (planner->num_transactions < MAX_TRANSACTIONS) {
        planner->transactions[planner->num_transactions] = *transaction;
        planner->num_transactions++;
        if (transaction->type == 'I') {
            planner->balance += transaction->amount;
        } else if (transaction->type == 'E') {
            planner->balance -= transaction->amount;
        }
    }
}

// Print the transactions of a personal finance planner
void print_transactions(personal_finance_planner* planner) {
    printf("Transactions for %s:\n", planner->name);
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("%s\t%f\t%c\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
    }
}

// Get the balance of a personal finance planner
double get_balance(personal_finance_planner* planner) {
    return planner->balance;
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_personal_finance_planner("John Doe");

    // Add some transactions to the planner
    transaction transaction1 = {"Salary", 2000.0, 'I'};
    add_transaction(planner, &transaction1);
    transaction transaction2 = {"Rent", 1000.0, 'E'};
    add_transaction(planner, &transaction2);
    transaction transaction3 = {"Groceries", 200.0, 'E'};
    add_transaction(planner, &transaction3);

    // Print the transactions of the planner
    print_transactions(planner);

    // Get the balance of the planner
    double balance = get_balance(planner);
    printf("Balance: %f\n", balance);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}