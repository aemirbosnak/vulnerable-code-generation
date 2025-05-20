//FormAI DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNewNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// Insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNewNode(data);
    newNode -> next = *head;
    *head = newNode;
}

// Insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* newNode = createNewNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
}

// Find the length of the linked list
int length(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head -> next;
    }
    return count;
}

// Delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp -> data == key) {
        *head = temp -> next;
        free(temp);
    } else {
        while (temp != NULL && temp -> data != key) {
            prev = temp;
            temp = temp -> next;
        }
        if (temp == NULL) {
            printf("Element not found");
            return;
        }
        prev -> next = temp -> next;
        free(temp);
    }
}

// Display the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    
    // Insert nodes into the linked list
    insertAtBeginning(&head, 7);
    insertAtEnd(&head, 14);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 22);
    insertAtBeginning(&head, 9);
    
    // Display the linked list
    displayList(head);
    
    // Delete a node from the linked list
    deleteNode(&head, 1);
    
    // Display the linked list after deletion
    displayList(head);
    
    // Find the length of the linked list
    printf("Length of the linked list: %d\n", length(head));
    
    return 0;
}