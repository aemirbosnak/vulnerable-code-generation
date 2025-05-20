//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double amount;
} expense_t;

typedef struct {
    char *name;
    double balance;
    expense_t *expenses;
    int num_expenses;
} account_t;

int main() {
    // Initialize account
    account_t account = {
        .name = "My Account",
        .balance = 1000.00,
        .expenses = NULL,
        .num_expenses = 0
    };

    // Add some expenses
    expense_t expense1 = {
        .name = "Rent",
        .amount = 500.00
    };
    expense_t expense2 = {
        .name = "Groceries",
        .amount = 100.00
    };
    expense_t expense3 = {
        .name = "Utilities",
        .amount = 50.00
    };

    account.expenses = realloc(account.expenses, (account.num_expenses + 3) * sizeof(expense_t));
    account.expenses[account.num_expenses++] = expense1;
    account.expenses[account.num_expenses++] = expense2;
    account.expenses[account.num_expenses++] = expense3;

    // Print account balance and expenses
    printf("Account: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
    for (int i = 0; i < account.num_expenses; i++) {
        printf("Expense: %s\n", account.expenses[i].name);
        printf("Amount: $%.2f\n", account.expenses[i].amount);
    }

    // Free memory
    for (int i = 0; i < account.num_expenses; i++) {
        free(account.expenses[i].name);
    }
    free(account.expenses);

    return 0;
}