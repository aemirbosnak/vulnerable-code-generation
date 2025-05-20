//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer information
typedef struct {
    char name[50];
    char address[100];
    int account_number;
    double balance;
} customer_t;

// Function to create a new customer
customer_t *new_customer(char *name, char *address) {
    customer_t *customer = (customer_t *)malloc(sizeof(customer_t));
    strcpy(customer->name, name);
    strcpy(customer->address, address);
    customer->account_number = 0;
    customer->balance = 0.0;
    return customer;
}

// Function to open a new account
void open_account(customer_t *customer, double amount) {
    customer->account_number++;
    customer->balance += amount;
}

// Function to deposit money into an account
void deposit_money(customer_t *customer, double amount) {
    customer->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(customer_t *customer, double amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to check the balance of an account
void check_balance(customer_t *customer) {
    printf("Balance: %f\n", customer->balance);
}

// Function to close an account
void close_account(customer_t *customer) {
    customer->account_number--;
}

int main() {
    // Create a new customer
    customer_t *customer = new_customer("John Doe", "123 Main St");

    // Open a new account
    open_account(customer, 1000.0);

    // Deposit money into the account
    deposit_money(customer, 500.0);

    // Withdraw money from the account
    withdraw_money(customer, 200.0);

    // Check the balance of the account
    check_balance(customer);

    // Close the account
    close_account(customer);

    return 0;
}