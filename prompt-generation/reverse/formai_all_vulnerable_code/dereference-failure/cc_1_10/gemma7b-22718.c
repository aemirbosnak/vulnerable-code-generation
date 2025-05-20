//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 256

typedef struct Record
{
    char name[MAX_RECORD_SIZE];
    int age;
    struct Record* next;
} Record;

typedef struct Index
{
    char key[MAX_RECORD_SIZE];
    int bucket;
    struct Index* next;
} Index;

Record* insertRecord(Record* head, char* name, int age)
{
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
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

Index* insertIndex(Index* head, char* key, int bucket)
{
    Index* newIndex = (Index*)malloc(sizeof(Index));
    strcpy(newIndex->key, key);
    newIndex->bucket = bucket;
    newIndex->next = NULL;

    if (head == NULL)
    {
        head = newIndex;
    }
    else
    {
        head->next = newIndex;
    }

    return head;
}

void searchRecord(Record* head, char* name)
{
    Record* currentRecord = head;

    while (currentRecord)
    {
        if (strcmp(currentRecord->name, name) == 0)
        {
            printf("Name: %s, Age: %d\n", currentRecord->name, currentRecord->age);
            return;
        }

        currentRecord = currentRecord->next;
    }

    printf("Record not found.\n");
}

void searchIndex(Index* head, char* key)
{
    Index* currentIndex = head;

    while (currentIndex)
    {
        if (strcmp(currentIndex->key, key) == 0)
        {
            searchRecord(insertRecord(NULL, currentIndex->key, currentIndex->bucket), currentIndex->key);
            return;
        }

        currentIndex = currentIndex->next;
    }

    printf("Index key not found.\n");
}

int main()
{
    Record* head = NULL;
    Index* indexHead = NULL;

    insertRecord(head, "John Doe", 25);
    insertRecord(head, "Jane Doe", 30);
    insertRecord(head, "Jack Doe", 40);

    insertIndex(indexHead, "John Doe", 0);
    insertIndex(indexHead, "Jane Doe", 1);
    insertIndex(indexHead, "Jack Doe", 2);

    searchRecord(head, "John Doe");
    searchIndex(indexHead, "John Doe");

    return 0;
}