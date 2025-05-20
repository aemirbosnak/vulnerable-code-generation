//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold customer information
struct customer {
    char name[100];
    int age;
    double balance;
};

// Define a function to create a new customer
struct customer* create_customer(char* name, int age, double balance) {
    struct customer* customer = (struct customer*)malloc(sizeof(struct customer));
    strcpy(customer->name, name);
    customer->age = age;
    customer->balance = balance;
    return customer;
}

// Define a function to display customer information
void display_customer(struct customer* customer) {
    printf("Name: %s\n", customer->name);
    printf("Age: %d\n", customer->age);
    printf("Balance: $%.2f\n", customer->balance);
}

// Define a function to update customer balance
void update_balance(struct customer* customer, double amount) {
    customer->balance += amount;
}

// Define a function to check if customer balance is positive
int is_balance_positive(struct customer* customer) {
    return customer->balance > 0;
}

int main() {
    // Create a new customer
    struct customer* customer1 = create_customer("John Doe", 25, 1000.00);
    printf("Created customer 1: %s\n", customer1->name);

    // Display customer information
    display_customer(customer1);

    // Update customer balance
    update_balance(customer1, 500.00);
    display_customer(customer1);

    // Check if balance is positive
    if (is_balance_positive(customer1)) {
        printf("Customer balance is positive.\n");
    } else {
        printf("Customer balance is negative.\n");
    }

    // Free memory allocated for customer1
    free(customer1);

    return 0;
}