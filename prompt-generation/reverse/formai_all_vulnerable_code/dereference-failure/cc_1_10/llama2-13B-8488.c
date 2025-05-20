//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to store bank account information
struct account {
    int balance; // Initial balance
    int max_withdraw; // Maximum amount that can be withdrawn
    int withdraw_limit; // Current withdrawal limit
};

// Function to create a new bank account
struct account *new_account(int init_balance) {
    struct account *acc = malloc(sizeof(struct account));
    acc->balance = init_balance;
    acc->max_withdraw = init_balance;
    acc->withdraw_limit = init_balance;
    return acc;
}

// Function to deposit money into an account
void deposit(struct account *acc, int amount) {
    acc->balance += amount;
    if (acc->balance > acc->max_withdraw) {
        acc->max_withdraw = acc->balance;
    }
}

// Function to withdraw money from an account
void withdraw(struct account *acc, int amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        if (acc->balance < acc->withdraw_limit) {
            acc->withdraw_limit = acc->balance;
        }
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to check if an account has enough balance for a withdrawal
int can_withdraw(struct account *acc, int amount) {
    return acc->balance >= amount;
}

// Recursive function to simulate a bank account with multiple withdrawals
void recursive_withdrawals(struct account *acc) {
    if (acc->balance > 0) {
        // Withdraw half of the balance
        withdraw(acc, acc->balance / 2);
        // Recursively withdraw the remaining balance
        recursive_withdrawals(acc);
    }
}

int main() {
    struct account *acc = new_account(1000);
    deposit(acc, 500);
    withdraw(acc, 300);
    recursive_withdrawals(acc);
    printf("Balance: %d\n", acc->balance);
    return 0;
}