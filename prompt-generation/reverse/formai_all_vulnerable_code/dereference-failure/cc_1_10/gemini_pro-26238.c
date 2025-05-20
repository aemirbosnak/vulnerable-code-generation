//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    float amount;
    int type; // 0 for income, 1 for expense
} Transaction;

// Define the structure of a personal finance plan
typedef struct {
    float income;
    float expenses;
    float balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} PersonalFinancePlan;

// Function to create a new personal finance plan
PersonalFinancePlan* create_plan() {
    PersonalFinancePlan* plan = malloc(sizeof(PersonalFinancePlan));
    plan->income = 0.0;
    plan->expenses = 0.0;
    plan->balance = 0.0;
    plan->num_transactions = 0;
    return plan;
}

// Function to add a transaction to a personal finance plan
void add_transaction(PersonalFinancePlan* plan, Transaction transaction) {
    plan->transactions[plan->num_transactions] = transaction;
    plan->num_transactions++;
    if (transaction.type == 0) {
        plan->income += transaction.amount;
    } else {
        plan->expenses += transaction.amount;
    }
    plan->balance = plan->income - plan->expenses;
}

// Function to print a personal finance plan
void print_plan(PersonalFinancePlan* plan) {
    printf("Income: $%.2f\n", plan->income);
    printf("Expenses: $%.2f\n", plan->expenses);
    printf("Balance: $%.2f\n", plan->balance);
    for (int i = 0; i < plan->num_transactions; i++) {
        printf("%s: $%.2f\n", plan->transactions[i].description, plan->transactions[i].amount);
    }
}

// Main function
int main() {
    // Create a new personal finance plan
    PersonalFinancePlan* plan = create_plan();

    // Add some transactions to the plan
    Transaction transaction1 = {"Salary", 2000.0, 0};
    add_transaction(plan, transaction1);
    Transaction transaction2 = {"Rent", -500.0, 1};
    add_transaction(plan, transaction2);
    Transaction transaction3 = {"Groceries", -100.0, 1};
    add_transaction(plan, transaction3);
    Transaction transaction4 = {"Entertainment", -50.0, 1};
    add_transaction(plan, transaction4);

    // Print the personal finance plan
    print_plan(plan);

    return 0;
}