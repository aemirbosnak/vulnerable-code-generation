//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank account information
typedef struct BankAccount
{
    char name[50];
    int account_no;
    double balance;
    struct BankAccount *next;
} BankAccount;

// Function to insert a new account into the linked list
void insertAccount(BankAccount **head, char *name, int account_no, double balance)
{
    BankAccount *newAccount = (BankAccount *)malloc(sizeof(BankAccount));
    strcpy(newAccount->name, name);
    newAccount->account_no = account_no;
    newAccount->balance = balance;
    newAccount->next = NULL;

    if (*head == NULL)
    {
        *head = newAccount;
    }
    else
    {
        (*head)->next = newAccount;
    }
}

// Function to search for an account by account number
BankAccount *searchAccount(BankAccount *head, int account_no)
{
    while (head)
    {
        if (head->account_no == account_no)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the balance of an account
void updateBalance(BankAccount *account, double new_balance)
{
    account->balance = new_balance;
}

// Function to withdraw money from an account
void withdrawMoney(BankAccount *account, double amount)
{
    if (amount <= account->balance)
    {
        account->balance -= amount;
    }
    else
    {
        printf("Insufficient funds");
    }
}

int main()
{
    // Create a linked list of bank accounts
    BankAccount *head = NULL;

    // Insert some accounts
    insertAccount(&head, "John Doe", 123456, 1000);
    insertAccount(&head, "Jane Doe", 654321, 500);
    insertAccount(&head, "Peter Pan", 984123, 2000);

    // Search for an account by account number
    BankAccount *account = searchAccount(head, 123456);

    // Update the balance of an account
    updateBalance(account, 2000);

    // Withdraw money from an account
    withdrawMoney(account, 500);

    // Print the updated balance of the account
    printf("Balance: %f", account->balance);

    return 0;
}