//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* insertAtTail(Node* head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void traverse(Node* head)
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

    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);
    head = insertAtTail(head, 50);

    traverse(head);

    return 0;
}