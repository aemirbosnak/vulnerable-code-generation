//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer information
typedef struct customer {
    char name[50];
    char address[100];
    char phone[20];
    double balance;
} customer;

// Function to create a new customer
customer* create_customer(char *name, char *address, char *phone, double balance) {
    customer *new_customer = (customer*) malloc(sizeof(customer));
    strcpy(new_customer->name, name);
    strcpy(new_customer->address, address);
    strcpy(new_customer->phone, phone);
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

// Function to print customer information
void print_customer(customer *customer) {
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Phone: %s\n", customer->phone);
    printf("Balance: %.2f\n", customer->balance);
}

// Main function
int main() {
    // Create a new customer
    customer *customer1 = create_customer("John Doe", "123 Main Street", "555-1212", 1000.00);

    // Deposit money into the account
    deposit_money(customer1, 500.00);

    // Withdraw money from the account
    withdraw_money(customer1, 300.00);

    // Print customer information
    print_customer(customer1);

    return 0;
}