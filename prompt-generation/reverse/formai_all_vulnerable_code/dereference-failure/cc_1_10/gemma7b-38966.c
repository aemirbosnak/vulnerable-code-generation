//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

struct customer {
    char name[20];
    int account_number;
    double balance;
    struct customer* next;
};

void add_customer(struct customer** head) {
    struct customer* new_customer = malloc(sizeof(struct customer));
    printf("Enter name: ");
    scanf("%s", new_customer->name);
    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);
    printf("Enter initial balance: ");
    scanf("%lf", &new_customer->balance);
    new_customer->next = NULL;
    if (*head == NULL) {
        *head = new_customer;
    } else {
        (*head)->next = new_customer;
    }
}

void display_customers(struct customer* head) {
    while (head) {
        printf("%s (%d) - Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

void transfer_money(struct customer* head) {
    int account_number_from;
    int account_number_to;
    double amount;

    printf("Enter account number from: ");
    scanf("%d", &account_number_from);
    printf("Enter account number to: ");
    scanf("%d", &account_number_to);
    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    struct customer* customer_from = NULL;
    struct customer* customer_to = NULL;

    while (head) {
        if (head->account_number == account_number_from) {
            customer_from = head;
        }
        if (head->account_number == account_number_to) {
            customer_to = head;
        }
        head = head->next;
    }

    if (customer_from && customer_to) {
        customer_from->balance -= amount;
        customer_to->balance += amount;
        printf("Transfer successful!\n");
    } else {
        printf("Account not found.\n");
    }
}

int main() {
    struct customer* head = NULL;

    add_customer(&head);
    add_customer(&head);
    add_customer(&head);

    display_customers(head);

    transfer_money(head);

    display_customers(head);

    return 0;
}