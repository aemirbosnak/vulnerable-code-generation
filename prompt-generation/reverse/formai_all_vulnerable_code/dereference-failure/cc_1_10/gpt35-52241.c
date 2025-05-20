//FormAI DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node at the beginning of the linked list
void addNode(Node** head_ref, int new_data) {
    // Allocate memory for a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    // Assign the new data to the node
    new_node->data = new_data;
    // Connect the new node to the beginning of the linked list
    new_node->next = *head_ref;
    // Update the head of the linked list
    *head_ref = new_node;
}

// Function that prints the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Initialize the head of the linked list as NULL
    Node* head = NULL;

    // Create and add nodes to the linked list
    addNode(&head, 3);
    addNode(&head, 5);
    addNode(&head, 8);
    addNode(&head, 1);
    printf("Linked List after adding nodes: ");
    printList(head);

    // Delete the third node from the linked list
    Node* temp = head->next->next;
    head->next->next = temp->next;
    free(temp);
    printf("Linked List after deleting node: ");
    printList(head);

    // Reverse the linked list
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked List after reversing: ");
    printList(head);

    // Free the memory occupied by the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}