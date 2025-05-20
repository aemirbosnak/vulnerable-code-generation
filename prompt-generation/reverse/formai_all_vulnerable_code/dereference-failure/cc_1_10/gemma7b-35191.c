//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

int dequeue(Node** head, int* data)
{
    if (*head == NULL) {
        return 0;
    }

    *data = (*head)->data;
    *head = (*head)->next;

    return 1;
}

int main()
{
    Node* head = NULL;

    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);
    enqueue(&head, 40);
    enqueue(&head, 50);

    int data;

    dequeue(&head, &data);
    printf("Data: %d\n", data);

    dequeue(&head, &data);
    printf("Data: %d\n", data);

    return 0;
}