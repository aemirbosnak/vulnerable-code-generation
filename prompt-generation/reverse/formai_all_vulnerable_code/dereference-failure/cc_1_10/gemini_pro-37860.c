//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double balance;
} account;

typedef struct {
    char *name;
    double income;
    double expenses;
    account *accounts;
    int num_accounts;
} budget;

int main() {
    // Create a new budget
    budget my_budget;
    my_budget.name = "My Budget";
    my_budget.income = 5000;
    my_budget.expenses = 2500;
    my_budget.num_accounts = 2;

    // Create two accounts
    account checking_account;
    checking_account.name = "Checking Account";
    checking_account.balance = 1000;

    account savings_account;
    savings_account.name = "Savings Account";
    savings_account.balance = 2000;

    // Add the accounts to the budget
    my_budget.accounts = malloc(sizeof(account) * my_budget.num_accounts);
    my_budget.accounts[0] = checking_account;
    my_budget.accounts[1] = savings_account;

    // Print the budget
    printf("Budget Name: %s\n", my_budget.name);
    printf("Income: %f\n", my_budget.income);
    printf("Expenses: %f\n", my_budget.expenses);
    printf("Accounts:\n");
    for (int i = 0; i < my_budget.num_accounts; i++) {
        printf("  %s: %f\n", my_budget.accounts[i].name, my_budget.accounts[i].balance);
    }

    return 0;
}