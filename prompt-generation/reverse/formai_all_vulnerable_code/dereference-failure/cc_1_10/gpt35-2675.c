//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for use in the Linked List
struct Node {
    int value;
    struct Node* next;
};

// Define a LinkedList structure with head and tail pointers
struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to add a new node to the end of the LinkedList
void add_node_to_tail(struct LinkedList* list, int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        // The LinkedList is empty
        list->head = new_node;
        list->tail = new_node;
    } else {
        // The LinkedList is not empty
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Function to print the contents of the LinkedList
void print_list(struct LinkedList* list) {
    struct Node* current_node = list->head;

    printf("LinkedList: ");

    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    // Initialize an empty LinkedList
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;

    // Add some nodes to the LinkedList
    add_node_to_tail(&list, 1);
    add_node_to_tail(&list, 2);
    add_node_to_tail(&list, 3);
    add_node_to_tail(&list, 4);

    // Print the contents of the LinkedList
    print_list(&list);

    return 0;
}