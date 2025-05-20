//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

struct customer {
    char name[20];
    int account_number;
    double balance;
    struct customer* next;
};

struct customer* create_customer(char* name, int account_number, double balance) {
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

void deposit(struct customer* customer, double amount) {
    customer->balance += amount;
}

void withdraw(struct customer* customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void transfer(struct customer* customer1, struct customer* customer2, double amount) {
    if (amount <= customer1->balance) {
        deposit(customer2, amount);
        withdraw(customer1, amount);
    } else {
        printf("Insufficient funds.\n");
    }
}

int main() {
    struct customer* head = NULL;

    // Create a few customers
    struct customer* customer1 = create_customer("John Watson", 123456, 1000.0);
    struct customer* customer2 = create_customer("Sherlock Holmes", 654321, 2000.0);
    struct customer* customer3 = create_customer("Dr. Watson", 984123, 3000.0);

    // Deposit some money
    deposit(customer1, 500.0);
    deposit(customer2, 200.0);

    // Withdraw some money
    withdraw(customer2, 300.0);
    withdraw(customer3, 100.0);

    // Transfer money
    transfer(customer1, customer2, 200.0);

    // Print the balances
    printf("Customer 1: %f\n", customer1->balance);
    printf("Customer 2: %f\n", customer2->balance);
    printf("Customer 3: %f\n", customer3->balance);

    return 0;
}