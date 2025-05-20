//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: configurable
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

Customer* head = NULL;

void add_customer(char* name, int account_number, double balance) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    if (head == NULL) {
        head = new_customer;
    } else {
        Customer* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_customer;
    }
}

void print_customer(int account_number) {
    Customer* current_customer = head;
    while (current_customer) {
        if (current_customer->account_number == account_number) {
            printf("Name: %s\n", current_customer->name);
            printf("Account Number: %d\n", current_customer->account_number);
            printf("Balance: %.2lf\n", current_customer->balance);
            break;
        }
        current_customer = current_customer->next;
    }

    if (current_customer == NULL) {
        printf("No customer found for that account number.\n");
    }
}

int main() {
    add_customer("John Doe", 12345, 1000.0);
    add_customer("Jane Doe", 67890, 2000.0);
    add_customer("Peter Pan", 34569, 3000.0);

    print_customer(12345);
    print_customer(67890);
    print_customer(34569);

    return 0;
}