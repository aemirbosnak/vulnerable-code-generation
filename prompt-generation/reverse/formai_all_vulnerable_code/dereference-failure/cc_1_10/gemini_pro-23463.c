//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node
{
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(node **head, int data)
{
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(node **head, int data)
{
    node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node after a given node
void insert_after_node(node **head, int data, int after_data)
{
    node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp != NULL && temp->data != after_data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_from_end(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *to_delete = temp->next;
    temp->next = NULL;
    free(to_delete);
}

// Function to delete a node from the list
void delete_node(node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->data == data)
    {
        delete_from_beginning(head);
        return;
    }
    node *temp = *head;
    while (temp->next != NULL && temp->next->data != data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Node not found\n");
        return;
    }
    node *to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}

// Function to reverse the list
void reverse_list(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the list
void print_list(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main()
{
    // Create a linked list
    node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after_node(&head, 4, 2);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    printf("After deleting from beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    printf("After deleting from end: ");
    print_list(head);

    // Delete a node from the list
    delete_node(&head, 3);

    // Print the list
    printf("After deleting node with data 3: ");
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the list
    printf("Reversed list: ");
    print_list(head);

    return 0;
}