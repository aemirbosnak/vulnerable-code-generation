//Gemma-7B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void *malloc_node(int size)
{
    Node *newNode = (Node *)malloc(sizeof(Node) + size);
    newNode->data = (char *)malloc(size);
    newNode->next = NULL;

    return newNode;
}

void insert_node(Node **head, char *data, int size)
{
    if (*head == NULL)
    {
        *head = malloc_node(size);
        strcpy((*head)->data, data);
    }
    else
    {
        Node *newNode = malloc_node(size);
        strcpy(newNode->data, data);
        (*head)->next = newNode;
        *head = newNode;
    }
}

void print_nodes(Node *head)
{
    Node *current = head;
    while (current)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;

    insert_node(&head, "John Doe", 10);
    insert_node(&head, "Jane Doe", 12);
    insert_node(&head, "Peter Pan", 15);

    print_nodes(head);

    return 0;
}