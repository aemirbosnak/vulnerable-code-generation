//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node* next;
};

// Define the structure of a linked list
struct linked_list {
    struct node* head;
    struct node* tail;
    int size;
};

// Function to create a new node with the given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty linked list
struct linked_list* create_linked_list() {
    struct linked_list* new_list = (struct linked_list*)malloc(sizeof(struct linked_list));
    if (new_list == NULL) {
        printf("Error: Failed to allocate memory for new linked list.\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node to the end of the linked list
void add_node(struct linked_list* list, int data) {
    struct node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Function to remove a node with the given data from the linked list
void remove_node(struct linked_list* list, int data) {
    struct node* current = list->head;
    struct node* previous = NULL;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Node with data %d not found in the linked list.\n", data);
    } else if (previous == NULL) {
        list->head = current->next;
        if (list->head!= NULL) {
            list->head->next = NULL;
        } else {
            list->tail = NULL;
        }
    } else {
        previous->next = current->next;
        if (previous->next!= NULL) {
            previous->next->next = NULL;
        } else {
            list->tail = previous;
        }
    }
    list->size--;
}

// Function to print the contents of the linked list
void print_list(struct linked_list* list) {
    printf("Linked List Contents:\n");
    struct node* current = list->head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the usage of the linked list functions
int main() {
    struct linked_list* list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    print_list(list);
    remove_node(list, 2);
    print_list(list);
    return 0;
}