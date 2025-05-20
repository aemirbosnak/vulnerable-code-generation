//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node struct for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert node at the end of the linked list
void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new_node;
    return;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    
    printf("Linked List: ");
    printList(head);
    
    return 0;
}