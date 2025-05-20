//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double amount;
} IncomeSource;

typedef struct {
    char *name;
    double amount;
} ExpenseCategory;

typedef struct {
    char *name;
    double balance;
    IncomeSource *incomes;
    int num_incomes;
    ExpenseCategory *expenses;
    int num_expenses;
} Account;

Account *create_account(char *name, double balance) {
    Account *account = malloc(sizeof(Account));
    account->name = strdup(name);
    account->balance = balance;
    account->incomes = NULL;
    account->num_incomes = 0;
    account->expenses = NULL;
    account->num_expenses = 0;
    return account;
}

void add_income(Account *account, char *name, double amount) {
    IncomeSource *income = malloc(sizeof(IncomeSource));
    income->name = strdup(name);
    income->amount = amount;
    account->incomes = realloc(account->incomes, (account->num_incomes + 1) * sizeof(IncomeSource));
    account->incomes[account->num_incomes++] = *income;
}

void add_expense(Account *account, char *name, double amount) {
    ExpenseCategory *expense = malloc(sizeof(ExpenseCategory));
    expense->name = strdup(name);
    expense->amount = amount;
    account->expenses = realloc(account->expenses, (account->num_expenses + 1) * sizeof(ExpenseCategory));
    account->expenses[account->num_expenses++] = *expense;
}

void print_account(Account *account) {
    printf("Account: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
    printf("Incomes:\n");
    for (int i = 0; i < account->num_incomes; i++) {
        printf("  %s: %.2f\n", account->incomes[i].name, account->incomes[i].amount);
    }
    printf("Expenses:\n");
    for (int i = 0; i < account->num_expenses; i++) {
        printf("  %s: %.2f\n", account->expenses[i].name, account->expenses[i].amount);
    }
}

void free_account(Account *account) {
    free(account->name);
    for (int i = 0; i < account->num_incomes; i++) {
        free(account->incomes[i].name);
    }
    free(account->incomes);
    for (int i = 0; i < account->num_expenses; i++) {
        free(account->expenses[i].name);
    }
    free(account->expenses);
    free(account);
}

int main() {
    // Create a new account
    Account *account = create_account("My Account", 1000.00);

    // Add some incomes
    add_income(account, "Salary", 2000.00);
    add_income(account, "Interest", 10.00);

    // Add some expenses
    add_expense(account, "Rent", 500.00);
    add_expense(account, "Groceries", 200.00);
    add_expense(account, "Transportation", 100.00);

    // Print the account
    print_account(account);

    // Free the account
    free_account(account);

    return 0;
}