//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main struct for storing financial data
typedef struct {
    char name[30];                  // Name of the account
    double balance;                 // Current balance
    double interest_rate;          // Annual interest rate
    double monthly_contribution;  // Monthly contribution
    double monthly_withdrawal;    // Monthly withdrawal
} account;

// Define the main struct for storing financial goals
typedef struct {
    char name[30];                  // Name of the goal
    double target_amount;         // Target amount
    double deadline;              // Deadline in years
} goal;

// Define the main struct for storing financial plans
typedef struct {
    account accounts[10];          // Array of accounts
    goal goals[10];                 // Array of goals
    int num_accounts;              // Number of accounts
    int num_goals;                 // Number of goals
} plan;

// Function to create a new financial plan
plan* create_plan() {
    plan* new_plan = (plan*)malloc(sizeof(plan));
    new_plan->num_accounts = 0;
    new_plan->num_goals = 0;
    return new_plan;
}

// Function to add a new account to a financial plan
void add_account(plan* plan, char* name, double balance, double interest_rate, double monthly_contribution, double monthly_withdrawal) {
    strcpy(plan->accounts[plan->num_accounts].name, name);
    plan->accounts[plan->num_accounts].balance = balance;
    plan->accounts[plan->num_accounts].interest_rate = interest_rate;
    plan->accounts[plan->num_accounts].monthly_contribution = monthly_contribution;
    plan->accounts[plan->num_accounts].monthly_withdrawal = monthly_withdrawal;
    plan->num_accounts++;
}

// Function to add a new goal to a financial plan
void add_goal(plan* plan, char* name, double target_amount, double deadline) {
    strcpy(plan->goals[plan->num_goals].name, name);
    plan->goals[plan->num_goals].target_amount = target_amount;
    plan->goals[plan->num_goals].deadline = deadline;
    plan->num_goals++;
}

// Function to print a financial plan
void print_plan(plan* plan) {
    printf("Financial Plan:\n");
    for (int i = 0; i < plan->num_accounts; i++) {
        printf("Account: %s\n", plan->accounts[i].name);
        printf("Balance: $%.2f\n", plan->accounts[i].balance);
        printf("Interest rate: %.2f%%\n", plan->accounts[i].interest_rate);
        printf("Monthly contribution: $%.2f\n", plan->accounts[i].monthly_contribution);
        printf("Monthly withdrawal: $%.2f\n\n", plan->accounts[i].monthly_withdrawal);
    }
    for (int i = 0; i < plan->num_goals; i++) {
        printf("Goal: %s\n", plan->goals[i].name);
        printf("Target amount: $%.2f\n", plan->goals[i].target_amount);
        printf("Deadline: %.2f years\n\n", plan->goals[i].deadline);
    }
}

// Main function
int main() {
    // Create a new financial plan
    plan* my_plan = create_plan();

    // Add some accounts to the plan
    add_account(my_plan, "Checking", 1000.00, 0.01, 100.00, 50.00);
    add_account(my_plan, "Savings", 5000.00, 0.02, 200.00, 0.00);
    add_account(my_plan, "Investment", 10000.00, 0.05, 500.00, 0.00);

    // Add some goals to the plan
    add_goal(my_plan, "Buy a house", 200000.00, 5.0);
    add_goal(my_plan, "Retire early", 1000000.00, 20.0);

    // Print the financial plan
    print_plan(my_plan);

    return 0;
}