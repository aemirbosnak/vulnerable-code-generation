//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ACCOUNT_NUMBER_LENGTH 20

typedef struct Account {
    char name[MAX_NAME_LENGTH];
    int account_number;
    double balance;
    struct Account* next;
} Account;

Account* createAccount(char* name, int account_number, double balance) {
    Account* newAccount = malloc(sizeof(Account));

    strcpy(newAccount->name, name);
    newAccount->account_number = account_number;
    newAccount->balance = balance;
    newAccount->next = NULL;

    return newAccount;
}

void printAccount(Account* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2lf\n", account->balance);
}

int main() {
    Account* head = NULL;

    // Create a few accounts
    Account* account1 = createAccount("John Doe", 123456, 1000.0);
    Account* account2 = createAccount("Jane Doe", 654321, 2000.0);
    Account* account3 = createAccount("Bob Smith", 345692, 3000.0);

    // Link the accounts together
    account1->next = account2;
    account2->next = account3;

    // Print the accounts
    printAccount(account1);
    printAccount(account2);
    printAccount(account3);

    return 0;
}