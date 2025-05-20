//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CUSTOMERS 10

typedef struct Customer {
    char name[25];
    long account_number;
    double balance;
    struct Customer *next;
} Customer;

Customer *head = NULL;

void add_customer(char *name, long account_number, double balance) {
    Customer *new_customer = malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    if (head == NULL) {
        head = new_customer;
    } else {
        Customer *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_customer;
    }
}

void transfer_money(long from_account_number, long to_account_number, double amount) {
    Customer *from_customer = NULL;
    Customer *to_customer = NULL;

    for (Customer *customer = head; customer; customer) {
        if (customer->account_number == from_account_number) {
            from_customer = customer;
        }
        if (customer->account_number == to_account_number) {
            to_customer = customer;
        }
    }

    if (from_customer && to_customer) {
        double new_balance = from_customer->balance - amount;
        from_customer->balance = new_balance;
        to_customer->balance += amount;
    }
}

int main() {
    add_customer("John Doe", 123456, 1000.0);
    add_customer("Jane Doe", 789234, 500.0);
    add_customer("Bob Smith", 412369, 200.0);

    transfer_money(123456, 789234, 200.0);
    transfer_money(412369, 123456, 50.0);

    for (Customer *customer = head; customer; customer) {
        printf("Name: %s, Account Number: %ld, Balance: %lf\n", customer->name, customer->account_number, customer->balance);
    }

    return 0;
}