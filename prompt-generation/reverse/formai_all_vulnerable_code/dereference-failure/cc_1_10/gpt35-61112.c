//FormAI DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create and insert a node at the beginning of the linked list
struct Node* insertBegin(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to create and insert a node at the end of the linked list
struct Node* insertEnd(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    // If the linked list is empty, just return the new node
    if (head == NULL) {
        head = newNode;
        return head;
    }
    // Traverse to the last node and insert the new node at the end
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node* head, int value) {
    // If the linked list is empty, just return NULL
    if (head == NULL) {
        return NULL;
    }
    // If the value is at the beginning of the linked list, delete the first node
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // Traverse to the node before the node with the given value
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    // If the node with the given value is found, delete the node
    if (temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    return head;
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL;
    int choice, data, value;
    do {
        // Display menu
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Delete a node");
        printf("\n4. Display linked list");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &data);
                head = insertBegin(head, data);
                break;
            case 2:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 3:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 4:
                displayLinkedList(head);
                break;
            case 0:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 0);
    return 0;
}