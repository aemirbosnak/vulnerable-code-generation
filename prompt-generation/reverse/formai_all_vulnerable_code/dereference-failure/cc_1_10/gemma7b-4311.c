//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct BankRecord
{
    char name[20];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert(BankRecord**, int account_no, double balance, char* name);

void search(BankRecord* head, int account_no);

void update(BankRecord* head, int account_no, double new_balance);

void delete(BankRecord* head, int account_no);

int main()
{
    BankRecord* head = NULL;

    insert(head, 1001, 5000, "John Doe");
    insert(head, 1002, 2000, "Jane Doe");
    insert(head, 1003, 3000, "Peter Pan");

    search(head, 1002);
    update(head, 1001, 10000);
    delete(head, 1003);

    search(head, 1002);

    return 0;
}

void insert(BankRecord** head, int account_no, double balance, char* name)
{
    BankRecord* new_node = (BankRecord*)malloc(sizeof(BankRecord));

    strcpy(new_node->name, name);
    new_node->account_no = account_no;
    new_node->balance = balance;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
}

void search(BankRecord* head, int account_no)
{
    while (head)
    {
        if (head->account_no == account_no)
        {
            printf("Name: %s\n", head->name);
            printf("Account No: %d\n", head->account_no);
            printf("Balance: %.2lf\n", head->balance);
            return;
        }
        head = head->next;
    }

    printf("Account not found.\n");
}

void update(BankRecord* head, int account_no, double new_balance)
{
    while (head)
    {
        if (head->account_no == account_no)
        {
            head->balance = new_balance;
            return;
        }
        head = head->next;
    }

    printf("Account not found.\n");
}

void delete(BankRecord* head, int account_no)
{
    BankRecord* previous = NULL;
    BankRecord* current = head;

    while (current)
    {
        if (current->account_no == account_no)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Account not found.\n");
}