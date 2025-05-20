//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node
{
    int data;
    struct Node* next;
};

void insertAtTail(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

void roundRobin(struct Node** head)
{
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current)
    {
        next = current->next;
        current->next = *head;
        *head = current;
        current = next;
    }
}

int main()
{
    struct Node* head = NULL;

    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    roundRobin(&head);

    struct Node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}