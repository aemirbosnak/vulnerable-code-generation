//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of customers
#define MAX_CUSTOMERS 100

// Define the maximum number of transactions per customer
#define MAX_TRANSACTIONS 100

// Define the maximum length of a customer's name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a transaction description
#define MAX_DESCRIPTION_LENGTH 100

// Define the data structure for a customer
typedef struct customer {
    char name[MAX_NAME_LENGTH];
    int account_number;
    double balance;
    struct transaction *transactions;
} customer;

// Define the data structure for a transaction
typedef struct transaction {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    struct transaction *next;
} transaction;

// Create a new customer
customer *create_customer(char *name, int account_number, double balance) {
    customer *new_customer = (customer *)malloc(sizeof(customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->transactions = NULL;
    return new_customer;
}

// Create a new transaction
transaction *create_transaction(char *description, double amount) {
    transaction *new_transaction = (transaction *)malloc(sizeof(transaction));
    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->next = NULL;
    return new_transaction;
}

// Add a transaction to a customer
void add_transaction(customer *customer, transaction *transaction) {
    if (customer->transactions == NULL) {
        customer->transactions = transaction;
    } else {
        transaction->next = customer->transactions;
        customer->transactions = transaction;
    }
}

// Print a customer's information
void print_customer(customer *customer) {
    printf("Name: %s\n", customer->name);
    printf("Account Number: %d\n", customer->account_number);
    printf("Balance: %.2f\n", customer->balance);
    printf("Transactions:\n");
    transaction *current_transaction = customer->transactions;
    while (current_transaction != NULL) {
        printf("  - %s: %.2f\n", current_transaction->description, current_transaction->amount);
        current_transaction = current_transaction->next;
    }
}

// Main function
int main() 
{
    // Create a new customer
    customer *customer1 = create_customer("John Doe", 123456789, 1000.00);

    // Create a new transaction
    transaction *transaction1 = create_transaction("Deposit", 500.00);

    // Add the transaction to the customer
    add_transaction(customer1, transaction1);

    // Print the customer's information
    print_customer(customer1);

    return 0;
}