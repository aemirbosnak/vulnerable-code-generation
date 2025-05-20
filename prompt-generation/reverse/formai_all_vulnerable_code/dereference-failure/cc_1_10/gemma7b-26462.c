//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

typedef struct Transaction {
    char description[200];
    double amount;
    struct Transaction* next;
} Transaction;

Customer* create_customer(char* name, int account_number, double balance) {
    Customer* customer = malloc(sizeof(Customer));
    strcpy(customer->name, name);
    customer->account_number = account_number;
    customer->balance = balance;
    customer->next = NULL;
    return customer;
}

Transaction* create_transaction(char* description, double amount) {
    Transaction* transaction = malloc(sizeof(Transaction));
    strcpy(transaction->description, description);
    transaction->amount = amount;
    transaction->next = NULL;
    return transaction;
}

void add_customer(Customer** head, char* name, int account_number, double balance) {
    Customer* customer = create_customer(name, account_number, balance);
    if (*head == NULL) {
        *head = customer;
    } else {
        (*head)->next = customer;
    }
}

void add_transaction(Transaction** head, char* description, double amount) {
    Transaction* transaction = create_transaction(description, amount);
    if (*head == NULL) {
        *head = transaction;
    } else {
        (*head)->next = transaction;
    }
}

void print_customer_list(Customer* head) {
    while (head) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

void print_transaction_list(Transaction* head) {
    while (head) {
        printf("Description: %s, Amount: %.2lf\n", head->description, head->amount);
        head = head->next;
    }
}

int main() {
    Customer* customer_head = NULL;
    Transaction* transaction_head = NULL;

    add_customer(&customer_head, "John Doe", 123456, 1000.0);
    add_customer(&customer_head, "Jane Doe", 654321, 2000.0);
    add_customer(&customer_head, "Peter Pan", 321468, 3000.0);

    add_transaction(&transaction_head, "Bought a car", 500.0);
    add_transaction(&transaction_head, "Paid rent", 200.0);
    add_transaction(&transaction_head, "Transferred money to Jane Doe", 100.0);

    print_customer_list(customer_head);
    print_transaction_list(transaction_head);

    return 0;
}