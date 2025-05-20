//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double balance;
    double interest_rate;
    int num_transactions;
    int *transaction_dates;
    double *transaction_amounts;
} account;

typedef struct {
    int num_accounts;
    account *accounts;
} portfolio;

portfolio *create_portfolio(int num_accounts) {
    portfolio *p = malloc(sizeof(portfolio));
    p->num_accounts = num_accounts;
    p->accounts = malloc(sizeof(account) * num_accounts);
    return p;
}

void free_portfolio(portfolio *p) {
    for (int i = 0; i < p->num_accounts; i++) {
        free(p->accounts[i].name);
        free(p->accounts[i].transaction_dates);
        free(p->accounts[i].transaction_amounts);
    }
    free(p->accounts);
    free(p);
}

account *create_account(char *name, double balance, double interest_rate) {
    account *a = malloc(sizeof(account));
    a->name = strdup(name);
    a->balance = balance;
    a->interest_rate = interest_rate;
    a->num_transactions = 0;
    a->transaction_dates = NULL;
    a->transaction_amounts = NULL;
    return a;
}

void free_account(account *a) {
    free(a->name);
    free(a->transaction_dates);
    free(a->transaction_amounts);
    free(a);
}

void add_transaction(account *a, int date, double amount) {
    a->num_transactions++;
    a->transaction_dates = realloc(a->transaction_dates, sizeof(int) * a->num_transactions);
    a->transaction_amounts = realloc(a->transaction_amounts, sizeof(double) * a->num_transactions);
    a->transaction_dates[a->num_transactions - 1] = date;
    a->transaction_amounts[a->num_transactions - 1] = amount;
}

void print_portfolio(portfolio *p) {
    for (int i = 0; i < p->num_accounts; i++) {
        printf("%s: $%.2f\n", p->accounts[i].name, p->accounts[i].balance);
    }
}

int main() {
    portfolio *p = create_portfolio(2);
    account *a1 = create_account("Checking", 1000.0, 0.01);
    account *a2 = create_account("Savings", 2000.0, 0.02);
    p->accounts[0] = *a1;
    p->accounts[1] = *a2;
    add_transaction(a1, 20230101, 100.0);
    add_transaction(a1, 20230102, -50.0);
    add_transaction(a2, 20230103, 200.0);
    print_portfolio(p);
    free_portfolio(p);
    return 0;
}