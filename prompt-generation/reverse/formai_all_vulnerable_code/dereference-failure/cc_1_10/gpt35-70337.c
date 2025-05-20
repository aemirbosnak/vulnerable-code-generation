//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int accountNum;
    double balance;
};

void deposit(struct Customer* customer, double amount) {
    customer->balance += amount;
    printf("Deposit of %.2lf successful. New balance: %.2lf\n", amount, customer->balance);
}

void withdraw(struct Customer* customer, double amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
        printf("Withdrawal of %.2lf successful. New balance: %.2lf\n", amount, customer->balance);
    } else {
        printf("Insufficient balance for withdrawal of %.2lf\n", amount);
    }
}

void viewBalance(struct Customer* customer) {
    printf("Account balance for customer %s (account number %d): %.2lf\n", customer->name, customer->accountNum, customer->balance);
}

int main() {
    struct Customer* customer1 = malloc(sizeof(struct Customer));
    strncpy(customer1->name, "John Smith", 50);
    customer1->accountNum = 1234;
    customer1->balance = 1000.00;

    struct Customer* customer2 = malloc(sizeof(struct Customer));
    strncpy(customer2->name, "Jane Doe", 50);
    customer2->accountNum = 5678;
    customer2->balance = 500.55;

    deposit(customer1, 250.00);
    viewBalance(customer1);

    withdraw(customer2, 750.00);
    viewBalance(customer2);

    free(customer1);
    free(customer2);

    return 0;
}