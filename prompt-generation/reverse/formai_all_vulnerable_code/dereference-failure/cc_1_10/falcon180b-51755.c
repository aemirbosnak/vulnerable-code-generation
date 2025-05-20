//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a linked list structure
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Function to initialize a linked list
void linked_list_init(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

// Function to add a node to the end of a linked list
void linked_list_add(LinkedList* list, int data) {
    // Create a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // Check if the list is empty
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        // Traverse the list to find the last node
        Node* current_node = list->head;
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        // Add the new node to the end of the list
        current_node->next = new_node;
    }
    // Increment the size of the list
    list->size++;
}

// Function to print a linked list
void linked_list_print(LinkedList* list) {
    // Traverse the list and print each node's data
    Node* current_node = list->head;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to free all memory used by a linked list
void linked_list_free(LinkedList* list) {
    // Traverse the list and free each node's memory
    Node* current_node = list->head;
    while (current_node!= NULL) {
        Node* temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    list->head = NULL;
    list->size = 0;
}

int main() {
    // Initialize a linked list
    LinkedList list;
    linked_list_init(&list);

    // Add some nodes to the list
    linked_list_add(&list, 1);
    linked_list_add(&list, 2);
    linked_list_add(&list, 3);

    // Print the list
    printf("List: ");
    linked_list_print(&list);

    // Free the memory used by the list
    linked_list_free(&list);

    return 0;
}