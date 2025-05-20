//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

typedef struct Transaction {
    int id;
    char description[200];
    double amount;
    struct Transaction* next;
} Transaction;

Customer* create_customer(char* name, int account_number, double balance) {
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    strcpy(customer->name, name);
    customer->account_number = account_number;
    customer->balance = balance;
    customer->next = NULL;
    return customer;
}

Transaction* create_transaction(int id, char* description, double amount) {
    Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
    transaction->id = id;
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

void add_transaction(Transaction** head, int id, char* description, double amount) {
    Transaction* transaction = create_transaction(id, description, amount);
    if (*head == NULL) {
        *head = transaction;
    } else {
        (*head)->next = transaction;
    }
}

void print_customers(Customer* head) {
    while (head) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

void print_transactions(Transaction* head) {
    while (head) {
        printf("ID: %d, Description: %s, Amount: %.2lf\n", head->id, head->description, head->amount);
        head = head->next;
    }
}

int main() {
    Customer* head = NULL;
    Transaction* transactions = NULL;

    add_customer(&head, "John Doe", 123456, 1000.0);
    add_customer(&head, "Jane Doe", 654321, 2000.0);

    add_transaction(&transactions, 1, "Purchase of groceries", -200.0);
    add_transaction(&transactions, 2, "Payment of rent", -500.0);

    print_customers(head);
    print_transactions(transactions);

    return 0;
}