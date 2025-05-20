//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a customer account
typedef struct {
    int account_number;
    int balance;
} customer_account;

// Function to create a new customer account
customer_account* create_account(int account_number, int balance) {
    customer_account* new_account = (customer_account*) malloc(sizeof(customer_account));
    new_account->account_number = account_number;
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into a customer account
void deposit_money(customer_account* account, int amount) {
    account->balance += amount;
}

// Function to withdraw money from a customer account
void withdraw_money(customer_account* account, int amount) {
    if (amount > account->balance) {
        printf("Insufficient balance\n");
        return;
    }
    account->balance -= amount;
}

// Function to print the balance of a customer account
void print_balance(customer_account* account) {
    printf("Balance: %d\n", account->balance);
}

// Function to main function
int main() {
    // Create a new customer account
    customer_account* account = create_account(1234, 1000);

    // Deposit money into the account
    deposit_money(account, 500);

    // Withdraw money from the account
    withdraw_money(account, 300);

    // Print the balance of the account
    print_balance(account);

    // Free the memory allocated for the account
    free(account);

    return 0;
}