//FormAI DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int new_data) {
    // If the linked list is empty, create a new node and make it the head
    if (*head == NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = NULL;
        *head = new_node;
    }
    // If the linked list is not empty, recurse to the end and insert a new node
    else {
        insertAtEnd(&((*head)->next), new_data);
    }
}

// Recursive function to delete a node with given key from the linked list
void deleteNode(struct Node** head, int key) {
    // If the linked list is empty, return without doing anything
    if (*head == NULL) {
        return;
    }
    // If the key is found in the head node, delete the head and update it
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    // Recurse to the rest of the linked list to delete the node with the key
    deleteNode(&((*head)->next), key);
}

// Recursive function to print the linked list in reverse order
void printReverse(struct Node* head) {
    // If the linked list is empty, return without doing anything
    if (head == NULL) {
        return;
    }
    // Recurse to the rest of the linked list first
    printReverse(head->next);
    // Then print the current node data
    printf("%d ", head->data);
}

// Recursive function to print the linked list
void printList(struct Node* head) {
    // If the linked list is empty, return without doing anything
    if (head == NULL) {
        return;
    }
    // Print the current node data
    printf("%d ", head->data);
    // Recurse to the rest of the linked list
    printList(head->next);
}

int main() {
    struct Node* head = NULL;
    // Insert 5 nodes at the end of the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    // Print the linked list
    printf("Linked list: ");
    printList(head);
    printf("\n");
    // Delete the nodes with keys 1 and 3
    deleteNode(&head, 1);
    deleteNode(&head, 3);
    // Print the linked list again
    printf("Linked list after deletion: ");
    printList(head);
    printf("\n");
    // Print the linked list in reverse order
    printf("Linked list in reverse order: ");
    printReverse(head);
    printf("\n");
    return 0;
}