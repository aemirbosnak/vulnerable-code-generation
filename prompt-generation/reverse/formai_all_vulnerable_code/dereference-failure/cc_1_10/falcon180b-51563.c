//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define our node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define our linked list structure
typedef struct list {
    Node* head;
} List;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
List* create_list() {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;
    return new_list;
}

// Function to add a node to the end of a linked list
void add_node(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current_node = list->head;
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to print a linked list
void print_list(List* list) {
    Node* current_node = list->head;
    while (current_node!= NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Function to reverse a linked list
void reverse_list(List* list) {
    Node* prev_node = NULL;
    Node* current_node = list->head;
    while (current_node!= NULL) {
        Node* next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    list->head = prev_node;
}

int main() {
    List* my_list = create_list();
    add_node(my_list, 1);
    add_node(my_list, 2);
    add_node(my_list, 3);
    add_node(my_list, 4);
    add_node(my_list, 5);

    printf("Original list:\n");
    print_list(my_list);

    reverse_list(my_list);

    printf("Reversed list:\n");
    print_list(my_list);

    return 0;
}