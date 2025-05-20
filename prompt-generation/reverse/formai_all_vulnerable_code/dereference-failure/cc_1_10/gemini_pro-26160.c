//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int account_number;
    double balance;
} account;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of accounts
    account accounts[10];

    // Initialize the accounts with random data
    for (int i = 0; i < 10; i++) {
        accounts[i].name = malloc(20);
        sprintf(accounts[i].name, "Account %d", i);
        accounts[i].account_number = rand() % 1000000000;
        accounts[i].balance = (double)rand() / RAND_MAX * 1000000;
    }

    // Print the accounts
    printf("Accounts:\n");
    for (int i = 0; i < 10; i++) {
        printf("  %s (%d): $%.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }

    // Create a new account
    account new_account;
    new_account.name = malloc(20);
    strcpy(new_account.name, "New Account");
    new_account.account_number = rand() % 1000000000;
    new_account.balance = 0.0;

    // Add the new account to the array
    accounts[10] = new_account;

    // Print the accounts
    printf("\nAccounts after adding new account:\n");
    for (int i = 0; i < 11; i++) {
        printf("  %s (%d): $%.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }

    // Free the memory allocated for the account names
    for (int i = 0; i < 11; i++) {
        free(accounts[i].name);
    }

    return 0;
}