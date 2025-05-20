//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
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

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtTail(struct Node** head)
{
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (*head == NULL)
    {
        return;
    }

    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev)
    {
        prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
}

int main()
{
    struct Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    printList(head);

    deleteAtTail(&head);

    printList(head);

    return 0;
}