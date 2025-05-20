//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct Account {
    char name[50];
    int account_no;
    double balance;
    struct Account* next;
};

void deposit(struct Account* account, double amount) {
    account->balance += amount;
}

void withdraw(struct Account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void transfer(struct Account* account1, struct Account* account2, double amount) {
    if (amount <= account1->balance) {
        account1->balance -= amount;
        account2->balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

int main() {
    struct Account* head = NULL;
    struct Account* current = NULL;

    // Create a new account
    struct Account* new_account = (struct Account*)malloc(sizeof(struct Account));
    new_account->account_no = 12345;
    strcpy(new_account->name, "John Doe");
    new_account->balance = 1000.0;
    new_account->next = NULL;

    if (head == NULL) {
        head = new_account;
        current = new_account;
    } else {
        current->next = new_account;
        current = new_account;
    }

    // Deposit money
    deposit(current, 500.0);

    // Withdraw money
    withdraw(current, 200.0);

    // Transfer money
    transfer(current, head, 100.0);

    // Print account balance
    printf("Account balance: %f\n", current->balance);

    return 0;
}