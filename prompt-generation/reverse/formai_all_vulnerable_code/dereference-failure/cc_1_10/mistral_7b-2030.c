//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float balance;
    struct account *next;
} account;

account *head = NULL;

void create_account(char *name, float amount) {
    account *new_account = (account *)malloc(sizeof(account));

    strcpy(new_account->name, name);
    new_account->balance = amount;
    new_account->next = head;
    head = new_account;
}

void display_accounts(account *ptr) {
    if (ptr != NULL) {
        printf("\nName: %s", ptr->name);
        printf("\nBalance: %.2f", ptr->balance);
        display_accounts(ptr->next);
    }
}

void deposit(char *name, float amount) {
    account *current = head;
    account *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->balance += amount;
            return;
        }
        previous = current;
        current = current->next;
    }

    // Account not found, create a new one
    create_account(name, current->balance + amount);
}

void withdraw(char *name, float amount) {
    account *current = head;
    account *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->balance >= amount) {
                current->balance -= amount;
            } else {
                printf("Insufficient balance.\n");
                return;
            }
            return;
        }
        previous = current;
        current = current->next;
    }

    // Account not found, create a new one
    create_account(name, current->balance - amount);
}

void recursive_search(account *ptr, char *name) {
    if (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            printf("\nName: %s", ptr->name);
            printf("\nBalance: %.2f", ptr->balance);
            return;
        }
        recursive_search(ptr->next, name);
    }
}

void main() {
    create_account("John Doe", 5000.00);
    create_account("Jane Doe", 3000.00);

    display_accounts(head);

    deposit("John Doe", 1000.00);
    deposit("Jane Doe", 2000.00);

    display_accounts(head);

    withdraw("John Doe", 500.00);
    withdraw("Jane Doe", 1500.00);

    display_accounts(head);

    recursive_search(head, "John Doe");
}