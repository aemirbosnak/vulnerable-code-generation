//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account
typedef struct {
    int balance; // Initial balance
    int account_number; // Unique account number
} account;

// Function to create a new bank account
account* create_account(int balance, int account_number) {
    // Allocate memory for the account structure using malloc
    account* new_account = (account*) malloc(sizeof(account));
    new_account->balance = balance;
    new_account->account_number = account_number;
    return new_account;
}

// Function to deposit money into an account
void deposit(account* account, int amount) {
    // Increment the balance of the account
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(account* account, int amount) {
    // Decrement the balance of the account
    account->balance -= amount;
}

// Function to print the balance of an account
void print_balance(account* account) {
    printf("Balance: %d\n", account->balance);
}

int main() {
    // Create three bank accounts
    account* account1 = create_account(1000, 101);
    account* account2 = create_account(500, 102);
    account* account3 = create_account(2000, 103);

    // Deposit money into the accounts
    deposit(account1, 200);
    deposit(account2, 300);
    deposit(account3, 400);

    // Withdraw money from the accounts
    withdraw(account1, 100);
    withdraw(account2, 200);
    withdraw(account3, 300);

    // Print the balance of the accounts
    print_balance(account1);
    print_balance(account2);
    print_balance(account3);

    // Free the memory allocated for the accounts
    free(account1);
    free(account2);
    free(account3);

    return 0;
}