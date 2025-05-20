//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void display(Node* head)
{
    Node* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtTail(Node* head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* last = head;
        while (last->next)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

int main()
{
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    display(head);

    return 0;
}