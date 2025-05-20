//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    int account_no;
    char type;
    int amount;
    struct Transaction* next;
};

struct Account {
    int account_no;
    int balance;
    struct Account* next;
    struct Transaction* transactions;
};

struct Account* createAccount(int account_no, int balance) {
    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    newAccount->account_no = account_no;
    newAccount->balance = balance;
    newAccount->next = NULL;
    newAccount->transactions = NULL;
    return newAccount;
}

void deposit(struct Account* account, int amount) {
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->account_no = account->account_no;
    newTransaction->type = 'D';
    newTransaction->amount = amount;
    newTransaction->next = NULL;

    if (account->transactions == NULL) {
        account->transactions = newTransaction;
    } else {
        struct Transaction* tempTransaction = account->transactions;
        while (tempTransaction->next) {
            tempTransaction = tempTransaction->next;
        }
        tempTransaction->next = newTransaction;
    }

    account->balance += amount;
}

void withdraw(struct Account* account, int amount) {
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->account_no = account->account_no;
    newTransaction->type = 'W';
    newTransaction->amount = amount;
    newTransaction->next = NULL;

    if (account->transactions == NULL) {
        account->transactions = newTransaction;
    } else {
        struct Transaction* tempTransaction = account->transactions;
        while (tempTransaction->next) {
            tempTransaction = tempTransaction->next;
        }
        tempTransaction->next = newTransaction;
    }

    account->balance -= amount;
}

int main() {
    struct Account* account = createAccount(123, 1000);
    deposit(account, 200);
    withdraw(account, 50);
    withdraw(account, 100);
    withdraw(account, 200);
    printf("Account No: %d, Balance: %d\n", account->account_no, account->balance);
    return 0;
}