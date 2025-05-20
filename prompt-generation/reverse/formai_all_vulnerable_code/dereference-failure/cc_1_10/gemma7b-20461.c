//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNT 10

typedef struct Account
{
    char name[50];
    double balance;
    struct Account* next;
} Account;

Account* account_create(char* name, double balance)
{
    Account* new_account = malloc(sizeof(Account));
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->next = NULL;

    return new_account;
}

void account_add(Account* head, char* name, double balance)
{
    Account* new_account = account_create(name, balance);

    if (head == NULL)
    {
        head = new_account;
    }
    else
    {
        Account* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_account;
    }
}

void account_print(Account* head)
{
    Account* current = head;
    while (current)
    {
        printf("%s: $%.2lf\n", current->name, current->balance);
        current = current->next;
    }
}

int main()
{
    Account* head = NULL;

    account_add(head, "John Doe", 1000);
    account_add(head, "Jane Doe", 2000);
    account_add(head, "Bill Smith", 3000);

    account_print(head);

    return 0;
}