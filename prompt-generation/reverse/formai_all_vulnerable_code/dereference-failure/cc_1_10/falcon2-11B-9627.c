//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated to each node in the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        struct Node* temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free the memory allocated to the nodes
    freeList(head);

    // Print the linked list after freeing the memory
    printf("\nLinked List after freeing memory: ");
    printList(head);

    return 0;
}