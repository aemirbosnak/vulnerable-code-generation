//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/** Structure to store node information in linkedlist **/
struct node
{
    int data;
    struct node *next;
};

/** Function to create new node **/
struct node* createNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/** Function to add a node after a specific position **/
void addNodeAtIndex(struct node **head_ref, int index, int data)
{
    struct node* newNode = createNode(data);
    struct node* prevNode = *head_ref;
    int i;
    for(i=0; i<index-1; i++)
    {
        prevNode = prevNode->next;
    }
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("\nData %d added after position %d in list\n", data, index);
}

/** Function to remove node from specific index **/
void removeNodeAtIndex(struct node **head_ref, int index)
{
    struct node* prevNode = *head_ref;
    struct node* currentNode = prevNode->next;
    int i;
    for(i=0; i<index-1; i++)
    {
        prevNode = prevNode->next;
        currentNode = currentNode->next;
    }
    prevNode->next = currentNode->next;
    free(currentNode);
    printf("\nData at position %d removed from list\n", index);
}

/** Function to search node with specific value **/
void searchNode(struct node *node, int data)
{
    int index = 0;
    while(node != NULL)
    {
        index++;
        if(node->data == data)
        {
            printf("\nData %d found at position %d in list\n", data, index);
            return;
        }
        node = node->next;
    }
    printf("\nData %d not found in list\n", data);
}

/** Function to print the linkedlist **/
void printList(struct node *node)
{
    printf("\nLinkedlist : ");
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    /** Initialize empty linkedlist **/
    struct node *head = NULL;
    
    /** Add nodes to the linkedlist **/
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    
    /** Print the linkedlist before operation **/
    printList(head);
    
    /** Add node after position 2 **/
    addNodeAtIndex(&head, 2, 25);
    
    /** Print the linkedlist after addNodeAtIndex operation **/
    printList(head);
    
    /** Remove node from position 4 **/
    removeNodeAtIndex(&head, 4);
    
    /** Print the linkedlist after removeNodeAtIndex operation **/
    printList(head);
    
    /** Search node with value 30 **/
    searchNode(head, 30);
    
    /** Search node with value 50 **/
    searchNode(head, 50);

    /** Return with zero exit status **/
    return 0;
}