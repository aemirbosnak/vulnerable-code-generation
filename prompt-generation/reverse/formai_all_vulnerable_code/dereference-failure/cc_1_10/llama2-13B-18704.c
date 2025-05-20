//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ACCOUNT_NAME_LENGTH 20
#define MAX_DEPOSIT_AMOUNT 10000
#define MAX_WITHDRAW_AMOUNT 5000
#define MIN_BALANCE 100

typedef struct {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    double balance;
} account_t;

account_t *create_account(const char *name) {
    account_t *acc = malloc(sizeof(account_t));
    strcpy(acc->name, name);
    acc->balance = 0;
    return acc;
}

void deposit(account_t *acc, double amount) {
    if (amount > MAX_DEPOSIT_AMOUNT || amount < 0) {
        fprintf(stderr, "Invalid amount: %f\n", amount);
        return;
    }

    acc->balance += amount;
    printf("Deposited %f to account %s\n", amount, acc->name);
}

void withdraw(account_t *acc, double amount) {
    if (amount > acc->balance || amount < 0) {
        fprintf(stderr, "Insufficient balance: %f\n", acc->balance);
        return;
    }

    acc->balance -= amount;
    printf("Withdrew %f from account %s\n", amount, acc->name);
}

void check_balance(account_t *acc) {
    if (acc->balance < MIN_BALANCE) {
        fprintf(stderr, "Account balance is too low: %f\n", acc->balance);
    }
    printf("Account balance: %f\n", acc->balance);
}

int main() {
    account_t *acc1 = create_account("John Doe");
    account_t *acc2 = create_account("Jane Doe");

    deposit(acc1, 1000);
    deposit(acc2, 500);

    check_balance(acc1);
    check_balance(acc2);

    withdraw(acc1, 500);
    withdraw(acc2, 200);

    check_balance(acc1);
    check_balance(acc2);

    return 0;
}