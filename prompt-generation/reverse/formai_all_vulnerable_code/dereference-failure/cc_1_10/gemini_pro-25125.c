//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char *description;
    float amount;
    char type; // 'I' for income, 'E' for expense
} transaction_t;

// Define the structure of the personal finance planner
typedef struct {
    char *name;
    float starting_balance;
    int num_transactions;
    transaction_t transactions[MAX_TRANSACTIONS];
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t *create_personal_finance_planner(char *name, float starting_balance) {
    personal_finance_planner_t *planner = malloc(sizeof(personal_finance_planner_t));
    planner->name = strdup(name);
    planner->starting_balance = starting_balance;
    planner->num_transactions = 0;
    return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner_t *planner, char *description, float amount, char type) {
    if (planner->num_transactions >= MAX_TRANSACTIONS) {
        fprintf(stderr, "Error: Maximum number of transactions reached\n");
        return;
    }

    transaction_t *transaction = &planner->transactions[planner->num_transactions++];
    transaction->description = strdup(description);
    transaction->amount = amount;
    transaction->type = type;
}

// Calculate the current balance of a personal finance planner
float calculate_balance(personal_finance_planner_t *planner) {
    float balance = planner->starting_balance;
    for (int i = 0; i < planner->num_transactions; i++) {
        transaction_t *transaction = &planner->transactions[i];
        if (transaction->type == 'I') {
            balance += transaction->amount;
        } else if (transaction->type == 'E') {
            balance -= transaction->amount;
        }
    }
    return balance;
}

// Print the transactions of a personal finance planner
void print_transactions(personal_finance_planner_t *planner) {
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        transaction_t *transaction = &planner->transactions[i];
        printf("  %s: $%.2f (%c)\n", transaction->description, transaction->amount, transaction->type);
    }
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner_t *planner) {
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].description);
    }
    free(planner->name);
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t *planner = create_personal_finance_planner("John Doe", 1000.00);

    // Add some transactions to the planner
    add_transaction(planner, "Salary", 2000.00, 'I');
    add_transaction(planner, "Rent", 1000.00, 'E');
    add_transaction(planner, "Groceries", 200.00, 'E');
    add_transaction(planner, "Entertainment", 100.00, 'E');

    // Calculate the current balance of the planner
    float balance = calculate_balance(planner);

    // Print the transactions and balance of the planner
    printf("Name: %s\n", planner->name);
    printf("Starting balance: $%.2f\n", planner->starting_balance);
    print_transactions(planner);
    printf("Current balance: $%.2f\n", balance);

    // Free the memory allocated for the planner
    free_personal_finance_planner(planner);

    return 0;
}