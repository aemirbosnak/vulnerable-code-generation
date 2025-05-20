//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 10

typedef struct Node {
    char name[20];
    int index;
    struct Node* next;
} Node;

struct Index {
    char key[MAX_INDEX][20];
    int key_size;
    struct Node* head;
};

void insert(struct Index* index, char* name, int index_no)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->index = index_no;
    newNode->next = NULL;

    if (index->head == NULL)
    {
        index->head = newNode;
    }
    else
    {
        index->head->next = newNode;
    }
    index->key_size++;
}

int search(struct Index* index, char* name)
{
    struct Node* current = index->head;
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->index;
        }
        current = current->next;
    }
    return -1;
}

int main()
{
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->key_size = 0;
    index->head = NULL;

    insert(index, "John Doe", 1);
    insert(index, "Jane Doe", 2);
    insert(index, "Peter Pan", 3);

    int result = search(index, "Jane Doe");
    if (result != -1)
    {
        printf("Index of Jane Doe: %d\n", result);
    }
    else
    {
        printf("Name not found.\n");
    }

    return 0;
}