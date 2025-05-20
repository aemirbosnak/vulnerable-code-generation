//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    double balance;
} account;

account *accounts;
int num_accounts;

void create_account(char *name, double balance) {
    accounts = realloc(accounts, (num_accounts + 1) * sizeof(account));
    accounts[num_accounts].name = malloc(strlen(name) + 1);
    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

void deposit(char *name, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            accounts[i].balance += amount;
            return;
        }
    }
    printf("No such account.\n");
}

void withdraw(char *name, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }
    printf("No such account.\n");
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %.2f\n", accounts[i].name, accounts[i].balance);
    }
}

int main() {
    srand(time(NULL));

    create_account("Alice", 1000.00);
    create_account("Bob", 500.00);
    create_account("Charlie", 200.00);

    deposit("Alice", 100.00);
    withdraw("Bob", 200.00);
    deposit("Charlie", 50.00);

    print_accounts();

    return 0;
}