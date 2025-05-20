//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 5

// Structure to store customer information
typedef struct {
    char name[50];
    char address[100];
    int account_balance;
} customer_t;

// Structure to store account information
typedef struct {
    char account_number[10];
    char account_type[20];
    int balance;
} account_t;

// Function to create a new customer
customer_t *create_customer(char *name, char *address) {
    customer_t *customer = (customer_t *) malloc(sizeof(customer_t));
    strcpy(customer->name, name);
    strcpy(customer->address, address);
    customer->account_balance = 0;
    return customer;
}

// Function to create a new account for a customer
account_t *create_account(customer_t *customer, int balance) {
    account_t *account = (account_t *) malloc(sizeof(account_t));
    strcpy(account->account_number, "A001"); // Assign a unique account number
    strcpy(account->account_type, "Checking");
    account->balance = balance;
    customer->account_balance = balance;
    return account;
}

// Function to deposit money into an account
void deposit_money(account_t *account, int amount) {
    account->balance += amount;
    printf("Deposit successful! Your new balance is %d\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(account_t *account, int amount) {
    if (amount > account->balance) {
        printf("Insufficient funds! Your current balance is %d\n", account->balance);
    } else {
        account->balance -= amount;
        printf("Withdrawal successful! Your new balance is %d\n", account->balance);
    }
}

// Function to check the balance of an account
int check_balance(account_t *account) {
    return account->balance;
}

// Function to close an account
void close_account(account_t *account) {
    printf("Account closed successfully!\n");
}

// Function to main function
int main() {
    // Create a list of customers
    customer_t *customers[MAX_CUSTOMERS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i] = create_customer("Customer", "123 Main St");
    }

    // Create a list of accounts for each customer
    account_t *accounts[MAX_ACCOUNTS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        for (int j = 0; j < MAX_ACCOUNTS; j++) {
            accounts[j] = create_account(customers[i], 1000);
        }
    }

    // Loop through each customer and account
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        for (int j = 0; j < MAX_ACCOUNTS; j++) {
            // Deposit money into an account
            deposit_money(accounts[j], 500);

            // Withdraw money from an account
            withdraw_money(accounts[j], 200);

            // Check the balance of an account
            int balance = check_balance(accounts[j]);
            printf("Account balance: %d\n", balance);

            // Close an account
            close_account(accounts[j]);
        }
    }

    return 0;
}