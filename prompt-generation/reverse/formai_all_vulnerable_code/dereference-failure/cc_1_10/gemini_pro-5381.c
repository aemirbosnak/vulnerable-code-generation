//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the struct for a transaction
typedef struct {
    char *description;
    double amount;
    char *category;
    char *date;
} transaction;

// Define the struct for a budget
typedef struct {
    char *category;
    double amount;
} budget;

// Create a new transaction
transaction *create_transaction(char *description, double amount, char *category, char *date) {
    transaction *new_transaction = malloc(sizeof(transaction));
    new_transaction->description = description;
    new_transaction->amount = amount;
    new_transaction->category = category;
    new_transaction->date = date;
    return new_transaction;
}

// Create a new budget
budget *create_budget(char *category, double amount) {
    budget *new_budget = malloc(sizeof(budget));
    new_budget->category = category;
    new_budget->amount = amount;
    return new_budget;
}

// Add a transaction to a list of transactions
void add_transaction(transaction **transactions, int *num_transactions, transaction *new_transaction) {
    *transactions = realloc(*transactions, (*num_transactions + 1) * sizeof(transaction));
    (*transactions)[*num_transactions] = *new_transaction;
    (*num_transactions)++;
}

// Add a budget to a list of budgets
void add_budget(budget **budgets, int *num_budgets, budget *new_budget) {
    *budgets = realloc(*budgets, (*num_budgets + 1) * sizeof(budget));
    (*budgets)[*num_budgets] = *new_budget;
    (*num_budgets)++;
}

// Print a list of transactions
void print_transactions(transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s, %f, %s, %s\n", transactions[i].description, transactions[i].amount, transactions[i].category, transactions[i].date);
    }
}

// Print a list of budgets
void print_budgets(budget *budgets, int num_budgets) {
    for (int i = 0; i < num_budgets; i++) {
        printf("%s, %f\n", budgets[i].category, budgets[i].amount);
    }
}

// Main function
int main() {
    // Create a list of transactions
    transaction *transactions = NULL;
    int num_transactions = 0;

    // Create a new transaction
    transaction *new_transaction = create_transaction("Bought groceries", -50.00, "Groceries", "2023-03-08");

    // Add the new transaction to the list of transactions
    add_transaction(&transactions, &num_transactions, new_transaction);

    // Create a list of budgets
    budget *budgets = NULL;
    int num_budgets = 0;

    // Create a new budget
    budget *new_budget = create_budget("Groceries", 200.00);

    // Add the new budget to the list of budgets
    add_budget(&budgets, &num_budgets, new_budget);

    // Print the list of transactions
    printf("Transactions:\n");
    print_transactions(transactions, num_transactions);

    // Print the list of budgets
    printf("\nBudgets:\n");
    print_budgets(budgets, num_budgets);

    return 0;
}