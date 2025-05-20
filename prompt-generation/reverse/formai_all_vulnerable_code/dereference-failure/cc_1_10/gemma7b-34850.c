//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct BankRecord
{
    char name[20];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert(BankRecord**, int account_no, double balance, char* name);
void display(BankRecord*);
void search(BankRecord*, int account_no);

int main()
{
    BankRecord* head = NULL;
    insert(head, 1234, 5000, "John Doe");
    insert(head, 5678, 2000, "Jane Doe");
    insert(head, 9123, 3000, "Peter Pan");

    display(head);

    search(head, 5678);

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

void display(BankRecord* head)
{
    while (head)
    {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}

void search(BankRecord* head, int account_no)
{
    while (head)
    {
        if (head->account_no == account_no)
        {
            printf("Name: %s, Balance: %.2lf\n", head->name, head->balance);
            break;
        }
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Account not found.\n");
    }
}