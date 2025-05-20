//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure definition
typedef struct list {
    Node* head;
    int size;
} List;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new empty list
List* create_list() {
    List* new_list = (List*) malloc(sizeof(List));
    if (new_list == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node at the end of the list
void add_node(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    }
    else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Function to search for a node with the given data in the list
Node* search_node(List* list, int data) {
    Node* temp = list->head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void print_list(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    List* my_list = create_list();
    add_node(my_list, 10);
    add_node(my_list, 20);
    add_node(my_list, 30);
    add_node(my_list, 40);
    add_node(my_list, 50);
    print_list(my_list);

    Node* result = search_node(my_list, 30);
    if (result!= NULL) {
        printf("Found node with data: %d\n", result->data);
    }
    else {
        printf("Node not found\n");
    }

    return 0;
}