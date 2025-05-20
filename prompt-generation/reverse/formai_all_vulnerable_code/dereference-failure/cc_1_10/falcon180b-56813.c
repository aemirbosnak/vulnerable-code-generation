//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the structure for a linked list
typedef struct linked_list {
    Node *head;
    Node *tail;
} LinkedList;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
LinkedList *create_linked_list() {
    LinkedList *new_list = (LinkedList *) malloc(sizeof(LinkedList));
    if (new_list == NULL) {
        printf("Error: Failed to allocate memory for new linked list.\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Function to add a node to the end of a linked list
void add_node(LinkedList *list, int data) {
    Node *new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Function to print the contents of a linked list
void print_list(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList *my_list = create_linked_list();
    add_node(my_list, 1);
    add_node(my_list, 2);
    add_node(my_list, 3);
    print_list(my_list);
    return 0;
}