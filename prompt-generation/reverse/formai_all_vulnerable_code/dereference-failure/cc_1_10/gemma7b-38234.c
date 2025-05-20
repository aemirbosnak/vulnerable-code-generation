//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct BankRecord
{
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

void insert_record(BankRecord**, double balance, int account_no, char* name);
void display_records(BankRecord*);

int main()
{
    BankRecord* head = NULL;

    insert_record(&head, 1000.0, 1234, "John Doe");
    insert_record(&head, 500.0, 5678, "Jane Doe");
    insert_record(&head, 200.0, 9841, "Peter Pan");

    display_records(head);

    return 0;
}

void insert_record(BankRecord** head, double balance, int account_no, char* name)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));

    new_record->balance = balance;
    new_record->account_no = account_no;
    strcpy(new_record->name, name);

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
        *head = new_record;
    }
}

void display_records(BankRecord* head)
{
    while (head)
    {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}