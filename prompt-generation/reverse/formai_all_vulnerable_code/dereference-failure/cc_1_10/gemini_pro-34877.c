//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[256];
    double balance;
    struct transaction *transactions;
};

struct transaction {
    char description[256];
    double amount;
    struct transaction *next;
};

struct budget {
    char category[256];
    double amount;
};

struct personal_finance_planner {
    struct account *accounts; // Array of accounts
    int num_accounts;
    struct budget *budgets; // Array of budgets
    int num_budgets;
};

struct personal_finance_planner *create_personal_finance_planner() {
    struct personal_finance_planner *planner = malloc(sizeof(struct personal_finance_planner));
    planner->accounts = NULL;
    planner->num_accounts = 0;
    planner->budgets = NULL;
    planner->num_budgets = 0;
    return planner;
}

void destroy_personal_finance_planner(struct personal_finance_planner *planner) {
    for (int i = 0; i < planner->num_accounts; i++) {
        struct account *account = &planner->accounts[i];
        free(account->transactions);
        free(account);
    }
    free(planner->accounts);
    for (int i = 0; i < planner->num_budgets; i++) {
        struct budget *budget = &planner->budgets[i];
        free(budget);
    }
    free(planner->budgets);
    free(planner);
}

void add_account(struct personal_finance_planner *planner, const char *name, double balance) {
    struct account *account = malloc(sizeof(struct account));
    strcpy(account->name, name);
    account->balance = balance;
    account->transactions = NULL;
    planner->accounts = realloc(planner->accounts, (planner->num_accounts + 1) * sizeof(struct account));
    planner->accounts[planner->num_accounts] = *account;
    planner->num_accounts++;
}

void add_transaction(struct personal_finance_planner *planner, const char *account_name, const char *description, double amount) {
    for (int i = 0; i < planner->num_accounts; i++) {
        struct account *account = &planner->accounts[i];
        if (strcmp(account->name, account_name) == 0) {
            struct transaction *transaction = malloc(sizeof(struct transaction));
            strcpy(transaction->description, description);
            transaction->amount = amount;
            transaction->next = account->transactions;
            account->transactions = transaction;
            account->balance += amount;
            break;
        }
    }
}

void add_budget(struct personal_finance_planner *planner, const char *category, double amount) {
    struct budget *budget = malloc(sizeof(struct budget));
    strcpy(budget->category, category);
    budget->amount = amount;
    planner->budgets = realloc(planner->budgets, (planner->num_budgets + 1) * sizeof(struct budget));
    planner->budgets[planner->num_budgets] = *budget;
    planner->num_budgets++;
}

void print_report(struct personal_finance_planner *planner) {
    printf("Accounts:\n");
    for (int i = 0; i < planner->num_accounts; i++) {
        struct account *account = &planner->accounts[i];
        printf("  %s: $%.2f\n", account->name, account->balance);
    }
    printf("\nBudgets:\n");
    for (int i = 0; i < planner->num_budgets; i++) {
        struct budget *budget = &planner->budgets[i];
        printf("  %s: $%.2f\n", budget->category, budget->amount);
    }
}

int main() {
    struct personal_finance_planner *planner = create_personal_finance_planner();
    add_account(planner, "Checking", 1000.00);
    add_account(planner, "Savings", 2000.00);
    add_transaction(planner, "Checking", "Rent", -500.00);
    add_transaction(planner, "Checking", "Groceries", -100.00);
    add_transaction(planner, "Savings", "Interest", 25.00);
    add_budget(planner, "Rent", 500.00);
    add_budget(planner, "Groceries", 100.00);
    print_report(planner);
    destroy_personal_finance_planner(planner);
    return 0;
}