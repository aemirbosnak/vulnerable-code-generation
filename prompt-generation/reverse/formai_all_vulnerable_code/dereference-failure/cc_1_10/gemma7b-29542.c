//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

struct Account
{
    char name[50];
    int account_number;
    double balance;
    struct Account* next;
};

void insert_account(struct Account** head, char* name, int account_number, double balance)
{
    struct Account* new_account = (struct Account*)malloc(sizeof(struct Account));
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
        *head = new_account;
    }
}

void print_accounts(struct Account* head)
{
    while (head)
    {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main()
{
    struct Account* head = NULL;

    insert_account(&head, "John Doe", 123456, 1000.0);
    insert_account(&head, "Jane Doe", 654321, 2000.0);
    insert_account(&head, "Peter Pan", 984123, 3000.0);

    print_accounts(head);

    return 0;
}