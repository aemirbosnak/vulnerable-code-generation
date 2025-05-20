//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TRANSACTIONS 10
#define MAX_CUSTOMERS 50

typedef struct customer {
    char name[50];
    int account_number;
    double balance;
    struct customer* next;
} customer;

typedef struct transaction {
    int account_from;
    int account_to;
    double amount;
    struct transaction* next;
} transaction;

customer* head_customer = NULL;
transaction* head_transaction = NULL;

void add_customer(char* name, int account_number, double balance) {
    customer* new_customer = (customer*)malloc(sizeof(customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = head_customer;
    head_customer = new_customer;
}

void add_transaction(int account_from, int account_to, double amount) {
    transaction* new_transaction = (transaction*)malloc(sizeof(transaction));
    new_transaction->account_from = account_from;
    new_transaction->account_to = account_to;
    new_transaction->amount = amount;
    new_transaction->next = head_transaction;
    head_transaction = new_transaction;
}

void print_customer_statement(int account_number) {
    customer* current_customer = head_customer;
    while (current_customer) {
        if (current_customer->account_number == account_number) {
            printf("Name: %s\n", current_customer->name);
            printf("Account Number: %d\n", current_customer->account_number);
            printf("Balance: %.2lf\n", current_customer->balance);
            printf("Transactions:\n");
            transaction* current_transaction = head_transaction;
            while (current_transaction) {
                if (current_transaction->account_from == account_number) {
                    printf("  To: %d, Amount: %.2lf\n", current_transaction->account_to, current_transaction->amount);
                }
            }
            break;
        }
        current_customer = current_customer->next;
    }
    if (current_customer == NULL) {
        printf("Customer not found.\n");
    }
}

int main() {
    add_customer("John Doe", 123456, 1000.0);
    add_customer("Jane Doe", 789412, 2000.0);
    add_customer("Peter Pan", 321548, 3000.0);
    add_transaction(123456, 789412, 500.0);
    add_transaction(789412, 321548, 200.0);
    add_transaction(321548, 123456, 300.0);

    print_customer_statement(123456);

    return 0;
}