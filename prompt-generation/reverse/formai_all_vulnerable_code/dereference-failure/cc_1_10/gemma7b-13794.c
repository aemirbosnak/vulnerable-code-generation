//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct PersonalFinanceAccount {
    char name[MAX_NAME_LENGTH];
    int account_number;
    double balance;
    struct PersonalFinanceAccount* next;
} PersonalFinanceAccount;

PersonalFinanceAccount* createAccount(char* name, int account_number, double balance) {
    PersonalFinanceAccount* newAccount = (PersonalFinanceAccount*)malloc(sizeof(PersonalFinanceAccount));
    strcpy(newAccount->name, name);
    newAccount->account_number = account_number;
    newAccount->balance = balance;
    newAccount->next = NULL;
    return newAccount;
}

void deposit(PersonalFinanceAccount* account, double amount) {
    account->balance += amount;
}

void withdraw(PersonalFinanceAccount* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void transfer(PersonalFinanceAccount* fromAccount, PersonalFinanceAccount* toAccount, double amount) {
    if (amount <= fromAccount->balance) {
        deposit(toAccount, amount);
        withdraw(fromAccount, amount);
    } else {
        printf("Insufficient funds.\n");
    }
}

int main() {
    PersonalFinanceAccount* head = createAccount("John Doe", 123456, 1000.0);
    deposit(head, 500.0);
    withdraw(head, 200.0);
    transfer(head, createAccount("Jane Doe", 654912, 2000.0), 100.0);
    printf("Balance: %f\n", head->balance);
    return 0;
}