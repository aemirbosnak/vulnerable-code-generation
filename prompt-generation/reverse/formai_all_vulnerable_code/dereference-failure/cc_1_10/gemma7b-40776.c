//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100

typedef struct Customer {
    char name[50];
    int account_number;
    double balance;
    struct Customer* next;
} Customer;

void insert_customer(Customer** head) {
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    printf("Enter customer name: ");
    scanf("%s", new_customer->name);
    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);
    printf("Enter initial balance: ");
    scanf("%lf", &new_customer->balance);

    if (*head == NULL) {
        *head = new_customer;
    } else {
        (*head)->next = new_customer;
    }
    *head = new_customer;
}

void search_customer(Customer* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            printf("Name: %s\n", head->name);
            printf("Account Number: %d\n", head->account_number);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }
    printf("Customer not found.\n");
}

void update_balance(Customer* head, int account_number, double new_balance) {
    while (head) {
        if (head->account_number == account_number) {
            head->balance = new_balance;
            return;
        }
        head = head->next;
    }
    printf("Customer not found.\n");
}

void delete_customer(Customer* head, int account_number) {
    Customer* prev = NULL;
    Customer* current = head;

    while (current) {
        if (current->account_number == account_number) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Customer not found.\n");
}

int main() {
    Customer* head = NULL;

    // Insert customers
    insert_customer(&head);
    insert_customer(&head);
    insert_customer(&head);

    // Search customer
    search_customer(head, 1234);

    // Update balance
    update_balance(head, 1234, 1000.0);

    // Delete customer
    delete_customer(head, 1234);

    return 0;
}