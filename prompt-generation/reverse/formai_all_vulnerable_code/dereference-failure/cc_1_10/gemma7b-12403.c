//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node
struct node {
    int data;
    struct node* next;
};

// Function to insert at the end
void insertAtEnd(struct node** head, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to delete from the end
void deleteFromEnd(struct node** head)
{
    struct node* prev = NULL;
    struct node* current = *head;

    // Traverse the linked list until the second last node is reached
    while (current->next) {
        prev = current;
        current = current->next;
    }

    // If the first node is to be deleted, update the head
    if (prev) {
        prev->next = current->next;
        free(current);
    } else {
        *head = current->next;
        free(current);
    }
}

// Function to traverse the linked list
void traverse(struct node* head)
{
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct node* head = NULL;

    // Insert some nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Traverse the linked list
    traverse(head);

    // Delete nodes from the end
    deleteFromEnd(&head);

    // Traverse the linked list after deletion
    traverse(head);

    return 0;
}