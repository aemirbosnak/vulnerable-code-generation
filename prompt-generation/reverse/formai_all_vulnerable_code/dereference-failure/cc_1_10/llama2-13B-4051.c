//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a bank account
typedef struct {
    int balance;  // Balance of the account
    char name[20]; // Name of the account holder
} account;

// Function to create a new bank account
account* create_account(const char* name) {
    account* new_account = (account*) malloc(sizeof(account));
    new_account->balance = 0;
    strcpy(new_account->name, name);
    return new_account;
}

// Function to deposit money into an account
void deposit(account* account, int amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(account* account, int amount) {
    if (amount > account->balance) {
        printf("Insufficient funds!\n");
        return;
    }
    account->balance -= amount;
}

// Function to print the balance of an account
void print_balance(account* account) {
    printf("Balance: %d\n", account->balance);
}

int main() {
    // Create three bank accounts
    account* account1 = create_account("John Doe");
    account* account2 = create_account("Jane Doe");
    account* account3 = create_account("Bob Smith");

    // Deposit money into the accounts
    deposit(account1, 1000);
    deposit(account2, 500);
    deposit(account3, 2000);

    // Withdraw money from the accounts
    withdraw(account1, 500);
    withdraw(account2, 200);
    withdraw(account3, 1000);

    // Print the balances of the accounts
    print_balance(account1);
    print_balance(account2);
    print_balance(account3);

    // Free the memory of the accounts
    free(account1);
    free(account2);
    free(account3);

    return 0;
}