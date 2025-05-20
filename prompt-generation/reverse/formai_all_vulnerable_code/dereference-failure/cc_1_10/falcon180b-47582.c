//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Ada Lovelace style struct for memory management
typedef struct {
    void* data;
    size_t size;
    struct node* next;
} node;

// Function to create a new node with the given data and size
node* create_node(void* data, size_t size) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the end of the list
void add_to_list(node** head, void* data, size_t size) {
    node* new_node = create_node(data, size);
    node* temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the list
void print_list(node* head) {
    node* temp = head;
    while (temp!= NULL) {
        printf("Data: %p, Size: %zu\n", temp->data, temp->size);
        temp = temp->next;
    }
}

// Function to free all the memory allocated for the list
void free_list(node* head) {
    node* temp = head;
    while (temp!= NULL) {
        free(temp->data);
        temp = temp->next;
    }
    free(head);
}

int main() {
    node* head = NULL;

    // Add some nodes to the list
    add_to_list(&head, "Hello world!", strlen("Hello world!"));
    add_to_list(&head, "Ada Lovelace", strlen("Ada Lovelace"));

    // Print the list
    printf("List:\n");
    print_list(head);

    // Free the memory allocated for the list
    free_list(head);

    return 0;
}