//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int id;
    char name[50];
    double balance;
};

typedef struct Account Account;

Account* create_account(int id, char name[50], double balance) {
    Account* acc = malloc(sizeof(Account));
    strcpy(acc->name, name);
    acc->id = id;
    acc->balance = balance;
    return acc;
}

void deposit(Account* acc, double amount) {
    acc->balance += amount;
    printf("Deposit of %0.2f successfully credited to account %s\n", amount, acc->name);
}

void withdraw(Account* acc, double amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Withdrawal of %0.2f successfully debited from account %s\n", amount, acc->name);
    } else {
        printf("Insufficient funds\n");
    }
}

void display_account(Account* acc) {
    printf("Account ID: %d\n", acc->id);
    printf("Account Name: %s\n", acc->name);
    printf("Account Balance: %0.2f\n", acc->balance);
}

int main() {
    Account* acc1 = create_account(123, "John Doe", 1000.00);
    Account* acc2 = create_account(456, "Jane Doe", 500.00);

    deposit(acc1, 500.00);
    withdraw(acc1, 200.00);
    deposit(acc2, 1000.00);
    withdraw(acc2, 200.00);

    display_account(acc1);
    display_account(acc2);

    free(acc1);
    free(acc2);

    return 0;
}