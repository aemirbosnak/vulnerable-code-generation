//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Transaction *transactions;
} Customer;

typedef struct Transaction {
    int transaction_id;
    double amount;
    char description[200];
    struct Transaction *next;
} Transaction;

void create_customer(Customer **customer);
void add_transaction(Customer *customer, double amount, char *description);

int main() {
    Customer *customers[MAX_CUSTOMERS];
    int num_customers = 0;

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i] = NULL;
    }

    // Create a customer
    create_customer(&customers[num_customers]);
    num_customers++;

    // Add some transactions to the customer
    add_transaction(customers[0], 100, "Salary");
    add_transaction(customers[0], 50, "Shopping");

    // Print the customer's transactions
    for (Transaction *transaction = customers[0]->transactions; transaction; transaction = transaction->next) {
        printf("Transaction ID: %d, Amount: %.2lf, Description: %s\n", transaction->transaction_id, transaction->amount, transaction->description);
    }

    return 0;
}

void create_customer(Customer **customer) {
    *customer = (Customer *)malloc(sizeof(Customer));
    (*customer)->name[0] = '\0';
    (*customer)->account_number = 0;
    (*customer)->balance = 0.0;
    (*customer)->transactions = NULL;
}

void add_transaction(Customer *customer, double amount, char *description) {
    Transaction *new_transaction = (Transaction *)malloc(sizeof(Transaction));
    new_transaction->transaction_id = customer->transactions ? customer->transactions->transaction_id + 1 : 0;
    new_transaction->amount = amount;
    strcpy(new_transaction->description, description);
    new_transaction->next = customer->transactions;
    customer->transactions = new_transaction;
}