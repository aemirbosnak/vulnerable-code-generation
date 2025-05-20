//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct BankAccount
{
    char name[50];
    int account_number;
    double balance;
    struct BankAccount* next;
};

typedef struct BankAccount BankAccount;

void insert_account(BankAccount** head, char* name, int account_number, double balance)
{
    BankAccount* new_account = (BankAccount*)malloc(sizeof(BankAccount));
    strcpy(new_account->name, name);
    new_account->account_number = account_number;
    new_account->balance = balance;
    new_account->next = NULL;

    if (*head == NULL)
    {
        *head = new_account;
    }
    else
    {
        (*head)->next = new_account;
    }
}

void print_account(BankAccount* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Account Number: %d\n", head->account_number);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    BankAccount* head = NULL;

    insert_account(&head, "John Doe", 123456, 1000.0);
    insert_account(&head, "Jane Doe", 654321, 2000.0);
    insert_account(&head, "Bill Smith", 984123, 3000.0);

    print_account(head);

    return 0;
}