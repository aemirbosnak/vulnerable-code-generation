//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer
typedef struct {
    char name[50];
    int age;
    float balance;
} customer_t;

// Function to create a new customer
customer_t *create_customer(char *name, int age, float balance) {
    customer_t *new_customer = malloc(sizeof(customer_t));
    strcpy(new_customer->name, name);
    new_customer->age = age;
    new_customer->balance = balance;
    return new_customer;
}

// Function to deposit money into a customer's account
void deposit(customer_t *customer, float amount) {
    customer->balance += amount;
}

// Function to withdraw money from a customer's account
void withdraw(customer_t *customer, float amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to check if a customer's balance is greater than or equal to a given amount
int check_balance(customer_t *customer, float amount) {
    return customer->balance >= amount;
}

// Function to print a customer's information
void print_customer(customer_t *customer) {
    printf("Name: %s\nAge: %d\nBalance: %f\n", customer->name, customer->age, customer->balance);
}

// Function to main function
int main() {
    // Create a new customer
    customer_t *customer1 = create_customer("John Doe", 30, 1000.00);

    // Deposit money into the customer's account
    deposit(customer1, 500.00);

    // Withdraw money from the customer's account
    withdraw(customer1, 200.00);

    // Check if the customer's balance is greater than or equal to a given amount
    if (check_balance(customer1, 300.00)) {
        printf("Customer has sufficient balance\n");
    } else {
        printf("Insufficient balance\n");
    }

    // Print the customer's information
    print_customer(customer1);

    // Free the memory allocated for the customer
    free(customer1);

    return 0;
}