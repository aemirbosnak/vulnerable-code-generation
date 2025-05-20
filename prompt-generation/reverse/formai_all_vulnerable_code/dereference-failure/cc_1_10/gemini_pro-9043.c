//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a transaction
typedef struct {
    char *description;
    float amount;
    char *category;
    char *date;
} transaction;

// Define the structure of a budget
typedef struct {
    char *name;
    float amount;
    char *category;
} budget;

// Create a new transaction
transaction *new_transaction(char *description, float amount, char *category, char *date) {
    transaction *t = malloc(sizeof(transaction));
    t->description = malloc(strlen(description) + 1);
    strcpy(t->description, description);
    t->amount = amount;
    t->category = malloc(strlen(category) + 1);
    strcpy(t->category, category);
    t->date = malloc(strlen(date) + 1);
    strcpy(t->date, date);
    return t;
}

// Create a new budget
budget *new_budget(char *name, float amount, char *category) {
    budget *b = malloc(sizeof(budget));
    b->name = malloc(strlen(name) + 1);
    strcpy(b->name, name);
    b->amount = amount;
    b->category = malloc(strlen(category) + 1);
    strcpy(b->category, category);
    return b;
}

// Print a transaction
void print_transaction(transaction *t) {
    printf("%s\t%.2f\t%s\t%s\n", t->description, t->amount, t->category, t->date);
}

// Print a budget
void print_budget(budget *b) {
    printf("%s\t%.2f\t%s\n", b->name, b->amount, b->category);
}

// Main function
int main() {
    // Create a new personal finance planner
    printf("Welcome to your personal finance planner!\n");

    // Create a list of transactions
    transaction *transactions[] = {
        new_transaction("Groceries", -50.00, "Food", "2023-01-01"),
        new_transaction("Gas", -20.00, "Transportation", "2023-01-05"),
        new_transaction("Salary", 2000.00, "Income", "2023-01-15"),
        new_transaction("Rent", -1000.00, "Housing", "2023-01-20"),
        new_transaction("Utilities", -150.00, "Housing", "2023-01-25"),
        new_transaction("Entertainment", -50.00, "Entertainment", "2023-01-30"),
    };

    // Create a list of budgets
    budget *budgets[] = {
        new_budget("Food", 200.00, "Food"),
        new_budget("Transportation", 100.00, "Transportation"),
        new_budget("Housing", 500.00, "Housing"),
        new_budget("Entertainment", 100.00, "Entertainment"),
    };

    // Print the list of transactions
    printf("\nTransactions:\n");
    for (int i = 0; i < sizeof(transactions) / sizeof(transactions[0]); i++) {
        print_transaction(transactions[i]);
    }

    // Print the list of budgets
    printf("\nBudgets:\n");
    for (int i = 0; i < sizeof(budgets) / sizeof(budgets[0]); i++) {
        print_budget(budgets[i]);
    }

    // Free the memory allocated for the transactions and budgets
    for (int i = 0; i < sizeof(transactions) / sizeof(transactions[0]); i++) {
        free(transactions[i]->description);
        free(transactions[i]->category);
        free(transactions[i]->date);
        free(transactions[i]);
    }

    for (int i = 0; i < sizeof(budgets) / sizeof(budgets[0]); i++) {
        free(budgets[i]->name);
        free(budgets[i]->category);
        free(budgets[i]);
    }

    return 0;
}