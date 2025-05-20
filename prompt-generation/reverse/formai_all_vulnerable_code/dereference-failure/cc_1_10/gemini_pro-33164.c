//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock Holmes' Banking Record System
//
// This program is a simple banking record system that allows users to create accounts, deposit money, withdraw money, and view their account balances.
//
// The program is written in a Sherlock Holmes style, with a focus on deduction and logic.

// The account structure
typedef struct account {
    char *name;
    int balance;
} account;

// The bank structure
typedef struct bank {
    account *accounts;
    int num_accounts;
} bank;

// Create a new account
account *create_account(char *name, int balance) {
    account *new_account = malloc(sizeof(account));
    new_account->name = strdup(name);
    new_account->balance = balance;
    return new_account;
}

// Deposit money into an account
void deposit_money(bank *bank, char *name, int amount) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (strcmp(bank->accounts[i].name, name) == 0) {
            bank->accounts[i].balance += amount;
            printf("Deposited %d pounds into %s's account.\n", amount, name);
            return;
        }
    }

    printf("Could not find an account with the name %s.\n", name);
}

// Withdraw money from an account
void withdraw_money(bank *bank, char *name, int amount) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (strcmp(bank->accounts[i].name, name) == 0) {
            if (bank->accounts[i].balance >= amount) {
                bank->accounts[i].balance -= amount;
                printf("Withdrew %d pounds from %s's account.\n", amount, name);
                return;
            } else {
                printf("Insufficient funds in %s's account.\n", name);
                return;
            }
        }
    }

    printf("Could not find an account with the name %s.\n", name);
}

// View the balance of an account
void view_balance(bank *bank, char *name) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (strcmp(bank->accounts[i].name, name) == 0) {
            printf("%s's balance: %d pounds.\n", name, bank->accounts[i].balance);
            return;
        }
    }

    printf("Could not find an account with the name %s.\n", name);
}

// Main function
int main() {
    // Create a new bank
    bank *bank = malloc(sizeof(bank));
    bank->accounts = NULL;
    bank->num_accounts = 0;

    // Create some accounts
    account *account1 = create_account("Sherlock Holmes", 1000);
    account *account2 = create_account("Dr. Watson", 500);
    account *account3 = create_account("Professor Moriarty", 0);

    // Add the accounts to the bank
    bank->accounts = realloc(bank->accounts, (bank->num_accounts + 3) * sizeof(account));
    bank->accounts[bank->num_accounts++] = *account1;
    bank->accounts[bank->num_accounts++] = *account2;
    bank->accounts[bank->num_accounts++] = *account3;

    // Deposit some money into the accounts
    deposit_money(bank, "Sherlock Holmes", 500);
    deposit_money(bank, "Dr. Watson", 250);

    // Withdraw some money from the accounts
    withdraw_money(bank, "Sherlock Holmes", 250);
    withdraw_money(bank, "Professor Moriarty", 100);

    // View the balances of the accounts
    view_balance(bank, "Sherlock Holmes");
    view_balance(bank, "Dr. Watson");
    view_balance(bank, "Professor Moriarty");

    // Free the memory allocated for the accounts
    free(account1);
    free(account2);
    free(account3);

    // Free the memory allocated for the bank
    free(bank->accounts);
    free(bank);

    return 0;
}