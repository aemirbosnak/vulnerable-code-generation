//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
};

struct Customer* insert_customer(struct Customer* head, char* name, int account_number, double balance) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    if (head == NULL) {
        head = new_customer;
    } else {
        struct Customer* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_customer;
    }

    return head;
}

void print_customer(struct Customer* head) {
    struct Customer* temp = head;
    while (temp) {
        printf("Name: %s\n", temp->name);
        printf("Account Number: %d\n", temp->account_number);
        printf("Balance: %.2lf\n", temp->balance);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    struct Customer* head = NULL;

    insert_customer(head, "John Doe", 12345, 1000.0);
    insert_customer(head, "Jane Doe", 67890, 2000.0);
    insert_customer(head, "Peter Pan", 32154, 3000.0);

    print_customer(head);

    return 0;
}