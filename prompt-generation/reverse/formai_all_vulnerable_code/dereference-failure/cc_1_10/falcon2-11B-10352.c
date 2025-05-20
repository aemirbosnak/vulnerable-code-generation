//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* current = *head_ref;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to delete a node with the given data from the linked list
void deleteNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found\n", data);
    } else if (prev == NULL) {
        *head_ref = current->next;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Inserting elements at the beginning
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    
    // Inserting elements at the end
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    
    // Deleting a node with data 20
    deleteNode(&head, 20);
    
    // Printing the elements of the linked list
    printList(head);
    
    return 0;
}