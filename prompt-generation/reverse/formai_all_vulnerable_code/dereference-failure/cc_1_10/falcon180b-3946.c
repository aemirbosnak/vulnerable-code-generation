//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for a node
struct node {
    int data;
    struct node* next;
};

// Define structure for a linked list
struct linked_list {
    struct node* head;
    int size;
};

// Function to create a new node with given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
struct linked_list* create_linked_list() {
    struct linked_list* new_list = (struct linked_list*) malloc(sizeof(struct linked_list));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node to the end of the linked list
void add_node(struct linked_list* list, int data) {
    struct node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Function to print the linked list
void print_linked_list(struct linked_list* list) {
    printf("Linked List:\n");
    struct node* temp = list->head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free memory used by linked list
void free_linked_list(struct linked_list* list) {
    struct node* temp = list->head;
    while (temp!= NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

int main() {
    struct linked_list* list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    add_node(list, 4);
    add_node(list, 5);
    print_linked_list(list);
    free_linked_list(list);
    return 0;
}