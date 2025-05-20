//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node
{
    int data;
    struct Node* next;
};

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
        head->next = newNode;
    }

    return head;
}

struct Node* search(struct Node* head, int target)
{
    struct Node* current = head;

    while (current)
    {
        if (current->data == target)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

int main()
{
    struct Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    struct Node* result = search(head, 30);

    if (result)
    {
        printf("Found node with data: %d\n", result->data);
    }
    else
    {
        printf("Node not found\n");
    }

    return 0;
}