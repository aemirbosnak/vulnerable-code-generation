//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
void displayList(struct Node* node);
struct Node* searchNode(struct Node* head, int key);

// Main function
int main() {
    struct Node* head = NULL;
    
    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    printf("Linked List after insertion: ");
    displayList(head);
    
    // Search for a node
    int searchKey = 20;
    struct Node* foundNode = searchNode(head, searchKey);
    if (foundNode != NULL) {
        printf("Node with value %d found in the list.\n", foundNode->data);
    } else {
        printf("Node with value %d not found in the list.\n", searchKey);
    }
    
    // Delete a node
    deleteNode(&head, 20);
    
    printf("Linked List after deletion of 20: ");
    displayList(head);
    
    // Free allocated memory (cleaning up)
    while (head != NULL) {
        deleteNode(&head, head->data);
    }
    
    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref; 
    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
}

// Function to delete a node with given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp); 
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to search for a node with the given key
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head; 
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL; // Return NULL if the key is not found
}