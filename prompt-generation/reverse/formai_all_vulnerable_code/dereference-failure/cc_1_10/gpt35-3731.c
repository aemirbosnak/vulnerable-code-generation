//FormAI DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node definition of Linked List
typedef struct node
{
    int data;
    struct node *next;
} Node;

// Function to insert a node at the head of the linked list
Node *insertNode(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to visualize the Linked List data structure
void visualizeLinkedList(Node *head)
{
    printf("\n\n*** Linked List Visualization ***\n\n");

    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n\n");
}

int main()
{
    Node *head = NULL;

    // Inserting Nodes into the Linked List
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);
    head = insertNode(head, 50);

    // Visualizing the Linked List
    visualizeLinkedList(head);

    return 0;
}