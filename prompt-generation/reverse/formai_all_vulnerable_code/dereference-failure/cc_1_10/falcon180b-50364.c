//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new empty linked list
List* create_list() {
    List* new_list = (List*) malloc(sizeof(List));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Add a new node to the end of the linked list
void add_node(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Print the contents of the linked list
void print_list(List* list) {
    Node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free the memory used by the linked list and its nodes
void destroy_list(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        Node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    free(list);
}

// Test the linked list implementation
int main() {
    List* my_list = create_list();
    add_node(my_list, 1);
    add_node(my_list, 2);
    add_node(my_list, 3);
    print_list(my_list);
    destroy_list(my_list);
    return 0;
}