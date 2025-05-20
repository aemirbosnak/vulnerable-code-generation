//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100

struct customer {
    char name[50];
    int account_number;
    double balance;
    struct customer *next;
};

struct customer *create_customer(char *name, int account_number, double balance) {
    struct customer *new_customer = malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;
    return new_customer;
}

struct customer *add_customer(struct customer *head, char *name, int account_number, double balance) {
    struct customer *new_customer = create_customer(name, account_number, balance);
    if (head == NULL) {
        head = new_customer;
    } else {
        struct customer *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_customer;
    }
    return head;
}

void print_customer(struct customer *head) {
    struct customer *current = head;
    while (current) {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", current->name, current->account_number, current->balance);
        current = current->next;
    }
}

int main() {
    struct customer *head = NULL;
    head = add_customer(head, "John Doe", 123456, 1000.0);
    head = add_customer(head, "Jane Doe", 654321, 2000.0);
    head = add_customer(head, "Peter Pan", 984123, 3000.0);
    print_customer(head);

    return 0;
}