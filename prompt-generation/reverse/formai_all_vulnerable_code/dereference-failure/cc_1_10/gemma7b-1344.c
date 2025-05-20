//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 100

typedef struct BankRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankRecord* next;
} BankRecord;

BankRecord* insertRecord(BankRecord* head, char* name, int account_number, double balance)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }

    return head;
}

void printRecords(BankRecord* head)
{
    BankRecord* current_record = head;

    while (current_record)
    {
        printf("Name: %s\n", current_record->name);
        printf("Account Number: %d\n", current_record->account_number);
        printf("Balance: %.2lf\n", current_record->balance);
        printf("\n");
        current_record = current_record->next;
    }
}

int main()
{
    BankRecord* head = NULL;

    insertRecord(head, "John Doe", 123456, 1000.0);
    insertRecord(head, "Jane Doe", 654912, 2000.0);
    insertRecord(head, "Peter Pan", 321468, 3000.0);

    printRecords(head);

    return 0;
}