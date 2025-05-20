//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insert_at_tail(Node** head, int data)
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

int delete_from_head(Node** head)
{
    if (*head == NULL)
    {
        return -1;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return 0;
}

int main()
{
    Node* head = NULL;

    insert_at_tail(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_tail(&head, 30);

    delete_from_head(&head);

    printf("Head: %d", head->data);

    return 0;
}