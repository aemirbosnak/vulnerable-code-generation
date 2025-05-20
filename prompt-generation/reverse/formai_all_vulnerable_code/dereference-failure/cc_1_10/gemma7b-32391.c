//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head)
{
    struct Node* current = head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* insertAtTail(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

struct Node* insertAtHead(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

int main()
{
    struct Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);

    traverse(head);

    return 0;
}