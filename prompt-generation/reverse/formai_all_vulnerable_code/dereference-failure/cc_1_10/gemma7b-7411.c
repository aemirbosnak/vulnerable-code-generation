//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Account
{
    char name[MAX_NAME_LENGTH];
    double balance;
    struct Account* next;
} Account;

Account* createAccount(char* name, double balance)
{
    Account* newAccount = malloc(sizeof(Account));
    strcpy(newAccount->name, name);
    newAccount->balance = balance;
    newAccount->next = NULL;

    return newAccount;
}

void deposit(Account* account, double amount)
{
    account->balance += amount;
}

void withdraw(Account* account, double amount)
{
    if (amount <= account->balance)
    {
        account->balance -= amount;
    }
    else
    {
        printf("Insufficient funds.\n");
    }
}

int main()
{
    Account* head = NULL;

    // Create a few accounts
    Account* account1 = createAccount("John Doe", 1000);
    Account* account2 = createAccount("Jane Doe", 2000);
    Account* account3 = createAccount("Mr. Smith", 3000);

    // Deposit some money
    deposit(account1, 500);
    deposit(account2, 200);

    // Withdraw some money
    withdraw(account2, 300);
    withdraw(account3, 1000);

    // Print the account balances
    printf("Account 1: $%f\n", account1->balance);
    printf("Account 2: $%f\n", account2->balance);
    printf("Account 3: $%f\n", account3->balance);

    return 0;
}