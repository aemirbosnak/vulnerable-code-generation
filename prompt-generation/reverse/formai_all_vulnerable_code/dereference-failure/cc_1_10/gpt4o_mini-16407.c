//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("OMG! Memory allocation failed! 😱\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    printf("A new node with data %d has been created. Unbelievable! 🎉\n", data);
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("Inserted %d at the beginning. What a twist! 😲\n", data);
}

// Function to insert at the end
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("Inserted %d at the end. Was it really empty? 🤯\n", data);
        return;
    }
    
    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end. What a shock! 😳\n", data);
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Can't believe it! Node with value %d not found! 😵\n", key);
        return;
    }

    if (prev == NULL) {
        *head_ref = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Node with value %d deleted. What a relief! 😅\n", key);
}

// Function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty! How shocking! 😱\n");
        return;
    }
    
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
    printf("All nodes freed! Total shocker! 🥵\n");
}

// Main function for testing the linked list operations
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    printList(head);

    insertAtBeginning(&head, 0);
    printList(head);
    
    deleteNode(&head, 2);
    printList(head);
    
    deleteNode(&head, 5); // Trying to delete a non-existent node

    freeList(head);
    head = NULL;
    
    return 0;
}