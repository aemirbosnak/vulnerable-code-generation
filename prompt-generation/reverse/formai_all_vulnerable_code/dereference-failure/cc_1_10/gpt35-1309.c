//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

// Define the structure for the node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Initialise a new node with the given data
struct Node* createNewNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse the linked list
void reverseLinkedList(struct Node **head)
{
    struct Node *currentNode = *head;
    struct Node *previousNode = NULL;
    struct Node *nextNode = NULL;
    while(currentNode!=NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    *head = previousNode;
}

// Driver program to test the above functions
int main()
{
    // Create a linked list with 5 nodes
    struct Node *head = createNewNode(1);
    head->next = createNewNode(2);
    head->next->next = createNewNode(3);
    head->next->next->next = createNewNode(4);
    head->next->next->next->next = createNewNode(5);

    // Display the linked list
    printf("Original ");
    printLinkedList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    // Display the reversed linked list
    printf("Reversed ");
    printLinkedList(head);

    return 0;
}