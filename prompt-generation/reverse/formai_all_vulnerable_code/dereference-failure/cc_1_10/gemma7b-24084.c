//Gemma-7B DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    head = insertAtTail(head, 50);

    Node* current = head;

    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}