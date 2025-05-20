//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

void create_customer(Customer**, char*, int, double);
void deposit(Customer*, double);
void withdraw(Customer*, double);
void transfer(Customer*, Customer*, double);
void print_account_statement(Customer*);

int main() {
    Customer* head = NULL;
    char name[50];
    int account_number;
    double balance;

    // Create a new customer
    create_customer(&head, "John Doe", 123456, 1000);
    create_customer(&head, "Jane Doe", 789234, 2000);
    create_customer(&head, "Bill Smith", 543216, 3000);

    // Deposit money
    deposit(head, 500);
    deposit(head, 200);

    // Withdraw money
    withdraw(head, 300);
    withdraw(head, 100);

    // Transfer money
    transfer(head, head->next, 200);

    // Print account statement
    print_account_statement(head);

    return 0;
}

void create_customer(Customer** head, char* name, int account_number, double balance) {
    Customer* new_customer = malloc(sizeof(Customer));

    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    if (*head == NULL) {
        *head = new_customer;
    } else {
        (*head)->next = new_customer;
    }
}

void deposit(Customer* head, double amount) {
    Customer* current_customer = head;

    while (current_customer) {
        if (strcmp(current_customer->name, "John Doe") == 0) {
            current_customer->balance += amount;
            break;
        }
        current_customer = current_customer->next;
    }
}

void withdraw(Customer* head, double amount) {
    Customer* current_customer = head;

    while (current_customer) {
        if (strcmp(current_customer->name, "Jane Doe") == 0) {
            current_customer->balance -= amount;
            break;
        }
        current_customer = current_customer->next;
    }
}

void transfer(Customer* head, Customer* to_customer, double amount) {
    Customer* current_customer = head;

    while (current_customer) {
        if (strcmp(current_customer->name, "Bill Smith") == 0) {
            current_customer->balance -= amount;
            break;
        }
        current_customer = current_customer->next;
    }

    while (current_customer) {
        if (strcmp(current_customer->name, to_customer->name) == 0) {
            current_customer->balance += amount;
            break;
        }
        current_customer = current_customer->next;
    }
}

void print_account_statement(Customer* head) {
    Customer* current_customer = head;

    while (current_customer) {
        printf("Name: %s\n", current_customer->name);
        printf("Account Number: %d\n", current_customer->account_number);
        printf("Balance: %.2lf\n\n", current_customer->balance);
        current_customer = current_customer->next;
    }
}