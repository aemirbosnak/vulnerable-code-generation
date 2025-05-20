//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LEN 50
#define MAX_TRANSACTIONS 10
#define MAX_TRANSACTION_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int accountNumber;
    double balance;
    struct account *next;
} account;

typedef struct {
    int transactionNumber;
    char description[MAX_TRANSACTION_DESC_LEN];
    double amount;
    account *account;
    struct transaction *next;
} transaction;

account *accountHead = NULL;
transaction *transactionHead = NULL;

void createAccount(char *name, int accountNumber) {
    account *newAccount = (account *) malloc(sizeof(account));

    strcpy(newAccount->name, name);
    newAccount->accountNumber = accountNumber;
    newAccount->balance = 0.0;
    newAccount->next = accountHead;

    accountHead = newAccount;
}

void addTransaction(account *account, char *description, double amount) {
    transaction *newTransaction = (transaction *) malloc(sizeof(transaction));

    newTransaction->transactionNumber = (transactionHead ? transactionHead->transactionNumber + 1 : 1);
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->account = account;
    newTransaction->next = transactionHead;

    transactionHead = newTransaction;
}

void printAccount(account *account) {
    printf("\nAccount Number: %d", account->accountNumber);
    printf("\nAccount Holder: %s", account->name);
    printf("\nBalance: $%.2f", account->balance);

    transaction *transaction = transactionHead;

    printf("\nTransactions:\n");

    while (transaction) {
        printf("\n   Transaction %d: %s", transaction->transactionNumber, transaction->description);
        printf("\n      Amount: $%.2f", transaction->amount);
        account->balance += transaction->amount;

        transaction = transaction->next;
    }
}

int main() {
    createAccount("John Doe", 12345678);
    createAccount("Jane Doe", 98765432);

    addTransaction(accountHead, "Salary", 1500.0);
    addTransaction(accountHead, "Rent", -800.0);

    addTransaction(accountHead->next, "Groceries", -200.0);
    addTransaction(accountHead->next, "Utility Bill", -150.0);

    account *currentAccount = accountHead;

    while (currentAccount) {
        printAccount(currentAccount);
        currentAccount = currentAccount->next;
    }

    return 0;
}