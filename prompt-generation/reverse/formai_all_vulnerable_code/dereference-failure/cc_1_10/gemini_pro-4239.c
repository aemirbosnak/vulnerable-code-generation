//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char *description;
    double amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

// Define the structure of a personal finance plan
typedef struct {
    double income;
    double expenses;
    double savings;
    double debt;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} finance_plan;

// Create a new personal finance plan
finance_plan *create_plan() {
    finance_plan *plan = malloc(sizeof(finance_plan));
    plan->income = 0;
    plan->expenses = 0;
    plan->savings = 0;
    plan->debt = 0;
    plan->num_transactions = 0;
    return plan;
}

// Add a transaction to a personal finance plan
void add_transaction(finance_plan *plan, transaction t) {
    plan->transactions[plan->num_transactions] = t;
    plan->num_transactions++;
    if (t.type == 'I') {
        plan->income += t.amount;
    } else if (t.type == 'E') {
        plan->expenses += t.amount;
    }
}

// Calculate the savings rate for a personal finance plan
double savings_rate(finance_plan *plan) {
    return plan->savings / plan->income;
}

// Calculate the debt-to-income ratio for a personal finance plan
double debt_to_income_ratio(finance_plan *plan) {
    return plan->debt / plan->income;
}

// Print a personal finance plan
void print_plan(finance_plan *plan) {
    printf("Income: $%.2f\n", plan->income);
    printf("Expenses: $%.2f\n", plan->expenses);
    printf("Savings: $%.2f\n", plan->savings);
    printf("Debt: $%.2f\n", plan->debt);
    printf("Savings rate: %.2f%%\n", savings_rate(plan) * 100);
    printf("Debt-to-income ratio: %.2f%%\n", debt_to_income_ratio(plan) * 100);
    printf("Transactions:\n");
    for (int i = 0; i < plan->num_transactions; i++) {
        printf("\t%s: $%.2f (%c)\n", plan->transactions[i].description, plan->transactions[i].amount, plan->transactions[i].type);
    }
}

// Free the memory allocated for a personal finance plan
void free_plan(finance_plan *plan) {
    for (int i = 0; i < plan->num_transactions; i++) {
        free(plan->transactions[i].description);
    }
    free(plan);
}

int main() {
    // Create a new personal finance plan
    finance_plan *plan = create_plan();

    // Add some transactions to the plan
    add_transaction(plan, (transaction) {"Salary", 2000, 'I'});
    add_transaction(plan, (transaction) {"Rent", 500, 'E'});
    add_transaction(plan, (transaction) {"Groceries", 200, 'E'});
    add_transaction(plan, (transaction) {"Savings", 300, 'I'});
    add_transaction(plan, (transaction) {"Credit card payment", 100, 'E'});

    // Print the personal finance plan
    print_plan(plan);

    // Free the memory allocated for the personal finance plan
    free_plan(plan);

    return 0;
}