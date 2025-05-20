//FormAI DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the struct for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given integer value
struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a new node to the end of a linked list
struct Node* appendNode(struct Node* head, int data) {
    struct Node* node = createNode(data);
    if (head == NULL) {
        head = node;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    return head;
}

// Function to insert a new node after a given node in a linked list
void insertNodeAfter(struct Node* node, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = node->next;
    node->next = newNode;
}

// Function to delete a node with a given integer value from a linked list
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;
    if (current == NULL) {
        return NULL;
    } else if (current->data == data) {
        head = current->next;
        free(current);
        return head;
    } else {
        while (current->next != NULL) {
            if (current->next->data == data) {
                struct Node* temp = current->next;
                current->next = current->next->next;
                free(temp);
                return head;
            }
            current = current->next;
        }
        return head;
    }
}

// Function to print the values of a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Add some nodes to the linked list
    head = appendNode(head, 4);
    head = appendNode(head, 6);
    head = appendNode(head, 8);
    
    // Print the linked list
    printf("Original linked list: ");
    printList(head);
    
    // Insert a new node after the second node
    insertNodeAfter(head->next, 5);
    
    // Print the updated linked list
    printf("Linked list after insert: ");
    printList(head);
    
    // Delete the node with value 6
    head = deleteNode(head, 6);
    
    // Print the updated linked list
    printf("Linked list after delete: ");
    printList(head);
    
    return 0;
}