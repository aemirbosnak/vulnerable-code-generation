//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

Customer* create_customer(char* name, int account_number, double balance) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

void deposit(Customer* customer, double amount) {
    customer->balance += amount;
}

void withdraw(Customer* customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds");
    }
}

void transfer(Customer* customer1, Customer* customer2, double amount) {
    if (amount <= customer1->balance) {
        deposit(customer2, amount);
        withdraw(customer1, amount);
    } else {
        printf("Insufficient funds");
    }
}

int main() {
    Customer* head = NULL;
    Customer* current_customer = NULL;

    // Create a few customers
    head = create_customer("John Doe", 123456, 1000);
    current_customer = head;
    create_customer("Jane Doe", 654321, 2000);
    create_customer("Bill Smith", 984123, 3000);

    // Deposit some money
    deposit(current_customer, 500);

    // Withdraw some money
    withdraw(current_customer, 200);

    // Transfer money
    transfer(current_customer, head, 100);

    // Print the customer's balance
    printf("Current customer balance: %f", current_customer->balance);

    return 0;
}