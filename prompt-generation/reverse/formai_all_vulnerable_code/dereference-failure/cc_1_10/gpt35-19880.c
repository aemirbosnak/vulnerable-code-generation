//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the linked list node
struct node {
    int data;
    struct node *next;
};

// Function to create a new node for the linked list
struct node* createNode(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct node* push(struct node *head, int data) {
    // Create a new node
    struct node *newNode = createNode(data);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    }
    // Otherwise, insert the new node at the beginning of the list
    else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to insert a new node at the end of the linked list
struct node* append(struct node *head, int data) {
    // Create a new node
    struct node *newNode = createNode(data);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse the list to the last node
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end of the list
    current->next = newNode;
    return head;
}

// Function to insert a new node at a given position in the linked list
struct node* insertAt(struct node *head, int data, int position) {
    // Handle the special case where the new node is to be inserted at the beginning of the list
    if (position == 0) {
        head = push(head, data);
        return head;
    }

    // Create a new node
    struct node *newNode = createNode(data);

    // Traverse the list to the node before the position where the new node is to be inserted
    struct node *current = head;
    for (int i = 0; i < position-1; i++) {
        current = current->next;
    }

    // Insert the new node at the given position in the list
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the node at the beginning of the linked list
struct node* pop(struct node *head) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If there is only one node in the list, delete it and return NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Delete the head node and make the second node the new head
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the node at the end of the linked list
struct node* deleteLast(struct node *head) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If there is only one node in the list, delete it and return NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Traverse the list to the second-to-last node
    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Delete the last node and set the next pointer of the second-to-last node to NULL
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node at a given position in the linked list
struct node* deleteAt(struct node *head, int position) {
    // Handle the special case where the node to be deleted is at the beginning of the list
    if (position == 0) {
        head = pop(head);
        return head;
    }

    // Traverse the list to the node before the position where the node is to be deleted
    struct node *current = head;
    for (int i = 0; i < position-1; i++) {
        current = current->next;
    }

    // Delete the node at the given position in the list
    struct node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to print the contents of the linked list
void printList(struct node *head) {
    // Traverse the list and print each node's data
    printf("List Contents: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    // Initialize an empty linked list
    struct node *head = NULL;

    // Test the push operation to insert nodes at the beginning of the list
    head = push(head, 9);
    head = push(head, 8);
    head = push(head, 7);
    printList(head);

    // Test the append operation to insert nodes at the end of the list
    head = append(head, 10);
    head = append(head, 11);
    head = append(head, 12);
    printList(head);

    // Test the insertAt operation to insert nodes at specific positions in the list
    head = insertAt(head, 13, 6);
    head = insertAt(head, 14, 3);
    head = insertAt(head, 15, 0);
    printList(head);

    // Test the pop operation to delete the first node in the list
    head = pop(head);
    head = pop(head);
    head = pop(head);
    printList(head);

    // Test the deleteLast operation to delete the last node in the list
    head = deleteLast(head);
    head = deleteLast(head);
    head = deleteLast(head);
    printList(head);

    // Test the deleteAt operation to delete nodes at specific positions in the list
    head = deleteAt(head, 3);
    head = deleteAt(head, 0);
    head = deleteAt(head, 2);
    printList(head);

    return 0;
}