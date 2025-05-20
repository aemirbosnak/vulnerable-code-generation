//Gemma-7B DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node
{
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

int main()
{
    Node *head = NULL;

    // Insert data into the linked list
    insert(&head, "John Doe");
    insert(&head, "Jane Doe");
    insert(&head, "Peter Pan");
    insert(&head, "Captain Hook");

    // Traverse the linked list and print the data
    Node *curr = head;
    while (curr)
    {
        printf("%s ", curr->data);
        curr = curr->next;
    }

    // Free the memory allocated for the nodes
    free(head);

    return 0;
}