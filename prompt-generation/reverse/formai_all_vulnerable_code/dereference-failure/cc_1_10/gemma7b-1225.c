//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node
{
    char data[MAX_SIZE];
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data;
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

void traverse(Node* head)
{
    while (head)
    {
        printf("%c ", head->data[0]);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'd');

    traverse(head);

    return 0;
}