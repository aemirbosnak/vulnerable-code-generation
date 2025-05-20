//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

typedef struct Transaction {
    int transaction_id;
    char description[200];
    double amount;
    struct Transaction* next;
} Transaction;

Customer* create_customer(char* name, int account_number, double balance) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

Transaction* create_transaction(int transaction_id, char* description, double amount) {
    Transaction* new_transaction = (Transaction*)malloc(sizeof(Transaction));
    new_transaction->transaction_id = transaction_id;
    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->next = NULL;
    return new_transaction;
}

void deposit(Customer* customer, double amount) {
    customer->balance += amount;
}

void withdraw(Customer* customer, double amount) {
    if (amount <= customer->balance) {
        customer->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void transfer(Customer* from_customer, Customer* to_customer, double amount) {
    if (amount <= from_customer->balance) {
        deposit(to_customer, amount);
        withdraw(from_customer, amount);
    } else {
        printf("Insufficient funds.\n");
    }
}

void print_customer_list(Customer* customer) {
    while (customer) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", customer->name, customer->account_number, customer->balance);
        customer = customer->next;
    }
}

void print_transaction_list(Transaction* transaction) {
    while (transaction) {
        printf("Transaction ID: %d, Description: %s, Amount: %.2lf\n", transaction->transaction_id, transaction->description, transaction->amount);
        transaction = transaction->next;
    }
}

int main() {
    Customer* head_customer = NULL;
    Transaction* head_transaction = NULL;

    // Create some customers
    Customer* customer1 = create_customer("John Doe", 123456, 1000);
    Customer* customer2 = create_customer("Jane Doe", 654321, 2000);
    Customer* customer3 = create_customer("Peter Pan", 984123, 3000);

    // Create some transactions
    Transaction* transaction1 = create_transaction(1, "Deposit", 200);
    Transaction* transaction2 = create_transaction(2, "Withdrawal", 50);
    Transaction* transaction3 = create_transaction(3, "Transfer", 100);

    // Add customers and transactions to the system
    customer1->next = customer2;
    customer2->next = customer3;
    transaction1->next = transaction2;
    transaction2->next = transaction3;

    // Print customer list
    print_customer_list(head_customer);

    // Print transaction list
    print_transaction_list(head_transaction);

    return 0;
}