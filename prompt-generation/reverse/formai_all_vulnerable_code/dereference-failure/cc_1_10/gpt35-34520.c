//FormAI DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the beginning of the Linked list
void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the Linked list
void printList(Node* head) {
    if(head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    printf("Linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to delete a node from the Linked list
bool deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return true;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return false;
    }
    prev->next = temp->next;
    free(temp);
    return true;
}

// Function to reverse the Linked list
void reverseList(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    // Insert nodes at the beginning of the Linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    // Print the Linked list
    printList(head);
    // Delete a node from the Linked list
    int key = 3;
    bool isDeleted = deleteNode(&head, key);
    if(isDeleted) {
        printf("%d is deleted from the Linked list\n", key);
    } else {
        printf("%d is not found in the Linked list\n", key);
    }
    // Print the Linked list after deletion
    printList(head);
    // Reverse the Linked list
    reverseList(&head);
    // Print the Linked list after reversing
    printList(head);
    return 0;
}