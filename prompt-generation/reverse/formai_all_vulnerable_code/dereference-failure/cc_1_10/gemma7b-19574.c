//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Record
{
    char name[50];
    int age;
    struct Record* next;
} Record;

typedef struct Index
{
    char keyword[20];
    int index_size;
    struct Index* next;
} Index;

Record* insert_record(Record* head, char* name, int age)
{
    Record* new_record = (Record*)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->age = age;
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

Index* insert_index(Index* head, char* keyword)
{
    Index* new_index = (Index*)malloc(sizeof(Index));
    strcpy(new_index->keyword, keyword);
    new_index->index_size = 0;
    new_index->next = NULL;

    if (head == NULL)
    {
        head = new_index;
    }
    else
    {
        head->next = new_index;
    }

    return head;
}

void search_records(Record* head, char* keyword)
{
    Index* index_head = head;

    while (index_head)
    {
        if (strcmp(index_head->keyword, keyword) == 0)
        {
            Record* record_head = head;

            while (record_head)
            {
                if (strstr(record_head->name, keyword) || strstr(record_head->name, keyword))
                {
                    printf("%s - %d\n", record_head->name, record_head->age);
                }
            }
        }

        index_head = index_head->next;
    }
}

int main()
{
    Record* record_head = NULL;
    Index* index_head = NULL;

    insert_record(record_head, "John Doe", 25);
    insert_record(record_head, "Jane Doe", 30);
    insert_record(record_head, "Jack Doe", 40);

    insert_index(index_head, "Doe");

    search_records(record_head, "Doe");

    return 0;
}