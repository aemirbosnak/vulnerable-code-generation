//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

// Define the data structure for a node
typedef struct node {
    int data;
    int next;
} Node;

// Define the data structure for the linked list
typedef struct linked_list {
    Node *head;
    int size;
} LinkedList;

// Create a new linked list
LinkedList *create_linked_list() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Add a node to the end of the linked list
void add_node(LinkedList *list, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current_node = list->head;
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    list->size++;
}

// Remove a node from the linked list
void remove_node(LinkedList *list, int data) {
    Node *current_node = list->head;
    if (current_node!= NULL && current_node->data == data) {
        list->head = current_node->next;
        free(current_node);
        list->size--;
    } else {
        while (current_node!= NULL && current_node->data!= data) {
            current_node = current_node->next;
        }
        if (current_node!= NULL) {
            Node *previous_node = current_node->next;
            current_node->next = previous_node->next;
            free(previous_node);
            list->size--;
        }
    }
}

// Print the linked list
void print_linked_list(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node!= NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    LinkedList *list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    print_linked_list(list);
    remove_node(list, 2);
    print_linked_list(list);
    return 0;
}