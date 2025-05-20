//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for a node in the linked list */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Function prototypes */
Node* create_node(int data);
void append_node(Node** head, int data);
void print_list(Node* head);
void free_list(Node* head);

/* Main function */
int main() {
    Node* head = NULL;

    /* Create some nodes */
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);

    /* Print the list */
    printf("Original list:\n");
    print_list(head);

    /* Free the list */
    free_list(head);

    /* Print the list again to show it has been freed */
    printf("\nList after freeing:\n");
    print_list(head);

    return 0;
}

/* Function to create a new node with given data */
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to append a node with given data to the end of the list */
void append_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* curr_node = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;
}

/* Function to print the list */
void print_list(Node* head) {
    Node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

/* Function to free the list */
void free_list(Node* head) {
    Node* curr_node = head;
    while (curr_node!= NULL) {
        Node* temp_node = curr_node;
        curr_node = curr_node->next;
        free(temp_node);
    }
}