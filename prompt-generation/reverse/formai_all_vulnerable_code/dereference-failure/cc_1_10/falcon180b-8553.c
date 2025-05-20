//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of the node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the linked list
typedef struct list {
    Node* head;
} List;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to append a node to the end of the list
void append_node(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* last_node = list->head;
        while (last_node->next!= NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

// Function to prepend a node to the beginning of the list
void prepend_node(List* list, int data) {
    Node* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

// Function to print the list
void print_list(List* list) {
    Node* current_node = list->head;
    while (current_node!= NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverse_list(List* list) {
    Node* current_node = list->head;
    Node* previous_node = NULL;
    while (current_node!= NULL) {
        Node* next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    list->head = previous_node;
}

int main() {
    List* my_list = (List*)malloc(sizeof(List));
    if (my_list == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    my_list->head = NULL;
    append_node(my_list, 10);
    prepend_node(my_list, 20);
    append_node(my_list, 30);
    prepend_node(my_list, 40);
    print_list(my_list);
    reverse_list(my_list);
    print_list(my_list);
    free(my_list);
    return 0;
}