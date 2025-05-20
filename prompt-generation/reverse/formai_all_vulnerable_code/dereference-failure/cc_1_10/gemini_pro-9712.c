//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer data
struct customer {
    char name[50];
    char address[100];
    char phone[20];
    float balance;
};

// Function to create a new customer
struct customer* create_customer(char *name, char *address, char *phone, float balance) {
    struct customer *new_customer = (struct customer*)malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    strcpy(new_customer->address, address);
    strcpy(new_customer->phone, phone);
    new_customer->balance = balance;
    return new_customer;
}

// Function to deposit money into a customer's account
void deposit_money(struct customer *customer, float amount) {
    customer->balance += amount;
}

// Function to withdraw money from a customer's account
void withdraw_money(struct customer *customer, float amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to print customer data
void print_customer(struct customer *customer) {
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Phone: %s\n", customer->phone);
    printf("Balance: %f\n", customer->balance);
}

// Main function
int main() {
    // Create an array of customers
    struct customer *customers[100];

    // Add some customers to the array
    customers[0] = create_customer("John Smith", "123 Main Street", "555-1212", 1000.00);
    customers[1] = create_customer("Jane Doe", "456 Elm Street", "555-1213", 2000.00);
    customers[2] = create_customer("Bill Jones", "789 Oak Street", "555-1214", 3000.00);

    // Print the customer data
    for (int i = 0; i < 3; i++) {
        print_customer(customers[i]);
    }

    // Deposit some money into the first customer's account
    deposit_money(customers[0], 500.00);

    // Withdraw some money from the second customer's account
    withdraw_money(customers[1], 1000.00);

    // Print the customer data again
    for (int i = 0; i < 3; i++) {
        print_customer(customers[i]);
    }

    // Free the memory allocated for the customers
    for (int i = 0; i < 3; i++) {
        free(customers[i]);
    }

    return 0;
}