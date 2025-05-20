//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 255

typedef struct Record
{
    char name[MAX_NAME_LENGTH];
    int age;
    struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, int age)
{
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL)
    {
        return newRecord;
    }

    head->next = newRecord;
    return head;
}

int searchRecord(Record* head, char* name)
{
    Record* currentRecord = head;

    while (currentRecord)
    {
        if (strcmp(currentRecord->name, name) == 0)
        {
            return 1;
        }

        currentRecord = currentRecord->next;
    }

    return 0;
}

int main()
{
    Record* head = NULL;
    head = insertRecord(head, "John Doe", 25);
    head = insertRecord(head, "Jane Doe", 30);
    head = insertRecord(head, "Peter Pan", 12);

    if (searchRecord(head, "Jane Doe") == 1)
    {
        printf("Jane Doe found!\n");
    }

    return 0;
}