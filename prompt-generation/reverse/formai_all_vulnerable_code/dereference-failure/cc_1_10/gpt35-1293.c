//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct node
{
    int data;
    struct node* next;
};

// Define a function to insert a node at the beginning of a linked list
void insertAtBeginning(struct node** head, int data)
{
    // Create a new node and assign data to it
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
  
    // If the linked list is empty, assign the new node as the head
    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    // Otherwise, insert the new node at the beginning of the list
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

// Define a function to delete a node from the linked list
void deleteNode(struct node** head, int key)
{
    // If the linked list is empty, return
    if(*head == NULL)
        return;
        
    // If the key is present at the beginning of the list
    if((*head)->data == key)
    {
        // Set the head pointer to the next node
        *head = (*head)->next;
        free(*head);
        return;
    }
    
    // Find the node to be deleted
    struct node* curr = *head;
    struct node* prev = NULL;
    while(curr != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    
    // If the key is not present in the list, return
    if(curr == NULL)
        return;
        
    // Otherwise, delete the node
    prev->next = curr->next;
    free(curr);
}

// Define a function to print the contents of a linked list
void printList(struct node* head)
{
    printf("Linked List: ");
    struct node* curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    // Initialize a linked list
    struct node* head = NULL;
    
    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 6);
    
    // Delete the node with data value 5
    deleteNode(&head, 5);
    
    // Print the contents of the list
    printList(head);
    
    return 0;
}