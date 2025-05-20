//FormAI DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
// Program to demonstrate operations on a linked list
#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to insert a new node at the beginning of a linked list */
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to insert a new node after a given node */
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Function to append a new node at the end of a linked list */
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

/* Function to print the linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above functions */
int main() {
    struct Node* head = NULL;
    // insert 6 at the beginning
    push(&head, 6);
    // insert 7 after 6
    insertAfter(head->next, 7);
    // append 8 to the end
    append(&head, 8);
    // print the linked list
    printList(head);
    return 0;
}