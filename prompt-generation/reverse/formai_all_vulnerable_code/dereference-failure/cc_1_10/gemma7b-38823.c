//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNT_NUMBERS 10

typedef struct Account {
    char name[20];
    int account_number;
    double balance;
    struct Account* next;
} Account;

Account* createAccount(char* name, int account_number, double balance) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    strcpy(newAccount->name, name);
    newAccount->account_number = account_number;
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
        printf("Insufficient funds!");
    }
}

void transfer(Account* account1, Account* account2, double amount) {
    if (amount <= account1->balance) {
        deposit(account2, amount);
        withdraw(account1, amount);
    } else {
        printf("Insufficient funds!");
    }
}

int main() {
    Account* head = NULL;

    // Create a few accounts
    Account* account1 = createAccount("John Doe", 123456, 1000.0);
    Account* account2 = createAccount("Jane Doe", 654321, 2000.0);
    Account* account3 = createAccount("Peter Pan", 984623, 3000.0);

    // Deposit some money
    deposit(account1, 200.0);
    deposit(account2, 300.0);

    // Withdraw some money
    withdraw(account2, 100.0);
    withdraw(account1, 50.0);

    // Transfer some money
    transfer(account1, account2, 150.0);

    // Print the account balances
    printf("Account 1 balance: $%.2lf\n", account1->balance);
    printf("Account 2 balance: $%.2lf\n", account2->balance);
    printf("Account 3 balance: $%.2lf\n", account3->balance);

    return 0;
}