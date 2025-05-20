//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
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

    strcpy(newRecord->name, name);
    newRecord->amount = amount;

    if (head == NULL)
    {
        head = newRecord;
    }
    else
    {
        head->next = insertRecord(head->next, name, amount);
    }

    return head;
}

int main()
{
    PersonalFinanceRecord* head = NULL;

    insertRecord(head, "John Doe", 1000);
    insertRecord(head, "Jane Doe", 2000);
    insertRecord(head, "Bill Smith", 3000);

    PersonalFinanceRecord* currentRecord = head;

    while (currentRecord)
    {
        printf("Name: %s, Amount: %.2lf\n", currentRecord->name, currentRecord->amount);
        currentRecord = currentRecord->next;
    }

    return 0;
}