//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

typedef struct HashTable
{
    Node** buckets;
    int size;
} HashTable;

void insert(HashTable* ht, char data)
{
    int hash = data % ht->size;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ht->buckets[hash];
    ht->buckets[hash] = newNode;
}

void traverse(HashTable* ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        Node* current = ht->buckets[i];
        while (current)
        {
            printf("%c ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = MAX;
    ht->buckets = malloc(MAX * sizeof(Node*));

    insert(ht, 'a');
    insert(ht, 'b');
    insert(ht, 'c');
    insert(ht, 'd');
    insert(ht, 'e');

    traverse(ht);

    free(ht->buckets);
    free(ht);

    return 0;
}