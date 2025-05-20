//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_BALANCE 10000

// Structure to store account information
typedef struct {
    char name[50];
    int balance;
} account;

// Function to create a new account
account *create_account(char *name, int balance) {
    account *new_account = (account *)malloc(sizeof(account));
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit(account *account, int amount) {
    account->balance += amount;
    printf("Deposited %d into account %s, new balance is %d\n", amount, account->name, account->balance);
}

// Function to withdraw money from an account
void withdraw(account *account, int amount) {
    if (amount > account->balance) {
        printf("Insufficient balance in account %s, cannot withdraw %d\n", account->name, amount);
        return;
    }
    account->balance -= amount;
    printf("Withdrew %d from account %s, new balance is %d\n", amount, account->name, account->balance);
}

// Function to display the balance of an account
void display_balance(account *account) {
    printf("Balance of account %s is %d\n", account->name, account->balance);
}

// Function to create a new customer
account *create_customer(char *name) {
    account *new_account = create_account(name, 0);
    return new_account;
}

// Function to main function
int main() {
    // Create a new customer
    account *customer1 = create_customer("John Doe");

    // Deposit money into the account
    deposit(customer1, 1000);

    // Withdraw money from the account
    withdraw(customer1, 500);

    // Display the balance of the account
    display_balance(customer1);

    // Create another customer
    account *customer2 = create_customer("Jane Doe");

    // Deposit money into the account
    deposit(customer2, 2000);

    // Withdraw money from the account
    withdraw(customer2, 1000);

    // Display the balance of the account
    display_balance(customer2);

    return 0;
}