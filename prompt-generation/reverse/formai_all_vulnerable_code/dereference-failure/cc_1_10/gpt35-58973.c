//FormAI DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Define a linked list node */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Initialize a linked list */
Node* initialize() {
    return NULL;
}

/* Add a new node to the linked list */
Node* add_node(Node* head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;

    return head;
}

/* Print the linked list */
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Reverse the linked list */
Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/* Main function */
int main() {
    Node* head = initialize();
    
    /* Add nodes to the linked list */
    head = add_node(head, 5);
    head = add_node(head, 10);
    head = add_node(head, 15);
    head = add_node(head, 20);
    
    /* Print the original linked list */
    printf("Original linked list: ");
    print_list(head);
    
    /* Reverse the linked list */
    head = reverse_list(head);
    
    /* Print the reversed linked list */
    printf("Reversed linked list: ");
    print_list(head);

    return 0;
}