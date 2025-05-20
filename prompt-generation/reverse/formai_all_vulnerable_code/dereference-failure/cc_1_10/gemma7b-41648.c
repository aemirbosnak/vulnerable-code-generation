//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* InsertAtTail(struct Node* head, int data)
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
        struct Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

struct Node* DeleteFromTail(struct Node* head)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head == NULL)
    {
        return NULL;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    return head;
}

int main()
{
    struct Node* head = NULL;

    InsertAtTail(head, 10);
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    InsertAtTail(head, 40);

    DeleteFromTail(head);

    struct Node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}