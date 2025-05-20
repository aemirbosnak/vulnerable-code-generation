//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to store customer details
typedef struct customer {
    int account_number;
    char name[50];
    float balance;
} customer;

// Function to create a new customer
customer* create_customer(int account_number, char* name, float balance) {
    customer* new_customer = (customer*)malloc(sizeof(customer));
    new_customer->account_number = account_number;
    strcpy(new_customer->name, name);
    new_customer->balance = balance;
    return new_customer;
}

// Function to print customer details
void print_customer(customer* customer) {
    printf("Account Number: %d\n", customer->account_number);
    printf("Name: %s\n", customer->name);
    printf("Balance: %.2f\n", customer->balance);
}

// Function to deposit money into an account
void deposit_money(customer* customer, float amount) {
    customer->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(customer* customer, float amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Main function
int main() {
    // Create an array of customers
    customer* customers[100];
    int num_customers = 0;

    // Create some customers
    customers[num_customers++] = create_customer(123456789, "John Doe", 1000.00);
    customers[num_customers++] = create_customer(987654321, "Jane Doe", 2000.00);

    // Print the customer details
    for (int i = 0; i < num_customers; i++) {
        print_customer(customers[i]);
    }

    // Deposit money into John Doe's account
    deposit_money(customers[0], 500.00);

    // Withdraw money from Jane Doe's account
    withdraw_money(customers[1], 300.00);

    // Print the updated customer details
    for (int i = 0; i < num_customers; i++) {
        print_customer(customers[i]);
    }

    return 0;
}