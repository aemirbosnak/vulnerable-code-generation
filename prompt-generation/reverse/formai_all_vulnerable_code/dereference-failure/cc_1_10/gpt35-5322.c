//FormAI DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
 
// Linked List Node structure
struct Node
{
    int data;
    struct Node* next;
};
 
// Function to print linked list
void printList(struct Node* n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}
 
// Function to add a node at the end of the linked list
void appendNode(struct Node** headRef, int data)
{
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef; // To traverse till end of the linked list
    newNode->data = data; // Assign data to the new node
    newNode->next = NULL; // New node will be the last node
 
    // If the linked list is empty, make the new node as the first node
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
 
    // Else traverse till the end of the linked list
    while (last->next != NULL)
        last = last->next;
 
    // Change last node's next pointer to the new node
    last->next = newNode;
    return;
}
 
// Function to delete a node at the given position
void deleteNode(struct Node** headRef, int position)
{
    // If linked list is empty
    if (*headRef == NULL)
        return;
 
    // Store head node
    struct Node* temp = *headRef;
 
    // If head needs to be removed
    if (position == 0)
    {
        *headRef = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than the number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Node to be deleted
    struct Node* next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next); // Free memory
    temp->next = next; // Unlink the deleted node from list
}
 
// Main function to test the linked list operations
int main()
{
    struct Node* head = NULL; // Empty linked list
 
    // Append nodes to the linked list
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);
 
    printf("Linked list before deletion: ");
    printList(head);
 
    // Delete a node at position 1
    deleteNode(&head, 1);
 
    printf("\nLinked list after deletion: ");
    printList(head);
 
    return 0;
}