//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node
{
    int data;
    struct node* next;
} node;

// Function to add a node at the beginning of the linked list
void add_node(node** head, int data)
{
    // Allocate memory for the new node
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;

    // Make head point to the new node
    *head = new_node;
}

// Function to print the contents of the linked list
void print_list(node* head)
{
    // Traverse through each node in the linked list and print its data
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete a node from the linked list
void delete_node(node** head, int data)
{
    // Store the head node and the previous node of the node to be deleted
    node* temp = *head;
    node* prev = NULL;

    // If the head node is to be deleted
    if(temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while(temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if(temp == NULL)
    {
        printf("Node with data %d not found\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free memory allocated to the node
    free(temp);
}

// Function to delete the entire linked list
void delete_list(node** head)
{
    // Store the head node
    node* current = *head;
    node* next;

    // Traverse through each node and free the memory allocated to it
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    // Make head point to NULL to indicate that the list is empty
    *head = NULL;
}

// Main function to test the implementation
int main()
{
    node* head = NULL;

    // Add nodes to the linked list
    add_node(&head, 5);
    add_node(&head, 9);
    add_node(&head, 3);
    add_node(&head, 1);

    // Print the contents of the linked list
    printf("Linked list: ");
    print_list(head);
    
    // Delete a node from the linked list
    delete_node(&head, 3);
    printf("Linked list after deleting node with data 3: ");
    print_list(head);

    // Delete the entire linked list
    delete_list(&head);
    printf("Linked list after deleting entire list: ");
    print_list(head);
    
    return 0;
}