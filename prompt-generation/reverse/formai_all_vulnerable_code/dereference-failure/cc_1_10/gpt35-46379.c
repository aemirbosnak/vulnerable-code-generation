//FormAI DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the struct for a doubly-linked list node
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

// Define a function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a new node at the beginning of the list
void push(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// Define a function to delete a node from the list
void delete_node(Node** head_ref, Node* del_node) {
    if ((*head_ref) == NULL || del_node == NULL) {
        return;
    }
    if ((*head_ref) == del_node) {
        (*head_ref) = del_node->next;
    }
    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }
    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }
    free(del_node);
}

int main() {
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    
    Node* current = head;
    printf("Doubly-linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Delete node with data value 3
    Node* del_node;
    current = head;
    while (current != NULL) {
        if (current->data == 3) {
            del_node = current;
            break;
        }
        current = current->next;
    }
    delete_node(&head, del_node);

    // Display updated list
    current = head;
    printf("Updated doubly-linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}