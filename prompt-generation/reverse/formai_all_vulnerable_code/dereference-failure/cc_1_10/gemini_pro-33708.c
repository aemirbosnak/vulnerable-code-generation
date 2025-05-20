//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char name[50];
    char account_number[20];
    double balance;
} account;

typedef struct node {
    account data;
    struct node *next;
} node;

node *head = NULL;

void insert_account(account acc) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = acc;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_account(char *account_number) {
    node *current = head;
    node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.account_number, account_number) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Account not found.\n");
}

account *get_account(char *account_number) {
    node *current = head;

    while (current != NULL) {
        if (strcmp(current->data.account_number, account_number) == 0) {
            return &current->data;
        }
        current = current->next;
    }

    return NULL;
}

void deposit(char *account_number, double amount) {
    account *acc = get_account(account_number);

    if (acc == NULL) {
        printf("Account not found.\n");
        return;
    }

    acc->balance += amount;
    printf("Deposited %.2lf into account %s.\n", amount, acc->account_number);
}

void withdraw(char *account_number, double amount) {
    account *acc = get_account(account_number);

    if (acc == NULL) {
        printf("Account not found.\n");
        return;
    }

    if (acc->balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }

    acc->balance -= amount;
    printf("Withdrew %.2lf from account %s.\n", amount, acc->account_number);
}

void print_accounts() {
    node *current = head;

    while (current != NULL) {
        printf("%s %s %.2lf\n", current->data.name, current->data.account_number, current->data.balance);
        current = current->next;
    }
}

int main() {
    // Create some accounts
    account acc1 = {"John Doe", "1234567890", 1000.0};
    account acc2 = {"Jane Doe", "0987654321", 2000.0};
    account acc3 = {"Bob Smith", "1122334455", 3000.0};

    // Insert the accounts into the linked list
    insert_account(acc1);
    insert_account(acc2);
    insert_account(acc3);

    // Print the accounts
    print_accounts();

    // Deposit some money into account 1234567890
    deposit("1234567890", 500.0);

    // Withdraw some money from account 0987654321
    withdraw("0987654321", 300.0);

    // Delete account 1122334455
    delete_account("1122334455");

    // Print the accounts again
    print_accounts();

    return 0;
}