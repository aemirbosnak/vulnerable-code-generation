//FormAI DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int data;
    struct Node *next;
};

// Define a function to create a new node with given data
struct Node *newNode(int data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head_ref, int data) {
    struct Node *new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("Inserted %d at the beginning of the list.\n", data);
}

// Define a function to insert a new node at the end of the list
void insertAtEnd(struct Node **head_ref, int data) {
    struct Node *new_node = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node *last_node = *head_ref;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    printf("Inserted %d at the end of the list.\n", data);
}

// Define a function to insert a new node after a given node
void insertAfter(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: The previous node cannot be NULL.\n");
        return;
    }
    struct Node *new_node = newNode(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    printf("Inserted %d after %d.\n", data, prev_node->data);
}

// Define a function to delete a node with given key from the list
void deleteNode(struct Node **head_ref, int key) {
    struct Node *temp_node = *head_ref, *prev_node;
    if (temp_node != NULL && temp_node->data == key) {
        *head_ref = temp_node->next;
        free(temp_node);
        printf("Deleted node with key %d from the list.\n", key);
        return;
    }
    while (temp_node != NULL && temp_node->data != key) {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    if (temp_node == NULL) {
        printf("Error: Key %d not found in the list.\n", key);
        return;
    }
    prev_node->next = temp_node->next;
    free(temp_node);
    printf("Deleted node with key %d from the list.\n", key);
}

// Define a function to print all the nodes in the list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Define the main function
int main() {
    struct Node *head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Insert nodes after a given node
    insertAfter(head->next, 6);

    // Delete nodes from the list
    deleteNode(&head, 5);
    deleteNode(&head, 7);

    // Print all the nodes in the list
    printf("The list is: ");
    printList(head);

    return 0;
}