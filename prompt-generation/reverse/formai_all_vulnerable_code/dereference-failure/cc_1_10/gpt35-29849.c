//FormAI DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define functions for linked list operations
void insert(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ",current->data);
        current = current->next;
    }
}

void delete(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
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

int main() {
    struct Node* head = NULL;

    // Add nodes to the linked list
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 9);
    insert(&head, 10);

    // Print the linked list
    printf("Original List: ");
    printList(head);

    // Delete a node from the linked list
    printf("\nDeleting node with data 8...\n");
    delete(&head, 8);

    // Print the linked list after deletion
    printf("List after deletion: ");
    printList(head);

    return 0;
}