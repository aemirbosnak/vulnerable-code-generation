//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the beginning of the list
void insert(Node** head_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete the first occurrence of a node with a given value
void deleteNode(Node** head_ref, int data) {
    Node* current = *head_ref;
    Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    Node* head = NULL;
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);
    insert(&head, 25);

    printf("Linked List: ");
    printList(head);

    printf("\nDeleting node with value 15: ");
    deleteNode(&head, 15);

    printf("\nLinked List: ");
    printList(head);

    return 0;
}