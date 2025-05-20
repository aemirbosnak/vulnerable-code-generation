//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a node in a linked list
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a new node with the given data
node* new_node(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void print_list(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
node* reverse_list(node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Create a new node with the head's data and link it to the previous node
    node* new_head = new_node(head->data);
    new_head->next = head->next;

    // Reverse the rest of the list
    head->next = NULL;
    return reverse_list(head->next);
}

int main() {
    // Create a list with the numbers 1 to 10
    node* head = new_node(1);
    for (int i = 2; i <= 10; i++) {
        head = head->next = new_node(i);
    }

    // Print the list
    print_list(head);

    // Reverse the list
    head = reverse_list(head);

    // Print the reversed list
    print_list(head);

    return 0;
}