//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

struct customer {
    char name[50];
    int account_number;
    double balance;
    struct customer* next;
};

struct customer* create_customer(char* name, int account_number, double balance) {
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

void add_customer(struct customer* head, char* name, int account_number, double balance) {
    struct customer* new_customer = create_customer(name, account_number, balance);
    if (head == NULL) {
        head = new_customer;
    } else {
        new_customer->next = head;
        head = new_customer;
    }
}

void print_customers(struct customer* head) {
    struct customer* current_customer = head;
    while (current_customer) {
        printf("%s (%d) - Balance: %.2lf\n", current_customer->name, current_customer->account_number, current_customer->balance);
        current_customer = current_customer->next;
    }
}

int main() {
    struct customer* head = NULL;

    add_customer(head, "John Doe", 1234, 1000.0);
    add_customer(head, "Jane Doe", 5678, 2000.0);
    add_customer(head, "Peter Pan", 9841, 3000.0);

    print_customers(head);

    return 0;
}