//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: active
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
} transaction_t;

// Define the structure of a personal finance plan
typedef struct personal_finance_plan {
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
    double total_income;
    double total_expenses;
    double net_income;
} personal_finance_plan_t;

// Function to create a new personal finance plan
personal_finance_plan_t* create_personal_finance_plan() {
    personal_finance_plan_t* plan = (personal_finance_plan_t*)malloc(sizeof(personal_finance_plan_t));
    plan->num_transactions = 0;
    plan->total_income = 0.0;
    plan->total_expenses = 0.0;
    plan->net_income = 0.0;
    return plan;
}

// Function to add a transaction to a personal finance plan
void add_transaction(personal_finance_plan_t* plan, transaction_t transaction) {
    if (plan->num_transactions < MAX_TRANSACTIONS) {
        plan->transactions[plan->num_transactions] = transaction;
        plan->num_transactions++;
        if (transaction.type == 'I') {
            plan->total_income += transaction.amount;
        } else if (transaction.type == 'E') {
            plan->total_expenses += transaction.amount;
        }
        plan->net_income = plan->total_income - plan->total_expenses;
    } else {
        printf("Error: Maximum number of transactions reached.\n");
    }
}

// Function to print a personal finance plan
void print_personal_finance_plan(personal_finance_plan_t* plan) {
    printf("Personal Finance Plan\n");
    printf("--------------------\n");
    printf("Total Income: $%.2f\n", plan->total_income);
    printf("Total Expenses: $%.2f\n", plan->total_expenses);
    printf("Net Income: $%.2f\n", plan->net_income);
    printf("\n");
    printf("Transactions:\n");
    for (int i = 0; i < plan->num_transactions; i++) {
        printf("%s: $%.2f (%c)\n", plan->transactions[i].description, plan->transactions[i].amount, plan->transactions[i].type);
    }
}

// Main function
int main() {
    // Create a new personal finance plan
    personal_finance_plan_t* plan = create_personal_finance_plan();

    // Add some transactions to the plan
    transaction_t transaction1 = {"Salary", 2000.0, 'I'};
    add_transaction(plan, transaction1);
    transaction_t transaction2 = {"Rent", 1200.0, 'E'};
    add_transaction(plan, transaction2);
    transaction_t transaction3 = {"Groceries", 300.0, 'E'};
    add_transaction(plan, transaction3);
    transaction_t transaction4 = {"Entertainment", 200.0, 'E'};
    add_transaction(plan, transaction4);
    transaction_t transaction5 = {"Savings", 500.0, 'I'};
    add_transaction(plan, transaction5);

    // Print the personal finance plan
    print_personal_finance_plan(plan);

    return 0;
}