//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNT_NUMBER 10

typedef struct Account
{
    int accountNumber;
    char accountName[20];
    double balance;
    struct Account* nextAccount;
} Account;

Account* createAccount(int accountNumber, char* accountName, double balance)
{
    Account* newAccount = (Account*)malloc(sizeof(Account));
    newAccount->accountNumber = accountNumber;
    strcpy(newAccount->accountName, accountName);
    newAccount->balance = balance;
    newAccount->nextAccount = NULL;
    return newAccount;
}

void printAccount(Account* account)
{
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Name: %s\n", account->accountName);
    printf("Balance: %.2lf\n", account->balance);
    printf("\n");
}

int main()
{
    Account* headAccount = NULL;

    // Create a few accounts
    Account* newAccount1 = createAccount(1001, "John Doe", 1000);
    Account* newAccount2 = createAccount(1002, "Jane Doe", 2000);
    Account* newAccount3 = createAccount(1003, "Peter Pan", 3000);

    // Link the accounts together
    newAccount1->nextAccount = newAccount2;
    newAccount2->nextAccount = newAccount3;

    // Print the accounts
    printAccount(newAccount1);
    printAccount(newAccount2);
    printAccount(newAccount3);

    return 0;
}