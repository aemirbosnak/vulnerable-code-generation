//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

// Struct to hold information about customers
typedef struct {
    int account_number;
    char name[50];
    float balance;
} Customer;

// Function to create a new customer
Customer* create_customer(int account_number, char name[], float balance) {
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    customer->account_number = account_number;
    strcpy(customer->name, name);
    customer->balance = balance;
    return customer;
}

// Function to deposit an amount into a customer's account
void deposit(Customer* customer, float amount) {
    customer->balance += amount;
    printf("Deposited %.2f into account %d\n", amount, customer->account_number);
}

// Function to withdraw an amount from a customer's account
void withdraw(Customer* customer, float amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
        printf("Withdrew %.2f from account %d\n", amount, customer->account_number);
    } else {
        printf("Insufficient balance in account %d\n", customer->account_number);
    }
}

int main() {
    Customer* alice = create_customer(1001, "Alice", 5000.0);
    Customer* bob = create_customer(1002, "Bob", 10000.0);

    deposit(alice, 1000.0);
    withdraw(bob, 5000.0);
    withdraw(alice, 3000.0);
    deposit(bob, 2000.0);

    printf("\nAccount Details:\n");
    printf("Account %d: %s - Balance: %.2f\n", alice->account_number, alice->name, alice->balance);
    printf("Account %d: %s - Balance: %.2f\n", bob->account_number, bob->name, bob->balance);

    free(alice);
    free(bob);

    return 0;
}