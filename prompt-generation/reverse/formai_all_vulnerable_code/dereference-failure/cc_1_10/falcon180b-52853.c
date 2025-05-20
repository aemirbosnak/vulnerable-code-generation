//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        (*head_ref) = new_node;
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// Function to add a node at a specific position in the list
void addAtPosition(struct Node** head_ref, int data, int pos) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (pos == 0) {
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 0; i < pos - 1 && temp!= NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

// Function to delete a node at a specific position in the list
void deleteNode(struct Node** head_ref, int pos) {
    struct Node* temp = *head_ref;
    if (pos == 0) {
        (*head_ref) = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos - 1 && temp!= NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
    return;
}

// Function to display the list
void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    display(head);
    printf("\n");
    append(&head, 50);
    display(head);
    printf("\n");
    addAtPosition(&head, 25, 2);
    display(head);
    printf("\n");
    deleteNode(&head, 2);
    display(head);
    return 0;
}