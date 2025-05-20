//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Define the linked list structure
struct linked_list {
    struct node* head;
};

// Function to create a new node with given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the linked list
void add_node(struct linked_list* list, int data) {
    struct node* new_node = create_node(data);
    struct node* temp = list->head;
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the linked list
void print_list(struct linked_list* list) {
    struct node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct linked_list* list = (struct linked_list*) malloc(sizeof(struct linked_list));
    if (list == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    list->head = NULL;

    // Add some nodes to the list
    add_node(list, 10);
    add_node(list, 20);
    add_node(list, 30);
    add_node(list, 40);

    // Print the list
    printf("Original list:\n");
    print_list(list);

    // Reverse the list
    struct node* prev_node = NULL;
    struct node* curr_node = list->head;
    while (curr_node!= NULL) {
        struct node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    list->head = prev_node;

    // Print the reversed list
    printf("Reversed list:\n");
    print_list(list);

    return 0;
}