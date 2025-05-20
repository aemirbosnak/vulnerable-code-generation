//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
typedef struct node
{
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the queue
void enqueue(Node** headRef, int data)
{
    Node* newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        Node* temp = *headRef;
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove and return the front node of the queue
Node* dequeue(Node** headRef)
{
    Node* temp = *headRef;
    if (*headRef == NULL)
    {
        return NULL;
    }
    else
    {
        Node* frontNode = *headRef;
        *headRef = (*headRef)->next;
        free(frontNode);
        return temp;
    }
}

// Function to display the queue
void displayQueue(Node* head)
{
    Node* temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    displayQueue(head);
    Node* frontNode = dequeue(&head);
    displayQueue(head);
    return 0;
}