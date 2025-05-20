//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store banking records
typedef struct BankRecord
{
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new record at the end
void insert_record(BankRecord** head)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
    }
    *head = new_record;
}

// Function to search a record by account number
BankRecord* search_record(BankRecord* head, int account_no)
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

// Function to update a record balance
void update_balance(BankRecord* head, int account_no, double new_balance)
{
    BankRecord* record = search_record(head, account_no);
    if (record)
    {
        record->balance = new_balance;
    }
}

// Function to delete a record
void delete_record(BankRecord* head, int account_no)
{
    BankRecord* record = search_record(head, account_no);
    if (record)
    {
        BankRecord* previous = NULL;
        while (record->next)
        {
            previous = record;
            record = record->next;
        }
        if (previous)
        {
            previous->next = record->next;
        }
        else
        {
            head = NULL;
        }
        free(record);
    }
}

int main()
{
    BankRecord* head = NULL;
    insert_record(&head);
    insert_record(&head);
    insert_record(&head);
    update_balance(head, 1001, 1000);
    delete_record(head, 1002);
    BankRecord* record = search_record(head, 1001);
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_no);
        printf("Balance: %lf\n", record->balance);
    }
    else
    {
        printf("Record not found\n");
    }
    return 0;
}