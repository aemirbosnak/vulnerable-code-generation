//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the data structures
typedef struct {
    char* name;
    float balance;
} Account;

typedef struct {
    char* name;
    float amount;
    float interest_rate;
    int term;
} Loan;

typedef struct {
    Account* accounts;
    int num_accounts;
    Loan* loans;
    int num_loans;
    float income;
    float expenses;
    float savings_goal;
} PersonalFinancePlan;

// Create a new personal finance plan
PersonalFinancePlan* create_plan() {
    PersonalFinancePlan* plan = malloc(sizeof(PersonalFinancePlan));

    plan->accounts = NULL;
    plan->num_accounts = 0;
    plan->loans = NULL;
    plan->num_loans = 0;
    plan->income = 0;
    plan->expenses = 0;
    plan->savings_goal = 0;

    return plan;
}

// Add an account to the plan
void add_account(PersonalFinancePlan* plan, char* name, float balance) {
    plan->accounts = realloc(plan->accounts, (plan->num_accounts + 1) * sizeof(Account));
    plan->accounts[plan->num_accounts].name = name;
    plan->accounts[plan->num_accounts].balance = balance;
    plan->num_accounts++;
}

// Add a loan to the plan
void add_loan(PersonalFinancePlan* plan, char* name, float amount, float interest_rate, int term) {
    plan->loans = realloc(plan->loans, (plan->num_loans + 1) * sizeof(Loan));
    plan->loans[plan->num_loans].name = name;
    plan->loans[plan->num_loans].amount = amount;
    plan->loans[plan->num_loans].interest_rate = interest_rate;
    plan->loans[plan->num_loans].term = term;
    plan->num_loans++;
}

// Set the income for the plan
void set_income(PersonalFinancePlan* plan, float income) {
    plan->income = income;
}

// Set the expenses for the plan
void set_expenses(PersonalFinancePlan* plan, float expenses) {
    plan->expenses = expenses;
}

// Set the savings goal for the plan
void set_savings_goal(PersonalFinancePlan* plan, float savings_goal) {
    plan->savings_goal = savings_goal;
}

// Print the plan
void print_plan(PersonalFinancePlan* plan) {
    printf("Personal Finance Plan\n");
    printf("---------------------\n");
    printf("Accounts:\n");
    for (int i = 0; i < plan->num_accounts; i++) {
        printf(" - %s: $%.2f\n", plan->accounts[i].name, plan->accounts[i].balance);
    }
    printf("Loans:\n");
    for (int i = 0; i < plan->num_loans; i++) {
        printf(" - %s: $%.2f, %.2f%% interest, %d months\n", plan->loans[i].name, plan->loans[i].amount, plan->loans[i].interest_rate, plan->loans[i].term);
    }
    printf("Income: $%.2f\n", plan->income);
    printf("Expenses: $%.2f\n", plan->expenses);
    printf("Savings Goal: $%.2f\n", plan->savings_goal);
}

// Free the memory allocated for the plan
void free_plan(PersonalFinancePlan* plan) {
    for (int i = 0; i < plan->num_accounts; i++) {
        free(plan->accounts[i].name);
    }
    free(plan->accounts);
    for (int i = 0; i < plan->num_loans; i++) {
        free(plan->loans[i].name);
    }
    free(plan->loans);
    free(plan);
}

// Main function
int main() {
    // Create a new personal finance plan
    PersonalFinancePlan* plan = create_plan();

    // Add some accounts to the plan
    add_account(plan, "Checking", 1000);
    add_account(plan, "Savings", 5000);

    // Add some loans to the plan
    add_loan(plan, "Car Loan", 10000, 5.0, 60);
    add_loan(plan, "Student Loan", 20000, 7.0, 120);

    // Set the income and expenses for the plan
    set_income(plan, 5000);
    set_expenses(plan, 3000);

    // Set the savings goal for the plan
    set_savings_goal(plan, 10000);

    // Print the plan
    print_plan(plan);

    // Free the memory allocated for the plan
    free_plan(plan);

    return 0;
}