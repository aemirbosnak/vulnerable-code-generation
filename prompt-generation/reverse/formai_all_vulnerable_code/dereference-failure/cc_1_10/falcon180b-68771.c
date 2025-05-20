//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a linked list structure
typedef struct linked_list {
    Node* head;
} LinkedList;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Add a node to the end of the list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* curr_node = list->head;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

// Print the linked list
void print_list(LinkedList* list) {
    Node* curr_node = list->head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Reverse the linked list
void reverse_list(LinkedList* list) {
    Node* curr_node = list->head;
    Node* prev_node = NULL;
    while (curr_node!= NULL) {
        Node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    list->head = prev_node;
}

int main() {
    LinkedList list;
    list.head = NULL;

    // Add some nodes to the list
    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);

    // Print the original list
    printf("Original list:\n");
    print_list(&list);

    // Reverse the list
    reverse_list(&list);

    // Print the reversed list
    printf("Reversed list:\n");
    print_list(&list);

    return 0;
}