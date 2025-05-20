//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a customer
typedef struct {
    char name[50];
    int age;
    float balance;
} customer_t;

// Function to create a new customer
customer_t *create_customer(char *name, int age, float balance) {
    customer_t *new_customer = (customer_t *)malloc(sizeof(customer_t));
    strcpy(new_customer->name, name);
    new_customer->age = age;
    new_customer->balance = balance;
    return new_customer;
}

// Function to deposit money into a customer's account
void deposit_money(customer_t *customer, float amount) {
    customer->balance += amount;
    printf("Customer %s has deposited %f into their account.\n", customer->name, amount);
}

// Function to withdraw money from a customer's account
void withdraw_money(customer_t *customer, float amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
        printf("Customer %s has withdrawn %f from their account.\n", customer->name, amount);
    } else {
        printf("Insufficient balance! Customer %s cannot withdraw %f.\n", customer->name, amount);
    }
}

// Function to check if a customer's balance is greater than or equal to a certain amount
bool check_balance(customer_t *customer, float amount) {
    return customer->balance >= amount;
}

// Function to print all customers and their balances
void print_customers(customer_t *customers[], int num_customers) {
    for (int i = 0; i < num_customers; i++) {
        printf("%d. Customer %s has a balance of %f\n", i + 1, customers[i]->name, customers[i]->balance);
    }
}

int main() {
    // Create some customers
    customer_t *customer1 = create_customer("John Doe", 35, 1000.00);
    customer_t *customer2 = create_customer("Jane Doe", 27, 500.00);
    customer_t *customer3 = create_customer("Bob Smith", 42, 2000.00);

    // Add some money to each customer's account
    deposit_money(customer1, 500.00);
    deposit_money(customer2, 200.00);
    deposit_money(customer3, 1000.00);

    // Print all customers and their balances
    print_customers(customer1, 3);

    // Withdraw some money from each customer's account
    withdraw_money(customer1, 250.00);
    withdraw_money(customer2, 300.00);
    withdraw_money(customer3, 500.00);

    // Print all customers and their balances again
    print_customers(customer1, 3);

    return 0;
}