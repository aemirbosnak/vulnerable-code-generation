//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    double balance;
} account;

typedef struct {
    char* category;
    double amount;
} expense;

typedef struct {
    account* accounts;
    int num_accounts;
    expense* expenses;
    int num_expenses;
} finance_plan;

finance_plan* create_plan() {
    finance_plan* plan = malloc(sizeof(finance_plan));
    plan->accounts = NULL;
    plan->num_accounts = 0;
    plan->expenses = NULL;
    plan->num_expenses = 0;
    return plan;
}

void destroy_plan(finance_plan* plan) {
    for (int i = 0; i < plan->num_accounts; i++) {
        free(plan->accounts[i].name);
    }
    free(plan->accounts);
    for (int i = 0; i < plan->num_expenses; i++) {
        free(plan->expenses[i].category);
    }
    free(plan->expenses);
    free(plan);
}

account* create_account(char* name, double balance) {
    account* account = malloc(sizeof(account));
    account->name = malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

void add_account(finance_plan* plan, account* account) {
    plan->accounts = realloc(plan->accounts, (plan->num_accounts + 1) * sizeof(account));
    plan->accounts[plan->num_accounts] = *account;
    plan->num_accounts++;
}

expense* create_expense(char* category, double amount) {
    expense* expense = malloc(sizeof(expense));
    expense->category = malloc(strlen(category) + 1);
    strcpy(expense->category, category);
    expense->amount = amount;
    return expense;
}

void add_expense(finance_plan* plan, expense* expense) {
    plan->expenses = realloc(plan->expenses, (plan->num_expenses + 1) * sizeof(expense));
    plan->expenses[plan->num_expenses] = *expense;
    plan->num_expenses++;
}

void print_plan(finance_plan* plan) {
    printf("Accounts:\n");
    for (int i = 0; i < plan->num_accounts; i++) {
        printf("    %s: $%.2f\n", plan->accounts[i].name, plan->accounts[i].balance);
    }
    printf("Expenses:\n");
    for (int i = 0; i < plan->num_expenses; i++) {
        printf("    %s: $%.2f\n", plan->expenses[i].category, plan->expenses[i].amount);
    }
}

int main() {
    finance_plan* plan = create_plan();

    account* checking = create_account("Checking", 1000.00);
    add_account(plan, checking);

    account* savings = create_account("Savings", 2000.00);
    add_account(plan, savings);

    expense* rent = create_expense("Rent", 1200.00);
    add_expense(plan, rent);

    expense* groceries = create_expense("Groceries", 200.00);
    add_expense(plan, groceries);

    expense* entertainment = create_expense("Entertainment", 100.00);
    add_expense(plan, entertainment);

    print_plan(plan);

    destroy_plan(plan);
}