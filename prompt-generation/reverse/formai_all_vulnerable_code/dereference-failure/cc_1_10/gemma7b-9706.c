//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void enqueue(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
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

int dequeue(Node** head)
{
    int data;

    if (*head == NULL)
    {
        return -1;
    }

    data = (*head)->data;
    *head = (*head)->next;

    return data;
}

int main()
{
    Node* head = NULL;

    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);
    enqueue(&head, 40);
    enqueue(&head, 50);

    printf("Enqueued data: ");
    for (Node* node = head; node; node = node->next)
    {
        printf("%d ", node->data);
    }

    printf("\n");

    int data = dequeue(&head);

    if (data != -1)
    {
        printf("Dequed data: %d", data);
    }

    printf("\n");

    data = dequeue(&head);

    if (data != -1)
    {
        printf("Dequed data: %d", data);
    }

    return 0;
}