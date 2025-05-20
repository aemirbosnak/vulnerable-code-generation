//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a bank account
struct bank_account {
    char name[100];
    int balance;
    int acc_no;
};

// Function to create a new bank account
struct bank_account* create_account(char* name, int balance, int acc_no) {
    struct bank_account* account = malloc(sizeof(struct bank_account));
    if (account == NULL) {
        printf("Failed to allocate memory for account\n");
        return NULL;
    }
    strcpy(account->name, name);
    account->balance = balance;
    account->acc_no = acc_no;
    return account;
}

// Function to deposit money into a bank account
void deposit(struct bank_account* account, int amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited $%d into account %s\n", amount, account->name);
    } else {
        printf("Invalid amount for deposit\n");
    }
}

// Function to withdraw money from a bank account
void withdraw(struct bank_account* account, int amount) {
    if (amount > 0) {
        if (amount <= account->balance) {
            account->balance -= amount;
            printf("Withdrew $%d from account %s\n", amount, account->name);
        } else {
            printf("Insufficient funds in account\n");
        }
    } else {
        printf("Invalid amount for withdrawal\n");
    }
}

// Function to check account balance
void check_balance(struct bank_account* account) {
    printf("Account balance for %s: $%d\n", account->name, account->balance);
}

// Function to close an account
void close_account(struct bank_account* account) {
    free(account);
    printf("Account closed\n");
}

int main() {
    struct bank_account* account = create_account("John Doe", 1000, 12345);
    deposit(account, 500);
    check_balance(account);
    withdraw(account, 200);
    check_balance(account);
    close_account(account);

    return 0;
}