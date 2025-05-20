//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int accountNumber;
    char name[50];
    float balance;
} Account;

typedef struct Node {
    Account account;
    struct Node *next;
} Node;

Node *head = NULL;

void createAccount(int accountNumber, const char *name, float initialDeposit) {
    Node *newAccount = (Node *) malloc(sizeof(Node));
    newAccount->account.accountNumber = accountNumber;
    strcpy(newAccount->account.name, name);
    newAccount->account.balance = initialDeposit;
    newAccount->next = head;
    head = newAccount;
}

void displayAccounts() {
    Node *current = head;
    while (current != NULL) {
        printf("Account Number: %d\n", current->account.accountNumber);
        printf("Name: %s\n", current->account.name);
        printf("Balance: %.2f\n", current->account.balance);
        current = current->next;
    }
}

void deposit(int accountNumber, float amount) {
    Node *current = head;
    while (current != NULL) {
        if (current->account.accountNumber == accountNumber) {
            current->account.balance += amount;
            printf("Deposit successful.\n");
            return;
        }
        current = current->next;
    }
    printf("Account not found.\n");
}

void withdraw(int accountNumber, float amount) {
    Node *current = head;
    while (current != NULL) {
        if (current->account.accountNumber == accountNumber) {
            if (current->account.balance >= amount) {
                current->account.balance -= amount;
                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("Account not found.\n");
}

int main() {
    createAccount(1001, "John Doe", 500.00);
    createAccount(1002, "Jane Doe", 1000.00);

    deposit(1001, 250.00);
    deposit(1002, 300.00);

    displayAccounts();

    withdraw(1001, 150.00);
    withdraw(1002, 700.00);

    displayAccounts();

    return 0;
}