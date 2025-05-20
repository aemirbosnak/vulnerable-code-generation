//Gemma-7B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void insert(Node **head, char *data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void traverse(Node *head)
{
    while (head)
    {
        printf("%s ", head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    insert(&head, "John Doe");
    insert(&head, "Jane Doe");
    insert(&head, "Peter Pan");

    traverse(head);

    free(head);

    return 0;
}