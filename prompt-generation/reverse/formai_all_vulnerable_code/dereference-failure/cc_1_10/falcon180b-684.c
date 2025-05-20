//Falcon-180B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    void *data;
    struct node *next;
} Node;

// Linked list structure
typedef struct list {
    Node *head;
    Node *tail;
    int size;
} List;

// Function to create a new node with given data
Node* create_node(void *data) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node to the end of the list
void add_node(List *list, void *data) {
    Node *node = create_node(data);
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Function to remove a node from the list
void remove_node(List *list, void *data) {
    Node *prev = NULL;
    Node *curr = list->head;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    if (curr == list->tail) {
        list->tail = prev;
    }
    free(curr);
    list->size--;
}

// Function to print the list
void print_list(List *list) {
    Node *curr = list->head;
    while (curr!= NULL) {
        printf("%p ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    // Add some nodes to the list
    add_node(&list, (void*) 1);
    add_node(&list, (void*) 2);
    add_node(&list, (void*) 3);

    // Print the list
    print_list(&list);

    // Remove a node from the list
    remove_node(&list, (void*) 2);

    // Print the list again
    print_list(&list);

    return 0;
}