//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void InsertAtTail(Node** head, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ((*head)->next = newNode);
    }
}

void PrintList(Node* head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    InsertAtTail(&head, 10);
    InsertAtTail(&head, 20);
    InsertAtTail(&head, 30);
    InsertAtTail(&head, 40);
    InsertAtTail(&head, 50);

    PrintList(head);

    return 0;
}