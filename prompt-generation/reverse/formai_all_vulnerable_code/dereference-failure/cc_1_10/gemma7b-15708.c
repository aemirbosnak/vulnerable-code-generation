//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 25
#define MAX_DESCRIPTION_LENGTH 50

typedef struct PersonalFinanceRecord
{
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int amount;
    struct PersonalFinanceRecord* next;
} PersonalFinanceRecord;

PersonalFinanceRecord* insertRecord(PersonalFinanceRecord* head, char* name, char* description, int amount)
{
    PersonalFinanceRecord* newRecord = malloc(sizeof(PersonalFinanceRecord));

    strcpy(newRecord->name, name);
    strcpy(newRecord->description, description);
    newRecord->amount = amount;
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

void printRecords(PersonalFinanceRecord* head)
{
    PersonalFinanceRecord* currentRecord = head;

    while (currentRecord)
    {
        printf("%s - %s: %d\n", currentRecord->name, currentRecord->description, currentRecord->amount);
        currentRecord = currentRecord->next;
    }
}

int main()
{
    PersonalFinanceRecord* head = NULL;

    insertRecord(head, "Rent", "Monthly rent payment", -1000);
    insertRecord(head, "Groceries", "Food purchases", -500);
    insertRecord(head, "Entertainment", "Movie tickets and games", -200);
    insertRecord(head, "Salary", "Income from job", 2000);

    printRecords(head);

    return 0;
}