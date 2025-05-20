//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
typedef struct node
{
    int data;
    struct node* next;
} Node;

// Create an empty list
Node* createList()
{
    Node* head = NULL;
    return head;
}

// Insert a node at the end of the list
void insertAtEnd(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (*head == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next!= NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    return;
}

// Insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}

// Insert a node at a specific position in the list
void insertAtPosition(Node** head, int data, int position)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL || position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < position - 2 && temp!= NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

// Delete a node from the list
void deleteNode(Node** head, int data)
{
    Node* temp = *head;
    if (temp!= NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }
    Node* prev = temp->next;
    free(temp);
    temp = prev;
    while (temp!= NULL)
    {
        if (temp->next == NULL)
        {
            temp->next = prev;
            break;
        }
        temp = temp->next;
    }
    return;
}

// Display the list
void displayList(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

// Main function
int main()
{
    Node* head = createList();
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtPosition(&head, 30, 2);
    displayList(head);
    deleteNode(&head, 20);
    displayList(head);
    return 0;
}