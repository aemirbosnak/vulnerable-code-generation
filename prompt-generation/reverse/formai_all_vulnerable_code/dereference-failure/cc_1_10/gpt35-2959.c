//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

/* Defining a struct for a linked list node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to create a new node with given data */
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a new node at the beginning of the linked list */
void insert_node(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to delete a node with given data from the linked list */
void delete_node(Node** head_ref, int data) {
    Node* current_node = *head_ref;
    Node* previous_node = NULL;

    while (current_node != NULL && current_node->data != data) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node with data %d not found in the linked list.\n", data);
        return;
    }

    if (previous_node == NULL) {
        *head_ref = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }

    free(current_node);
}

/* Function to print the linked list */
void print_list(Node* head) {
    Node* current_node = head;

    while (current_node != NULL) {
        printf("%d -> ", current_node->data);

        current_node = current_node->next;
    }

    printf("NULL\n");
}

/* Main function */
int main() {
    Node* head = NULL;

    printf("Initial linked list:\n");
    print_list(head);

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);

    printf("Linked list after inserting nodes:\n");
    print_list(head);

    delete_node(&head, 2);

    printf("Linked list after deleting node with data 2:\n");
    print_list(head);

    return 0;
}