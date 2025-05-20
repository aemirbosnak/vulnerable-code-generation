//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    insert(head, 1001, 1000, "John Doe");
    insert(head, 1002, 2000, "Jane Doe");
    insert(head, 1003, 3000, "Bill Smith");

    search(head, 1002);
    update(head, 1001, 2000);
    delete(head, 1003);

    return 0;
}

void insert(BankRecord** head, int account_no, double balance, char* name)
{
    BankRecord* new_record = malloc(sizeof(BankRecord));

    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
    }
}

void search(BankRecord* head, int account_no)
{
    BankRecord* current = head;

    while (current)
    {
        if (current->account_no == account_no)
        {
            printf("Name: %s\n", current->name);
            printf("Account No: %d\n", current->account_no);
            printf("Balance: %.2lf\n", current->balance);
            break;
        }
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Record not found.\n");
    }
}

void update(BankRecord* head, int account_no, double new_balance)
{
    BankRecord* current = head;

    while (current)
    {
        if (current->account_no == account_no)
        {
            current->balance = new_balance;
            break;
        }
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Record not found.\n");
    }
}

void delete(BankRecord* head, int account_no)
{
    BankRecord* current = head;
    BankRecord* previous = NULL;

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
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Record not found.\n");
    }
}