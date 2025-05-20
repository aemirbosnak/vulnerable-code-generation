//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold customer information
struct Customer {
    char name[50];
    int age;
    float balance;
};

// Struct to hold bank account information
struct Account {
    int accNum;
    char owner[50];
    float balance;
};

// Function to create a new customer account
struct Customer* createCustomer(char* name, int age, float balance) {
    struct Customer* customer = (struct Customer*) malloc(sizeof(struct Customer));
    strcpy(customer->name, name);
    customer->age = age;
    customer->balance = balance;
    return customer;
}

// Function to create a new bank account
struct Account* createAccount(char* owner, float balance) {
    struct Account* account = (struct Account*) malloc(sizeof(struct Account));
    strcpy(account->owner, owner);
    account->balance = balance;
    account->accNum = 0;
    return account;
}

// Function to display customer information
void displayCustomer(struct Customer* customer) {
    printf("Name: %s\n", customer->name);
    printf("Age: %d\n", customer->age);
    printf("Balance: $%.2f\n", customer->balance);
}

// Function to deposit money into an account
void deposit(struct Account* account, float amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct Account* account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to display bank account information
void displayAccount(struct Account* account) {
    printf("Account Number: %d\n", account->accNum);
    printf("Owner: %s\n", account->owner);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
    struct Customer* customer1 = createCustomer("John Doe", 25, 1000);
    displayCustomer(customer1);

    struct Account* account1 = createAccount("John Doe", 1000);
    displayAccount(account1);

    deposit(account1, 500);
    displayAccount(account1);

    withdraw(account1, 1000);
    displayAccount(account1);

    free(customer1);
    free(account1);

    return 0;
}