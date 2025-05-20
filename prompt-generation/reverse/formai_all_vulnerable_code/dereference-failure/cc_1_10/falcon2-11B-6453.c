//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[100];
    float balance;
    int id;
};

struct account* createAccount(char* name, float balance, int id) {
    struct account* account = (struct account*) malloc(sizeof(struct account));
    if (account == NULL) {
        fprintf(stderr, "Malloc failed\n");
        exit(1);
    }
    strcpy(account->name, name);
    account->balance = balance;
    account->id = id;
    return account;
}

void displayAccount(struct account* account) {
    printf("Name: %s\n", account->name);
    printf("Balance: %f\n", account->balance);
    printf("ID: %d\n", account->id);
}

void deposit(struct account* account, float amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposit successful\n");
    } else {
        printf("Invalid amount\n");
    }
}

void withdraw(struct account* account, float amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawal successful\n");
    } else {
        printf("Invalid amount\n");
    }
}

int main() {
    struct account* account = createAccount("John Doe", 1000.00, 1234);
    displayAccount(account);
    deposit(account, 500.00);
    displayAccount(account);
    withdraw(account, 200.00);
    displayAccount(account);
    return 0;
}