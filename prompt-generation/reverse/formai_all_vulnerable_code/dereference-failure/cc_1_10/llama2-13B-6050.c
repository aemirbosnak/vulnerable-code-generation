//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the list
void deleteFirstNode(struct Node** head_ref) {
    if (*head_ref != NULL) {
        struct Node* temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
    }
}

// Function to find the node with the given data and return its address
struct Node* findNode(struct Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to traverse the list in a secure style
void traverseSecure(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printf("Current node: %d\n", head->data);
    traverseSecure(head->next);
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);

    // Delete the first node of the list
    deleteFirstNode(&head);

    // Find the node with the given data and print its address
    struct Node* found = findNode(head, 2);
    if (found != NULL) {
        printf("Node found at address: %p\n", found);
    } else {
        printf("Node not found\n");
    }

    // Traverse the list in a secure style
    traverseSecure(head);

    return 0;
}