//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct linked_list {
    Node* head;
} LinkedList;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->head = NULL;
    return new_list;
}

// Function to add a node to the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

// Function to print the linked list
void print_linked_list(LinkedList* list) {
    Node* current_node = list->head;
    while (current_node!= NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverse_linked_list(LinkedList* list) {
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

// Function to delete a node from the linked list
void delete_node(LinkedList* list, int data) {
    Node* prev_node = NULL;
    Node* current_node = list->head;
    while (current_node!= NULL && current_node->data!= data) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node!= NULL) {
        prev_node->next = current_node->next;
        free(current_node);
    }
}

// Function to search for a node in the linked list
bool search_node(LinkedList* list, int data) {
    Node* current_node = list->head;
    while (current_node!= NULL) {
        if (current_node->data == data) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

// Function to sort the linked list
void sort_linked_list(LinkedList* list) {
    Node* current_node = list->head;
    while (current_node!= NULL) {
        Node* next_node = current_node->next;
        while (next_node!= NULL && current_node->data > next_node->data) {
            int temp_data = current_node->data;
            current_node->data = next_node->data;
            next_node->data = temp_data;
            current_node = next_node;
            next_node = current_node->next;
        }
        current_node = next_node;
    }
}

int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 5);
    add_node(list, 3);
    add_node(list, 7);
    add_node(list, 2);
    add_node(list, 8);
    add_node(list, 1);
    print_linked_list(list);
    reverse_linked_list(list);
    print_linked_list(list);
    delete_node(list, 3);
    print_linked_list(list);
    sort_linked_list(list);
    print_linked_list(list);
    return 0;
}