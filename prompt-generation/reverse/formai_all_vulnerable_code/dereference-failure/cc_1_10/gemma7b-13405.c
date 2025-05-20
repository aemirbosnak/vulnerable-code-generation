//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[255];
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
    newNode->next = index->buckets[hash] = newNode;
    index->buckets[hash] = newNode;
    index->size++;
}

void deleteIndex(struct Index* index, const void* data)
{
    int hash = index->compare(data, index->buckets);
    Node* prev = NULL;
    Node* current = index->buckets[hash];

    while (current && strcmp(current->data, data) != 0)
    {
        prev = current;
        current = current->next;
    }

    if (current)
    {
        if (prev)
        {
            prev->next = current->next;
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
    insertIndex(index, "Peter Pan");

    deleteIndex(index, "Jane Doe");

    for (Node* current = index->buckets[0]; current; current = current->next)
    {
        printf("%s\n", current->data);
    }

    return 0;
}