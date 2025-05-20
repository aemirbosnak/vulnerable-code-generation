//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node** buckets;
    int size;
    int (*compare)(const void*, const void*);
    void (*insert)(const void*);
    void (*delete)(const void*);
};

void insertIndex(struct Index* index, const void* data)
{
    int hash = index->compare(data, index->buckets);
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->buckets[hash] == NULL)
    {
        index->buckets[hash] = newNode;
    }
    else
    {
        Node* tail = index->buckets[hash];
        tail->next = newNode;
    }

    index->size++;
}

void deleteIndex(struct Index* index, const void* data)
{
    int hash = index->compare(data, index->buckets);
    Node* nodeToDelete = NULL;

    if (index->buckets[hash] != NULL)
    {
        Node* current = index->buckets[hash];
        Node* previous = NULL;

        while (current && strcmp(current->data, data) != 0)
        {
            previous = current;
            current = current->next;
        }

        if (previous)
        {
            previous->next = current->next;
        }
        else
        {
            index->buckets[hash] = current->next;
        }

        free(current);
        index->size--;
    }
}

int main()
{
    struct Index* index = malloc(sizeof(struct Index));
    index->buckets = (Node**)malloc(MAX_INDEX_SIZE * sizeof(Node*));
    index->size = 0;
    index->compare = strcmp;
    index->insert = insertIndex;
    index->delete = deleteIndex;

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Bill Smith");
    insertIndex(index, "Mary Johnson");

    deleteIndex(index, "Jane Doe");

    for (int i = 0; i < index->size; i++)
    {
        printf("%s\n", index->buckets[i]->data);
    }

    return 0;
}