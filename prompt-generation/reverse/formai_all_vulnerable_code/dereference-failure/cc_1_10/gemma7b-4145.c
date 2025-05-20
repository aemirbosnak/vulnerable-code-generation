//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertAtTail(Node** head, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ((*head)->prev)->next = newNode;
        newNode->prev = (*head)->prev;
    }
}

void traverse(Node* head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    traverse(head);

    return 0;
}