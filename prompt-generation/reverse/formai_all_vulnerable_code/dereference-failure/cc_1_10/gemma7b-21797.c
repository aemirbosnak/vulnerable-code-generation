//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct HashTable
{
    int size;
    Node** buckets;
} HashTable;

void insert(HashTable* h, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (h->buckets[data] == NULL)
    {
        h->buckets[data] = newNode;
    }
    else
    {
        insert(h, data);
    }
}

void traverse(HashTable* h)
{
    for (int i = 0; i < h->size; i++)
    {
        Node* current = h->buckets[i];
        while (current)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}

int main()
{
    HashTable* h = malloc(sizeof(HashTable));
    h->size = MAX;
    h->buckets = (Node**)malloc(h->size * sizeof(Node*));

    insert(h, 10);
    insert(h, 20);
    insert(h, 30);
    insert(h, 40);
    insert(h, 50);

    traverse(h);

    return 0;
}