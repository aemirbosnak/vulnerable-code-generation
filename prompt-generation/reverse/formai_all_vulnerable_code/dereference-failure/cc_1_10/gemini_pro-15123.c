//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a customer
typedef struct customer {
    int account_number;
    char name[50];
    double balance;
} customer;

// Function to create a new customer
customer* create_customer(int account_number, char *name, double balance) {
    customer *new_customer = (customer*)malloc(sizeof(customer));
    new_customer->account_number = account_number;
    strcpy(new_customer->name, name);
    new_customer->balance = balance;

    return new_customer;
}

// Function to deposit money into an account
void deposit_money(customer *customer, double amount) {
    customer->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(customer *customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print the details of a customer
void print_customer_details(customer *customer) {
    printf("Account Number: %d\n", customer->account_number);
    printf("Name: %s\n", customer->name);
    printf("Balance: %.2f\n", customer->balance);
}

// Main function
int main() {
    // Create a customer
    customer *customer1 = create_customer(123456, "John Smith", 1000.00);

    // Deposit money into the account
    deposit_money(customer1, 500.00);

    // Withdraw money from the account
    withdraw_money(customer1, 300.00);

    // Print the details of the customer
    print_customer_details(customer1);

    return 0;
}