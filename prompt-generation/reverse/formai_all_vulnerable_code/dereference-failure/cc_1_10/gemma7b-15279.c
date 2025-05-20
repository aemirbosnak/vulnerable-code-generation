//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

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
        ((*head)->next) = newNode;
    }
}

int dequeue(Node** head)
{
    int data;
    Node* temp = *head;

    if (*head == NULL) {
        return -1;
    }

    *head = (*head)->next;
    data = temp->data;
    free(temp);

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

    printf("Data from the queue:");
    while (head) {
        int data = dequeue(&head);
        if (data != -1) {
            printf(" %d ", data);
        }
    }

    return 0;
}