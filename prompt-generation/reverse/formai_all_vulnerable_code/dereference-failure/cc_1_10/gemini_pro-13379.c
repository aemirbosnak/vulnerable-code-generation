//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double balance;
} account;

typedef struct {
    char name[50];
    double amount;
} transaction;

typedef struct {
    int num_accounts;
    account *accounts;
    int num_transactions;
    transaction *transactions;
} personal_finance_planner;

personal_finance_planner *create_personal_finance_planner(void) {
    personal_finance_planner *planner = malloc(sizeof(personal_finance_planner));
    if (planner == NULL) {
        return NULL;
    }
    planner->num_accounts = 0;
    planner->accounts = NULL;
    planner->num_transactions = 0;
    planner->transactions = NULL;
    return planner;
}

void destroy_personal_finance_planner(personal_finance_planner *planner) {
    if (planner == NULL) {
        return;
    }
    for (int i = 0; i < planner->num_accounts; i++) {
        free(planner->accounts[i].name);
    }
    free(planner->accounts);
    for (int i = 0; i < planner->num_transactions; i++) {
        free(planner->transactions[i].name);
    }
    free(planner->transactions);
    free(planner);
}

int add_account(personal_finance_planner *planner, const char *name, double balance) {
    if (planner == NULL || name == NULL) {
        return -1;
    }
    planner->accounts = realloc(planner->accounts, (planner->num_accounts + 1) * sizeof(account));
    if (planner->accounts == NULL) {
        return -1;
    }
    strcpy(planner->accounts[planner->num_accounts].name, name);
    planner->accounts[planner->num_accounts].balance = balance;
    planner->num_accounts++;
    return 0;
}

int add_transaction(personal_finance_planner *planner, const char *name, double amount) {
    if (planner == NULL || name == NULL) {
        return -1;
    }
    planner->transactions = realloc(planner->transactions, (planner->num_transactions + 1) * sizeof(transaction));
    if (planner->transactions == NULL) {
        return -1;
    }
    strcpy(planner->transactions[planner->num_transactions].name, name);
    planner->transactions[planner->num_transactions].amount = amount;
    planner->num_transactions++;
    return 0;
}

int print_personal_finance_planner(personal_finance_planner *planner) {
    if (planner == NULL) {
        return -1;
    }
    printf("Personal Finance Planner\n");
    printf("Accounts:\n");
    for (int i = 0; i < planner->num_accounts; i++) {
        printf("  %s: $%.2f\n", planner->accounts[i].name, planner->accounts[i].balance);
    }
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: $%.2f\n", planner->transactions[i].name, planner->transactions[i].amount);
    }
    return 0;
}

int main(void) {
    personal_finance_planner *planner = create_personal_finance_planner();
    if (planner == NULL) {
        return -1;
    }
    add_account(planner, "Checking", 1000.00);
    add_account(planner, "Savings", 2000.00);
    add_transaction(planner, "Rent", -1200.00);
    add_transaction(planner, "Groceries", -200.00);
    add_transaction(planner, "Salary", 3000.00);
    print_personal_finance_planner(planner);
    destroy_personal_finance_planner(planner);
    return 0;
}