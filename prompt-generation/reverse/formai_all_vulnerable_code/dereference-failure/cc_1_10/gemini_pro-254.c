//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a transaction
typedef struct {
    char description[50];
    float amount;
    int type; // 0 for expense, 1 for income
} transaction_t;

// Define the structure of a budget
typedef struct {
    char name[50];
    float amount;
    int num_transactions;
    transaction_t *transactions;
} budget_t;

// Create a new transaction
transaction_t *new_transaction(char *description, float amount, int type) {
    transaction_t *transaction = malloc(sizeof(transaction_t));
    strcpy(transaction->description, description);
    transaction->amount = amount;
    transaction->type = type;
    return transaction;
}

// Create a new budget
budget_t *new_budget(char *name, float amount) {
    budget_t *budget = malloc(sizeof(budget_t));
    strcpy(budget->name, name);
    budget->amount = amount;
    budget->num_transactions = 0;
    budget->transactions = NULL;
    return budget;
}

// Add a transaction to a budget
void add_transaction(budget_t *budget, transaction_t *transaction) {
    // Reallocate the array of transactions if necessary
    if (budget->num_transactions >= budget->amount) {
        budget->transactions = realloc(budget->transactions, sizeof(transaction_t) * (budget->num_transactions + 1));
    }

    // Add the transaction to the array
    budget->transactions[budget->num_transactions] = *transaction;
    budget->num_transactions++;
}

// Print a budget
void print_budget(budget_t *budget) {
    printf("Budget: %s\n", budget->name);
    printf("Amount: %.2f\n", budget->amount);
    printf("Transactions:\n");
    for (int i = 0; i < budget->num_transactions; i++) {
        printf("    %s: %.2f\n", budget->transactions[i].description, budget->transactions[i].amount);
    }
}

// Free the memory allocated for a budget
void free_budget(budget_t *budget) {
    free(budget->transactions);
    free(budget);
}

// Main function
int main() {
    // Create a new budget
    budget_t *budget = new_budget("My Budget", 1000.00);

    // Add some transactions to the budget
    add_transaction(budget, new_transaction("Groceries", -50.00, 0));
    add_transaction(budget, new_transaction("Salary", 1000.00, 1));
    add_transaction(budget, new_transaction("Rent", -300.00, 0));
    add_transaction(budget, new_transaction("Utilities", -100.00, 0));
    add_transaction(budget, new_transaction("Savings", 200.00, 1));

    // Print the budget
    print_budget(budget);

    // Free the memory allocated for the budget
    free_budget(budget);

    return 0;
}