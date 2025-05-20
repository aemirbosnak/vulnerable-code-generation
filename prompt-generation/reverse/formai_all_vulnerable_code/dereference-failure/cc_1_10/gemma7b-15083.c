//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Account {
    char name[MAX_NAME_LENGTH];
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

void addAccount(Account* head, char* name, double balance) {
    Account* newAccount = createAccount(name, balance);
    if (head == NULL) {
        head = newAccount;
    } else {
        Account* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newAccount;
    }
}

double getAccountBalance(Account* account) {
    return account->balance;
}

void printAccounts(Account* head) {
    Account* temp = head;
    while (temp) {
        printf("%s: %f\n", temp->name, getAccountBalance(temp));
        temp = temp->next;
    }
}

int main() {
    Account* accounts = NULL;
    addAccount(accounts, "John Doe", 1000.0);
    addAccount(accounts, "Jane Doe", 2000.0);
    addAccount(accounts, "Bill Smith", 3000.0);

    printAccounts(accounts);

    return 0;
}