//FormAI DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

/* The structure of a node in a linked list */
struct Node {
    int data;
    struct Node* next;
};

/* Function to add a node at the beginning of the linked list */
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to add a node at the end of the linked list */
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

/* Function to delete the first occurrence of a node with given data */
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

/* Function to print the linked list */
void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Sample usage */
int main() {
    struct Node* head = NULL;
    // Add nodes to the beginning of the linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    // Print the linked list
    printf("Linked list after inserting nodes at the beginning: ");
    printList(head);
    // Add nodes to the end of the linked list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    // Print the linked list
    printf("Linked list after inserting nodes at the end: ");
    printList(head);
    // Delete node with value 3
    deleteNode(&head, 3);
    // Print the linked list
    printf("Linked list after deleting node with value 3: ");
    printList(head);
    return 0;
}