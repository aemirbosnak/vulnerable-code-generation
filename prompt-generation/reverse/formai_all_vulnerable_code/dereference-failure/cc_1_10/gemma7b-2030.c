//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertRear(Node** head, int data)
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

int deleteFront(Node** head)
{
    int data;
    Node* temp = *head;

    if (*head == NULL)
    {
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

    insertRear(&head, 10);
    insertRear(&head, 20);
    insertRear(&head, 30);
    insertRear(&head, 40);
    insertRear(&head, 50);

    printf("Data at the front: %d\n", deleteFront(&head));
    printf("Data at the rear: %d\n", head->data);

    return 0;
}