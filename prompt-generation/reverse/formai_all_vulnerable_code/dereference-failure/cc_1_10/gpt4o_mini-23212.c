//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Inserted %d into the linked list! 🎉\n", data);
}

// Function to delete a node with a specific value
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("The list is empty, nothing to delete! 🚫\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found! 😞\n", key);
        return;
    }

    if (prev == NULL) {
        *head = current->next; // Key found in head
    } else {
        prev->next = current->next; // Bypass the current node
    }
    free(current);
    printf("Deleted node with value %d from the linked list! 🗑️\n", key);
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to display! 😶\n");
        return;
    }
    printf("Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    printf("Freed the linked list! All nodes are gone! ❌\n");
}

// Main function to showcase linked list operations
int main() {
    Node* head = NULL;
    int choice, value;

    printf("Welcome to the Energetic Linked List Program! ⚡\n");
    
    while (1) {
        printf("\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                freeList(head);
                printf("Thank you for using the Energetic Linked List Program! 👋\n");
                return 0;
            default:
                printf("Invalid option! Please try again. 🛑\n");
                break;
        }
    }

    return 0;
}