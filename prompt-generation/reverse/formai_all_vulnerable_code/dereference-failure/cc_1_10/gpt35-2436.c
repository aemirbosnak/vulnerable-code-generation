//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct ListNode {
    int data;
    struct ListNode *next;
};

// Function to print the linked list
void printList(struct ListNode *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to add a node at the beginning of the linked list
void push(struct ListNode **head, int data) {
    // Create a new node
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the linked list
void append(struct ListNode **head, int data) {
    // Create a new node
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node as the head node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the last node and link the new node to it
    struct ListNode *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct ListNode *prev, int data) {
    // Check if the previous node is NULL
    if (prev == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        return;
    }

    // Create a new node
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

// Function to delete the first occurrence of a node with the given data
void deleteNode(struct ListNode **head, int data) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    // Check if the head node contains the data
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }

    // Traverse the list to find the node with the given data
    struct ListNode *prev = *head, *curr = (*head)->next;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    // If the node is not found
    if (curr == NULL) {
        printf("Error: Node with data %d not found.\n", data);
        return;
    }

    // Link the previous node to the next node and free the current node
    prev->next = curr->next;
    free(curr);
}

// Function to reverse the linked list
void reverseList(struct ListNode **head) {
    struct ListNode *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Sample usage
int main() {
    struct ListNode *head = NULL;

    // Add nodes to the list
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    append(&head, 4);
    append(&head, 5);

    insertAfter(head->next, 8);
    insertAfter(head->next->next, 9);

    // Print the list
    printList(head);

    // Delete a node and print the list
    deleteNode(&head, 4);
    printList(head);

    // Reverse the list and print it
    reverseList(&head);
    printList(head);

    return 0;
}