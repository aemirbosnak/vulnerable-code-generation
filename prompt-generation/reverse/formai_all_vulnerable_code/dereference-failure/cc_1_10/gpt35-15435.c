//FormAI DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a struct for each node in the linked list
typedef struct node
{
    int data;
    struct node* next;
} Node;

// Add a new element to the beginning of the list
void prepend(Node** head, int data)
{
    // Create a new node with the given data
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    // Set the next pointer of the new node to the current first element of the list
    new_node->next = *head;

    // Update the head pointer to point to the new node
    *head = new_node;
}

// Add a new element to the end of the list
void append(Node** head, int data)
{
    // Create a new node with the given data
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, set the head pointer to the new node
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last element
    Node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Set the next pointer of the last element to the new node
    current->next = new_node;
}

// Remove the first element of the list
void remove_head(Node** head)
{
    if (*head == NULL)
    {
        printf("Cannot remove head - list is empty\n");
        return;
    }

    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Remove the last element of the list
void remove_tail(Node** head)
{
    if (*head == NULL)
    {
        printf("Cannot remove tail - list is empty\n");
        return;
    }

    // If the list has only one element, remove it
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse the list to find the second-to-last element
    Node* current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    // Free the last element and set the next pointer of the second-to-last element to NULL
    free(current->next);
    current->next = NULL;
}

// Insert a new element after a given node
void insert_after(Node* node, int data)
{
    // Create a new node with the given data
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    // Set the next pointer of the new node to the next pointer of the given node
    new_node->next = node->next;

    // Set the next pointer of the given node to the new node
    node->next = new_node;
}

// Traverse the list and print each element
void print_list(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* current = head;
    printf("List elements:\n");
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    // Create an empty list
    Node* head = NULL;

    // Prepend some elements
    prepend(&head, 1);
    prepend(&head, 2);
    prepend(&head, 3);

    // Append some elements
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    // Remove the head and tail elements
    remove_head(&head);
    remove_tail(&head);

    // Find the element with value 1 and insert a new element after it
    Node* current = head;
    while (current->data != 1)
    {
        current = current->next;
    }
    insert_after(current, 7);

    // Print the final list
    print_list(head);

    return 0;
}