//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _account {
    int account_number;
    char *name;
    double balance;
} account;

typedef struct _bank {
    int num_accounts;
    struct _account *accounts;
} bank;

// Utility functions
void print_account(account *a) {
    printf("Account number: %d\n", a->account_number);
    printf("Name: %s\n", a->name);
    printf("Balance: %f\n", a->balance);
}

void print_bank(bank *b) {
    for (int i = 0; i < b->num_accounts; i++) {
        print_account(&b->accounts[i]);
        printf("\n");
    }
}

// Banking operations
bool deposit(bank *b, int account_number, double amount) {
    for (int i = 0; i < b->num_accounts; i++) {
        if (b->accounts[i].account_number == account_number) {
            b->accounts[i].balance += amount;
            return true;
        }
    }
    return false;
}

bool withdraw(bank *b, int account_number, double amount) {
    for (int i = 0; i < b->num_accounts; i++) {
        if (b->accounts[i].account_number == account_number) {
            if (b->accounts[i].balance >= amount) {
                b->accounts[i].balance -= amount;
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

bool transfer(bank *b, int from_account_number, int to_account_number, double amount) {
    if (from_account_number == to_account_number) {
        return false;
    }
    for (int i = 0; i < b->num_accounts; i++) {
        if (b->accounts[i].account_number == from_account_number) {
            if (b->accounts[i].balance >= amount) {
                b->accounts[i].balance -= amount;
                for (int j = 0; j < b->num_accounts; j++) {
                    if (b->accounts[j].account_number == to_account_number) {
                        b->accounts[j].balance += amount;
                        return true;
                    }
                }
            } else {
                return false;
            }
        }
    }
    return false;
}

// Main function
int main() {
    // Initialize the bank
    bank b;
    b.num_accounts = 3;
    b.accounts = malloc(sizeof(account) * b.num_accounts);

    // Initialize the accounts
    b.accounts[0].account_number = 123456;
    b.accounts[0].name = "Sherlock Holmes";
    b.accounts[0].balance = 1000000.00;
    
    b.accounts[1].account_number = 234567;
    b.accounts[1].name = "John Watson";
    b.accounts[1].balance = 500000.00;
    
    b.accounts[2].account_number = 345678;
    b.accounts[2].name = "Irene Adler";
    b.accounts[2].balance = 250000.00;

    // Print the initial bank statement
    printf("Initial bank statement:\n");
    print_bank(&b);

    // Deposit some money into Sherlock's account
    deposit(&b, 123456, 100000.00);
    
    // Withdraw some money from John's account
    withdraw(&b, 234567, 50000.00);

    // Transfer some money from Irene's account to Sherlock's account
    transfer(&b, 345678, 123456, 25000.00);

    // Print the final bank statement
    printf("Final bank statement:\n");
    print_bank(&b);

    return 0;
}