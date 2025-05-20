//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for a transaction
typedef struct {
    char *description;
    double amount;
    char *category;
} transaction_t;

// Define the data structure for a personal finance plan
typedef struct {
    char *name;
    double income;
    double expenses;
    double savings;
    transaction_t *transactions;
    int num_transactions;
} personal_finance_plan_t;

// Create a new personal finance plan
personal_finance_plan_t *create_plan(char *name, double income, double expenses, double savings) {
    personal_finance_plan_t *plan = malloc(sizeof(personal_finance_plan_t));
    plan->name = strdup(name);
    plan->income = income;
    plan->expenses = expenses;
    plan->savings = savings;
    plan->transactions = NULL;
    plan->num_transactions = 0;
    return plan;
}

// Add a transaction to a personal finance plan
void add_transaction(personal_finance_plan_t *plan, char *description, double amount, char *category) {
    plan->transactions = realloc(plan->transactions, (plan->num_transactions + 1) * sizeof(transaction_t));
    plan->transactions[plan->num_transactions].description = strdup(description);
    plan->transactions[plan->num_transactions].amount = amount;
    plan->transactions[plan->num_transactions].category = strdup(category);
    plan->num_transactions++;
}

// Print a personal finance plan
void print_plan(personal_finance_plan_t *plan) {
    printf("Name: %s\n", plan->name);
    printf("Income: %.2f\n", plan->income);
    printf("Expenses: %.2f\n", plan->expenses);
    printf("Savings: %.2f\n", plan->savings);
    printf("Transactions:\n");
    for (int i = 0; i < plan->num_transactions; i++) {
        printf("  - %s: %.2f (%s)\n", plan->transactions[i].description, plan->transactions[i].amount, plan->transactions[i].category);
    }
}

// Free the memory allocated for a personal finance plan
void free_plan(personal_finance_plan_t *plan) {
    free(plan->name);
    for (int i = 0; i < plan->num_transactions; i++) {
        free(plan->transactions[i].description);
        free(plan->transactions[i].category);
    }
    free(plan->transactions);
    free(plan);
}

// Main function
int main() {
    // Create a new personal finance plan
    personal_finance_plan_t *plan = create_plan("My Plan", 5000, 3000, 2000);

    // Add some transactions to the plan
    add_transaction(plan, "Rent", -1000, "Housing");
    add_transaction(plan, "Groceries", -200, "Food");
    add_transaction(plan, "Entertainment", -100, "Fun");
    add_transaction(plan, "Savings", 500, "Savings");

    // Print the plan
    print_plan(plan);

    // Free the memory allocated for the plan
    free_plan(plan);

    return 0;
}