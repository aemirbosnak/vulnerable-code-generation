//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void insert(Node* head, int data)
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
}

void printList(Node* head)
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

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    printList(head);

    return 0;
}