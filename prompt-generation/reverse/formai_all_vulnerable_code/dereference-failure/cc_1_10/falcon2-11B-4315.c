//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Linked list operations
void printList(Node* head)
{
    Node* temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addNode(Node** head, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory error\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void deleteNode(Node** head, int data)
{
    Node* temp = *head;
    Node* prev = NULL;
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp!= NULL && temp->data!= data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}

void reverseList(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    Node* head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    printf("Original List:\n");
    printList(head);
    printf("\n");

    reverseList(&head);
    printf("Reversed List:\n");
    printList(head);
    printf("\n");

    deleteNode(&head, 30);
    printf("List after deleting 30:\n");
    printList(head);
    printf("\n");

    return 0;
}