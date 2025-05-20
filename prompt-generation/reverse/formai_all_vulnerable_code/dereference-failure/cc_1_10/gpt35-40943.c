//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure for linked list node
typedef struct node
{
    int data;
    struct node *next;
} node;

// Function to add a node to the front of the list
void push(node **head, int data)
{
    // Allocate memory for a new node
    node *new_node = malloc(sizeof(node));

    // Set the data of the new node
    new_node->data = data;

    // Point the new node to the current head
    new_node->next = *head;

    // Set the head to the new node
    *head = new_node;
}

// Function to add a node to the end of the list
void append(node **head, int data)
{
    // Allocate memory for a new node
    node *new_node = malloc(sizeof(node));

    // Set the data of the new node
    new_node->data = data;

    // Set the next pointer of the new node to NULL
    new_node->next = NULL;

    // If the list is empty, set the head to the new node
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node
    node *last_node = *head;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    // Set the next pointer of the last node to the new node
    last_node->next = new_node;
}

// Function to insert a node at a given position in the list
void insert(node **head, int data, int position)
{
    // Allocate memory for a new node
    node *new_node = malloc(sizeof(node));

    // Set the data of the new node
    new_node->data = data;

    // If the list is empty, set the head to the new node
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // If the position is 0, insert the node at the front of the list
    if (position == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the node before the insertion position
    node *previous_node = *head;
    for (int i = 0; i < position - 1 && previous_node->next != NULL; i++)
    {
        previous_node = previous_node->next;
    }

    // If the position is out of bounds, return an error message
    if (previous_node == NULL || previous_node->next == NULL)
    {
        printf("Error: position out of bounds\n");
        return;
    }

    // Set the new node to point to the next node
    new_node->next = previous_node->next;

    // Set the previous node to point to the new node
    previous_node->next = new_node;
}

// Function to delete a node with a given data value from the list
void delete(node **head, int data)
{
    // If the list is empty, return an error message
    if (*head == NULL)
    {
        printf("Error: list is empty\n");
        return;
    }

    // If the head node is the node to delete, set the next node as the head
    if ((*head)->data == data)
    {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node before the node to delete
    node *previous_node = *head;
    while (previous_node->next != NULL && previous_node->next->data != data)
    {
        previous_node = previous_node->next;
    }

    // If the node to delete is not found, return an error message
    if (previous_node->next == NULL)
    {
        printf("Error: node not found\n");
        return;
    }

    // Set the previous node to point to the node after the one to delete
    node *to_delete = previous_node->next;
    previous_node->next = to_delete->next;

    // Free memory for the deleted node
    free(to_delete);
}

// Function to print the contents of the list
void print_list(node *head)
{
    // Traverse the list and print the data of each node
    node *current_node = head;
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main()
{
    // Initialize an empty linked list
    node *head = NULL;

    // Add nodes to the list using the push function
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);

    // Print the contents of the list
    printf("Initial list: ");
    print_list(head);

    // Add nodes to the list using the append function
    append(&head, 20);
    append(&head, 25);
    append(&head, 30);

    // Print the contents of the list
    printf("List after appending: ");
    print_list(head);

    // Insert nodes at different positions in the list
    insert(&head, 8, 1);
    insert(&head, 18, 3);
    insert(&head, 28, 5);

    // Print the contents of the list
    printf("List after inserting: ");
    print_list(head);

    // Delete nodes from the list
    delete(&head, 5);
    delete(&head, 18);
    delete(&head, 30);

    // Print the contents of the list
    printf("List after deleting: ");
    print_list(head);

    return 0;
}