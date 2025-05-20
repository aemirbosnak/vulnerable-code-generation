//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int balance;
} account_t;

account_t *accounts[100];
int num_accounts = 0;

void create_account(char *name, int balance) {
    account_t *account = malloc(sizeof(account_t));
    account->name = malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->balance = balance;
    accounts[num_accounts++] = account;
}

void deposit(char *name, int amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i]->name, name) == 0) {
            accounts[i]->balance += amount;
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(char *name, int amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i]->name, name) == 0) {
            if (accounts[i]->balance >= amount) {
                accounts[i]->balance -= amount;
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %d\n", accounts[i]->name, accounts[i]->balance);
    }
}

int main() {
    create_account("Alice", 100);
    create_account("Bob", 200);
    create_account("Charlie", 300);

    deposit("Alice", 50);
    withdraw("Bob", 100);

    print_accounts();

    return 0;
}