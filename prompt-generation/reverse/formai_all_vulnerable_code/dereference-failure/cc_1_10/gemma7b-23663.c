//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct PF_Account
{
    char name[MAX];
    int account_no;
    double balance;
    struct PF_Account* next;
} PF_Account;

void insert_account(PF_Account**, double balance, char* name, int account_no);

int main()
{
    PF_Account* head = NULL;

    insert_account(&head, 2000, "John Doe", 1234);
    insert_account(&head, 1500, "Jane Doe", 5678);
    insert_account(&head, 1000, "Peter Pan", 9841);

    PF_Account* current = head;

    while (current)
    {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", current->name, current->account_no, current->balance);
        current = current->next;
    }

    return 0;
}

void insert_account(PF_Account** head, double balance, char* name, int account_no)
{
    PF_Account* new_account = (PF_Account*)malloc(sizeof(PF_Account));

    new_account->balance = balance;
    strcpy(new_account->name, name);
    new_account->account_no = account_no;
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