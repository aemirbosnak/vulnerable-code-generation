//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORD_SIZE 100

typedef struct BankingRecord
{
    char name[50];
    int account_number;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

BankingRecord* insertRecord(BankingRecord* head, char* name, int account_number, double balance)
{
    BankingRecord* newRecord = (BankingRecord*)malloc(sizeof(BankingRecord));
    strcpy(newRecord->name, name);
    newRecord->account_number = account_number;
    newRecord->balance = balance;
    newRecord->next = NULL;

    if (head == NULL)
    {
        head = newRecord;
    }
    else
    {
        head->next = newRecord;
    }

    return head;
}

BankingRecord* searchRecord(BankingRecord* head, int account_number)
{
    BankingRecord* currentRecord = head;

    while (currentRecord)
    {
        if (currentRecord->account_number == account_number)
        {
            return currentRecord;
        }
        currentRecord = currentRecord->next;
    }

    return NULL;
}

void updateRecord(BankingRecord* record, double new_balance)
{
    record->balance = new_balance;
}

void deleteRecord(BankingRecord* head, int account_number)
{
    BankingRecord* previousRecord = NULL;
    BankingRecord* currentRecord = head;

    while (currentRecord)
    {
        if (currentRecord->account_number == account_number)
        {
            if (previousRecord)
            {
                previousRecord->next = currentRecord->next;
            }
            else
            {
                head = currentRecord->next;
            }
            free(currentRecord);
            return;
        }
        previousRecord = currentRecord;
        currentRecord = currentRecord->next;
    }

    return;
}

int main()
{
    BankingRecord* head = NULL;

    insertRecord(head, "John Doe", 123456, 1000.0);
    insertRecord(head, "Jane Doe", 654321, 2000.0);
    insertRecord(head, "Peter Pan", 984123, 3000.0);

    BankingRecord* record = searchRecord(head, 123456);
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    updateRecord(record, 1500.0);

    record = searchRecord(head, 123456);
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    deleteRecord(head, 654321);

    record = searchRecord(head, 654321);
    if (record)
    {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %.2lf\n", record->balance);
    }

    return 0;
}