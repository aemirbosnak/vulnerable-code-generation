//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Account {
    char name[50];
    int account_no;
    double balance;
    struct Account* next;
} Account;

Account* insertAccount(Account* head, Account* newAccount)
{
    if (head == NULL)
    {
        head = newAccount;
    }
    else
    {
        Account* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newAccount;
    }
    return head;
}

void displayAccount(Account* head)
{
    Account* temp = head;
    while (temp)
    {
        printf("Name: %s\n", temp->name);
        printf("Account No: %d\n", temp->account_no);
        printf("Balance: %.2lf\n", temp->balance);
        printf("\n");
        temp = temp->next;
    }
}

int main()
{
    Account* head = NULL;

    Account* newAccount1 = (Account*)malloc(sizeof(Account));
    strcpy(newAccount1->name, "John Doe");
    newAccount1->account_no = 12345;
    newAccount1->balance = 1000.0;

    Account* newAccount2 = (Account*)malloc(sizeof(Account));
    strcpy(newAccount2->name, "Jane Doe");
    newAccount2->account_no = 65432;
    newAccount2->balance = 2000.0;

    insertAccount(head, newAccount1);
    insertAccount(head, newAccount2);

    displayAccount(head);

    return 0;
}