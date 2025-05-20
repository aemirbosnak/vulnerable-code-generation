//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for customers
struct Customer {
    char name[50];
    char address[50];
    int balance;
};

// Function to create a new customer
struct Customer* createCustomer(char name[50], char address[50], int balance) {
    struct Customer* customer = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy(customer->name, name);
    strcpy(customer->address, address);
    customer->balance = balance;
    return customer;
}

// Function to display a customer's information
void displayCustomer(struct Customer* customer) {
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Balance: %d\n", customer->balance);
}

// Function to add money to a customer's account
void addMoney(struct Customer* customer, int amount) {
    customer->balance += amount;
}

// Function to remove money from a customer's account
void removeMoney(struct Customer* customer, int amount) {
    customer->balance -= amount;
}

// Function to transfer money between customers
void transferMoney(struct Customer* fromCustomer, struct Customer* toCustomer, int amount) {
    fromCustomer->balance -= amount;
    toCustomer->balance += amount;
}

// Function to deduct money from a customer's account
void deductMoney(struct Customer* customer, int amount) {
    customer->balance -= amount;
}

int main() {
    srand(time(NULL));

    // Creating customers
    struct Customer* customer1 = createCustomer("John Doe", "123 Main St", 100);
    struct Customer* customer2 = createCustomer("Jane Smith", "456 Elm St", 200);
    struct Customer* customer3 = createCustomer("Bob Johnson", "789 Oak St", 300);

    // Adding money to customer1's account
    addMoney(customer1, 50);

    // Removing money from customer2's account
    removeMoney(customer2, 50);

    // Transferring money from customer1 to customer3
    transferMoney(customer1, customer3, 100);

    // Deducting money from customer2's account
    deductMoney(customer2, 50);

    // Displaying customer information
    displayCustomer(customer1);
    displayCustomer(customer2);
    displayCustomer(customer3);

    return 0;
}