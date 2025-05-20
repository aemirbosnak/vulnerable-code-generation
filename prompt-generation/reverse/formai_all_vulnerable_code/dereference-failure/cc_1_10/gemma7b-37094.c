//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char item_name[20];
    int quantity;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, char item_name, int quantity)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->item_name, item_name);
    newNode->quantity = quantity;
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

void TraverseList(Node* head)
{
    Node* current = head;
    while (current)
    {
        printf("%s - %d\n", current->item_name, current->quantity);
        current = current->next;
    }
}

int main()
{
    Node* head = NULL;

    InsertAtTail(head, "Apple", 10);
    InsertAtTail(head, "Banana", 20);
    InsertAtTail(head, "Orange", 30);

    TraverseList(head);

    return 0;
}