//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNT_NUM 10

typedef struct Account {
    char name[20];
    double balance;
    struct Account* next;
} Account;

Account* createAccount(char* name, double balance) {
    Account* newAccount = malloc(sizeof(Account));
    strcpy(newAccount->name, name);
    newAccount->balance = balance;
    newAccount->next = NULL;
    return newAccount;
}

void deposit(Account* account, double amount) {
    account->balance += amount;
}

void withdraw(Account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void printAccounts(Account* account) {
    while (account) {
        printf("Account name: %s, Balance: %.2lf\n", account->name, account->balance);
        account = account->next;
    }
}

int main() {
    Account* head = NULL;

    // Create some accounts
    head = createAccount("John Doe", 1000.0);
    createAccount("Jane Doe", 2000.0);
    createAccount("Bob Smith", 3000.0);

    // Deposit some money
    deposit(head, 500.0);
    deposit(head->next, 200.0);

    // Withdraw some money
    withdraw(head, 300.0);
    withdraw(head->next, 100.0);

    // Print the accounts
    printAccounts(head);

    return 0;
}