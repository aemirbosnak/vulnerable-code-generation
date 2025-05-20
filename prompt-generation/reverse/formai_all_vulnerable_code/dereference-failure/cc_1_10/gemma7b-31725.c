//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct PersonalFinanceRecord
{
    char name[MAX_NAME_LENGTH];
    double amount;
    struct PersonalFinanceRecord* next;
} PersonalFinanceRecord;

PersonalFinanceRecord* insertRecord(PersonalFinanceRecord* head, char* name, double amount)
{
    PersonalFinanceRecord* newRecord = malloc(sizeof(PersonalFinanceRecord));
    newRecord->amount = amount;
    strcpy(newRecord->name, name);

    if (head == NULL)
    {
        head = newRecord;
    }
    else
    {
        newRecord->next = head;
        head = newRecord;
    }

    return head;
}

void printRecords(PersonalFinanceRecord* head)
{
    while (head)
    {
        printf("%s: %.2lf\n", head->name, head->amount);
        head = head->next;
    }
}

int main()
{
    PersonalFinanceRecord* head = NULL;

    insertRecord(head, "John Doe", 1000.0);
    insertRecord(head, "Jane Doe", 2000.0);
    insertRecord(head, "Peter Pan", 3000.0);

    printRecords(head);

    return 0;
}