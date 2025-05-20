//FormAI DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize linked list as empty
struct Node* head = NULL;

// Insert node at the head of the list
void insertAtHead(int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set data and next pointer of new node
    new_node->data = new_data;
    new_node->next = head;
    // Set head to point to new node
    head = new_node;
}

// Insert node after a given node
void insertAfter(struct Node* prev_node, int new_data) {
    // Check if given previous node is NULL
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        return;
    }
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set data and next pointer of new node
    new_node->data = new_data;
    new_node->next = prev_node->next;
    // Set next pointer of previous node to new node
    prev_node->next = new_node;
}

// Insert node at the end of the list
void insertAtEnd(int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set data and next pointer of new node
    new_node->data = new_data;
    new_node->next = NULL;
    // If list is empty, set head to point to new node
    if (head == NULL) {
        head = new_node;
        return;
    }
    // Traverse list to find last node
    struct Node* last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    // Set next pointer of last node to new node
    last_node->next = new_node;
}

// Delete node with given key
void deleteNode(int key) {
    // If list is empty, return
    if (head == NULL) {
        return;
    }
    // If head node is to be deleted
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    // Traverse list to find previous node of node to be deleted
    struct Node* prev_node = head;
    while (prev_node->next != NULL && prev_node->next->data != key) {
        prev_node = prev_node->next;
    }
    // If node with given key was not found, return
    if (prev_node->next == NULL) {
        return;
    }
    // Delete the node and free memory
    struct Node* node_to_delete = prev_node->next;
    prev_node->next = node_to_delete->next;
    free(node_to_delete);
}

// Print the linked list
void printList() {
    struct Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test linked list operations
int main() {
    // Insert nodes at the head of the list
    printf("Inserting nodes at the head of the list:\n");
    insertAtHead(3);
    insertAtHead(6);
    insertAtHead(9);
    printList();
    // Insert node after a given node
    printf("Inserting node after a given node:\n");
    struct Node* prev_node = head->next;
    insertAfter(prev_node, 4);
    printList();
    // Insert nodes at the end of the list
    printf("Inserting nodes at the end of the list:\n");
    insertAtEnd(5);
    insertAtEnd(7);
    printList();
    // Delete node with given key
    printf("Deleting node with given key:\n");
    deleteNode(4);
    printList();

    return 0;
}