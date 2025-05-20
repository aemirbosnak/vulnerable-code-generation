//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's Banking Record System
// A rudimentary system for managing bank accounts in the style of the great detective.

// Account structure
typedef struct Account
{
    char *name;
    int accountNumber;
    double balance;
    struct Account *next;
} Account;

// Global variables
Account *head = NULL; // Head of the account linked list

// Function to create a new account
Account *createAccount(char *name, int accountNumber, double balance)
{
    Account *newAccount = (Account *)malloc(sizeof(Account));
    newAccount->name = strdup(name);
    newAccount->accountNumber = accountNumber;
    newAccount->balance = balance;
    newAccount->next = NULL;
    return newAccount;
}

// Function to add an account to the system
void addAccount(Account *account)
{
    if (head == NULL)
    {
        head = account;
    }
    else
    {
        Account *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = account;
    }
}

// Function to find an account by account number
Account *findAccount(int accountNumber)
{
    Account *current = head;
    while (current != NULL)
    {
        if (current->accountNumber == accountNumber)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to deposit money into an account
void deposit(int accountNumber, double amount)
{
    Account *account = findAccount(accountNumber);
    if (account != NULL)
    {
        account->balance += amount;
        printf("Deposited %.2f into account %d.\n", amount, accountNumber);
    }
    else
    {
        printf("Invalid account number.\n");
    }
}

// Function to withdraw money from an account
void withdraw(int accountNumber, double amount)
{
    Account *account = findAccount(accountNumber);
    if (account != NULL)
    {
        if (amount <= account->balance)
        {
            account->balance -= amount;
            printf("Withdrew %.2f from account %d.\n", amount, accountNumber);
        }
        else
        {
            printf("Insufficient funds.\n");
        }
    }
    else
    {
        printf("Invalid account number.\n");
    }
}

// Function to print the details of an account
void printAccount(Account *account)
{
    printf("Account Holder: %s\n", account->name);
    printf("Account Number: %d\n", account->accountNumber);
    printf("Balance: %.2f\n", account->balance);
}

// Function to print the details of all accounts
void printAllAccounts()
{
    Account *current = head;
    while (current != NULL)
    {
        printAccount(current);
        current = current->next;
    }
}

// Main function
int main()
{
    // Create some test accounts
    Account *account1 = createAccount("Sherlock Holmes", 12345, 1000.00);
    Account *account2 = createAccount("John Watson", 54321, 500.00);
    Account *account3 = createAccount("Mycroft Holmes", 98765, 1500.00);

    // Add the accounts to the system
    addAccount(account1);
    addAccount(account2);
    addAccount(account3);

    // Print the details of all accounts
    printf("All Accounts:\n");
    printAllAccounts();

    // Deposit money into account 1
    deposit(12345, 200.00);

    // Withdraw money from account 2
    withdraw(54321, 100.00);

    // Print the details of account 1
    printf("Account Details for Account 1:\n");
    printAccount(account1);

    // Free the memory allocated for the accounts
    free(account1->name);
    free(account1);
    free(account2->name);
    free(account2);
    free(account3->name);
    free(account3);

    return 0;
}