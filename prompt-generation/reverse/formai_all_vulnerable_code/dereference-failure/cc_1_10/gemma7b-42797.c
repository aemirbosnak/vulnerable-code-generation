//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode
{
    char *key;
    struct IndexNode *next;
} IndexNode;

IndexNode *insertIndexNode(IndexNode *head, char *key)
{
    IndexNode *newNode = (IndexNode *)malloc(sizeof(IndexNode));
    newNode->key = strdup(key);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        IndexNode *traversal = head;
        while (traversal->next != NULL)
        {
            traversal = traversal->next;
        }
        traversal->next = newNode;
    }

    return head;
}

int main()
{
    IndexNode *indexHead = NULL;

    insertIndexNode(indexHead, "John Doe");
    insertIndexNode(indexHead, "Jane Doe");
    insertIndexNode(indexHead, "Peter Pan");

    IndexNode *traversal = indexHead;
    while (traversal)
    {
        printf("%s\n", traversal->key);
        traversal = traversal->next;
    }

    return 0;
}