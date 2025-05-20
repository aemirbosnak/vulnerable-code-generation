//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer account
typedef struct {
    int balance; // Initial balance
    int fee; // Fee for each transaction
} customer_account;

// Function to create a new customer account
customer_account* create_account(int init_balance, int fee) {
    customer_account* acc = (customer_account*) malloc(sizeof(customer_account));
    acc->balance = init_balance;
    acc->fee = fee;
    return acc;
}

// Function to deposit money into a customer account
void deposit(customer_account* acc, int amount) {
    acc->balance += amount;
}

// Function to withdraw money from a customer account
void withdraw(customer_account* acc, int amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to charge a fee for a transaction
void charge_fee(customer_account* acc) {
    acc->balance -= acc->fee;
}

int main() {
    // Create a new customer account
    customer_account* acc = create_account(1000, 10);

    // Deposit money into the account
    deposit(acc, 500);

    // Withdraw money from the account
    withdraw(acc, 300);

    // Charge a fee for the transaction
    charge_fee(acc);

    // Print the current balance of the account
    printf("Current balance: %d\n", acc->balance);

    return 0;
}