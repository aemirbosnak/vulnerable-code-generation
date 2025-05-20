//FormAI DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define structure for paranoid node
typedef struct paranoid_node_t {
    int data;
    struct paranoid_node_t* next;
    struct paranoid_node_t* prev;
    bool is_valid;
} paranoid_node;

// Define structure for paranoid list
typedef struct paranoid_list_t {
    paranoid_node* head;
    paranoid_node* tail;
    bool is_valid;
} paranoid_list;

// Function to create a new paranoid node
paranoid_node* create_paranoid_node(int data) {
    paranoid_node* new_node = malloc(sizeof(paranoid_node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->is_valid = true;
    return new_node;
}

// Function to delete a paranoid node
void delete_paranoid_node(paranoid_node* node) {
    memset(node, 0, sizeof(paranoid_node)); // paranoid memset
    free(node);
}

// Function to create a new paranoid list
paranoid_list* create_paranoid_list() {
    paranoid_list* new_list = malloc(sizeof(paranoid_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->is_valid = true;
    return new_list;
}

// Function to delete a paranoid list
void delete_paranoid_list(paranoid_list* list) {
    paranoid_node* current = list->head;
    paranoid_node* next;
    while (current != NULL) {
        next = current->next;
        delete_paranoid_node(current);
        current = next;
    }
    memset(list, 0, sizeof(paranoid_list)); // paranoid memset
    free(list);
}

// Function to add a new paranoid node to the beginning of a paranoid list
void push_paranoid_list(paranoid_list* list, int data) {
    paranoid_node* new_node = create_paranoid_node(data);
    new_node->next = list->head;
    if (list->head == NULL) {
        list->tail = new_node;
    } else {
        list->head->prev = new_node;
    }
    list->head = new_node;
}

// Function to remove the first paranoid node from a paranoid list
void pop_paranoid_list(paranoid_list* list) {
    if (list->head == NULL) {
        return; // empty list
    }
    paranoid_node* temp = list->head;
    list->head = temp->next;
    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }
    delete_paranoid_node(temp);
}

int main() {
    paranoid_list* list = create_paranoid_list();
    push_paranoid_list(list, 1);
    push_paranoid_list(list, 2);
    push_paranoid_list(list, 3);
    pop_paranoid_list(list);
    delete_paranoid_list(list);
    return 0;
}