//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct transaction {
    char description[50];
    double amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

// Define the structure of a personal finance plan
typedef struct personal_finance_plan {
    char name[50];
    int num_transactions;
    transaction transactions[MAX_TRANSACTIONS];
    double total_income;
    double total_expenses;
    double net_income;
} personal_finance_plan;

// Function to create a new personal finance plan
personal_finance_plan* create_plan(char* name) {
    personal_finance_plan* plan = malloc(sizeof(personal_finance_plan));
    strcpy(plan->name, name);
    plan->num_transactions = 0;
    plan->total_income = 0;
    plan->total_expenses = 0;
    plan->net_income = 0;
    return plan;
}

// Function to add a transaction to a personal finance plan
void add_transaction(personal_finance_plan* plan, char* description, double amount, char type) {
    if (plan->num_transactions < MAX_TRANSACTIONS) {
        strcpy(plan->transactions[plan->num_transactions].description, description);
        plan->transactions[plan->num_transactions].amount = amount;
        plan->transactions[plan->num_transactions].type = type;
        plan->num_transactions++;
        if (type == 'I') {
            plan->total_income += amount;
        } else if (type == 'E') {
            plan->total_expenses += amount;
        }
        plan->net_income = plan->total_income - plan->total_expenses;
    } else {
        printf("Error: Maximum number of transactions reached.\n");
    }
}

// Function to print a personal finance plan
void print_plan(personal_finance_plan* plan) {
    printf("Personal Finance Plan: %s\n", plan->name);
    printf("=======================================\n");
    printf("Transactions:\n");
    for (int i = 0; i < plan->num_transactions; i++) {
        printf("  - %s: $%.2f (%c)\n", plan->transactions[i].description, plan->transactions[i].amount, plan->transactions[i].type);
    }
    printf("\n");
    printf("Total Income: $%.2f\n", plan->total_income);
    printf("Total Expenses: $%.2f\n", plan->total_expenses);
    printf("Net Income: $%.2f\n", plan->net_income);
}

// Function to free the memory allocated for a personal finance plan
void free_plan(personal_finance_plan* plan) {
    free(plan);
}

// Main function
int main() {
    // Create a new personal finance plan
    personal_finance_plan* plan = create_plan("My Personal Finance Plan");

    // Add some transactions to the plan
    add_transaction(plan, "Salary", 2000, 'I');
    add_transaction(plan, "Rent", 1000, 'E');
    add_transaction(plan, "Groceries", 200, 'E');
    add_transaction(plan, "Entertainment", 100, 'E');
    add_transaction(plan, "Savings", 500, 'I');

    // Print the personal finance plan
    print_plan(plan);

    // Free the memory allocated for the personal finance plan
    free_plan(plan);

    return 0;
}