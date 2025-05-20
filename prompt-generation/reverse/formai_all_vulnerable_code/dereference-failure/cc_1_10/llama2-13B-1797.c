//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the list
struct Node* deleteFirst(struct Node** head_ref) {
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
    return first_node;
}

// Function to find the node with the given data and return its address
struct Node* findNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print all the nodes in the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Delete the first node of the list
    head = deleteFirst(&head);

    // Find a node with the data 2 and print its address
    struct Node* node = findNode(&head, 2);
    if (node != NULL) {
        printf("Node with data 2 found at address %p\n", node);
    } else {
        printf("Node with data 2 not found\n");
    }

    // Print the remaining nodes in the list
    printList(head);

    return 0;
}