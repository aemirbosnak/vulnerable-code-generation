//FormAI DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define linked structure
struct node {
    int data;
    struct node* next;
};

// Function to insert node at the beginning of the linked list
void insertAtBeginning(struct node** head, int data) {
    // Allocate memory for new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert node at the end of the linked list
void insertAtEnd(struct node** head, int data) {
    // Allocate memory for new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;
    newNode->data = data;
    newNode->next = NULL;

    // If linked list is empty, make new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Else traverse till the last node and insert the new node at end
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

// Function to delete node at given index in the linked list
void deleteAtIndex(struct node** head, int index) {
    // If linked list is empty or index out of bounds, return
    if (*head == NULL || index < 0) {
        return;
    }

    // If index is zero, delete the head node
    if (index == 0) {
        struct node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse till the node before the node to be deleted
    struct node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If index is out of bounds, return
    if (temp == NULL || temp->next == NULL) {
        return;
    }

    // Delete the node at given index
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return;
}

// Function to print the linked list
void printList(struct node* head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]");
    return;
}

int main() {
    struct node* head = NULL;

    // Insert nodes at beginning and end
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Output the linked list
    printf("Linked list:\n");
    printList(head);

    // Delete a node from the linked list
    deleteAtIndex(&head, 2);

    // Output the linked list again
    printf("\nLinked list after deletion:\n");
    printList(head);

    return 0;
}