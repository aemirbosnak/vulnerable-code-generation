//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

Customer* CreateCustomer(char* name, int account_number, double balance) {
    Customer* new_customer = malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

void AddCustomer(Customer* head, char* name, int account_number, double balance) {
    Customer* new_customer = CreateCustomer(name, account_number, balance);
    if (head == NULL) {
        head = new_customer;
    } else {
        new_customer->next = head;
        head = new_customer;
    }
}

void PrintCustomers(Customer* head) {
    Customer* current_customer = head;
    while (current_customer) {
        printf("%s, %d, %f\n", current_customer->name, current_customer->account_number, current_customer->balance);
        current_customer = current_customer->next;
    }
}

int main() {
    Customer* head = NULL;

    AddCustomer(head, "John Doe", 123456, 1000.0);
    AddCustomer(head, "Jane Doe", 654912, 2000.0);
    AddCustomer(head, "Peter Pan", 321549, 3000.0);

    PrintCustomers(head);

    return 0;
}