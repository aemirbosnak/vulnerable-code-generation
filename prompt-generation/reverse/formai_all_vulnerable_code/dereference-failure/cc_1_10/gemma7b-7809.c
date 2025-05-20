//Gemma-7B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    void **data;
    struct Node *next;
} Node;

void insert(Node **head, void *data, int size)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(size * MAX_SIZE);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }

    // Copy data into the new node
    memcpy(newNode->data, data, size);
}

void traverse(Node *head)
{
    while (head)
    {
        // Print data from the node
        printf("%s\n", (char *)head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    // Insert data into the linked list
    insert(&head, "Hello, world!", 13);
    insert(&head, "This is a string.", 18);
    insert(&head, "The quick brown fox jumps over the lazy dog.", 42);

    // Traverse the linked list
    traverse(head);

    // Free memory
    free(head);

    return 0;
}