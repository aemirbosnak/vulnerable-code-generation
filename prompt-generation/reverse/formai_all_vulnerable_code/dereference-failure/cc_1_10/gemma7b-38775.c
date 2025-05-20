//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORD_NUM 100

typedef struct Record
{
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* createRecord()
{
    Record* new_record = (Record*)malloc(sizeof(Record));
    new_record->next = NULL;
    return new_record;
}

void addRecord(Record* head, char* name, int account_number, double balance)
{
    Record* new_record = createRecord();
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }
}

void printRecords(Record* head)
{
    while (head)
    {
        printf("Name: %s, Account Number: %d, Balance: %.2lf\n", head->name, head->account_number, head->balance);
        head = head->next;
    }
}

int main()
{
    Record* head = NULL;
    addRecord(head, "John Doe", 123456, 1000.0);
    addRecord(head, "Jane Doe", 654321, 2000.0);
    addRecord(head, "Peter Pan", 789412, 3000.0);

    printRecords(head);

    return 0;
}