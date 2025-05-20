//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record
{
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* createRecord(char* name, int account_number, double balance)
{
    Record* newRecord = malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->account_number = account_number;
    newRecord->balance = balance;
    newRecord->next = NULL;

    return newRecord;
}

void addToRecords(Record** head, char* name, int account_number, double balance)
{
    Record* newRecord = createRecord(name, account_number, balance);

    if (*head == NULL)
    {
        *head = newRecord;
    }
    else
    {
        (*head)->next = newRecord;
    }
}

void displayRecords(Record* head)
{
    while (head)
    {
        printf("%s, %d, %f\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main()
{
    Record* records = NULL;

    addToRecords(&records, "John Doe", 12345, 1000.0);
    addToRecords(&records, "Jane Doe", 67890, 2000.0);
    addToRecords(&records, "Bob Smith", 34126, 3000.0);

    displayRecords(records);

    return 0;
}