//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 10

struct customer {
    char name[50];
    int account_number;
    double balance;
    struct customer* next;
};

struct customer* head = NULL;

void add_customer(char* name, int account_number, double balance) {
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    new_customer->account_number = account_number;
    new_customer->balance = balance;
    new_customer->next = NULL;

    if (head == NULL) {
        head = new_customer;
    } else {
        struct customer* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_customer;
    }
}

void print_customer(int account_number) {
    struct customer* temp = head;
    while (temp) {
        if (temp->account_number == account_number) {
            printf("Name: %s\n", temp->name);
            printf("Account Number: %d\n", temp->account_number);
            printf("Balance: %.2lf\n", temp->balance);
            break;
        }
        temp = temp->next;
    }
}

int main() {
    add_customer("John Doe", 123456, 1000.0);
    add_customer("Jane Doe", 654321, 2000.0);
    add_customer("Peter Pan", 784632, 3000.0);

    print_customer(123456);

    return 0;
}