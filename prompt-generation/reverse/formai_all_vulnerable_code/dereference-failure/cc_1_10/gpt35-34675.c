//FormAI DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure definition
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* create_node(int);
void insert_front(Node**, int);
void insert_end(Node**, int);
bool is_empty(Node*);
void display_list(Node*);
void free_list(Node**);
void delete_front(Node**);
void delete_end(Node**);
void delete_node(Node**, int);

// Main function
int main()
{
    Node* head = NULL;
    
    // Inserting elements in the linked list
    insert_front(&head, 10);
    insert_front(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);

    // Displaying the linked list
    printf("Linked List: ");
    display_list(head);

    // Deleting nodes from the linked list
    delete_front(&head);
    delete_end(&head);
    delete_node(&head, 20);

    // Displaying the modified linked list
    printf("Modified Linked List: ");
    display_list(head);

    // Freeing up memory
    free_list(&head);

    return 0;
}

// Function to create a new node
Node* create_node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert an element at the front of the linked list
void insert_front(Node** head, int data)
{
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert an element at the end of the linked list
void insert_end(Node** head, int data)
{
    Node* new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to check if the linked list is empty or not
bool is_empty(Node* head)
{
    return head == NULL;
}

// Function to display the linked list
void display_list(Node* head)
{
    if (is_empty(head))
    {
        printf("Empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free up memory occupied by the linked list
void free_list(Node** head)
{
    Node* temp = *head;
    while (*head != NULL)
    {
        *head = (*head)->next;
        free(temp);
        temp = *head;
    }
}

// Function to delete the first node from the linked list
void delete_front(Node** head)
{
    if (is_empty(*head))
    {
        printf("Cannot delete from an empty list\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node from the linked list
void delete_end(Node** head)
{
    if (is_empty(*head))
    {
        printf("Cannot delete from an empty list\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a particular node from the linked list
void delete_node(Node** head, int data)
{
    if (is_empty(*head))
    {
        printf("Cannot delete from an empty list\n");
        return;
    }
    if ((*head)->data == data)
    {
        delete_front(head);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Element not found in the list\n");
        return;
    }
    Node* to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}