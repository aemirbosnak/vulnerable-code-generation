//FormAI DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node structure
typedef struct node {
    int value;
    struct node* next;
} Node;

// Define a LinkedList structure
typedef struct linked_list {
    Node* head;
} LinkedList;

// Initialize an empty LinkedList
LinkedList* init_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

// Add a node with the given value to the front of the list
void add_to_front(LinkedList* list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
}

// Remove the first node in the list and return its value
int remove_from_front(LinkedList* list) {
    Node* curr_node = list->head;
    int value = curr_node->value;
    list->head = curr_node->next;
    free(curr_node);
    return value;
}

// Print the current state of the list
void print_list(LinkedList* list) {
    printf("\nCurrent State of LinkedList: [ ");

    Node* curr_node = list->head;
    while (curr_node != NULL) {
        printf("%d ", curr_node->value);
        curr_node = curr_node->next;
    }

    printf("]\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    LinkedList* list = init_list(); // Initialize an empty list

    // Add random values to the list
    for (int i = 0; i < 10; i++) {
        add_to_front(list, rand() % 100);
        print_list(list); // Print the list after each addition
    }

    // Remove values from the list until empty
    while (list->head != NULL) {
        int removed_value = remove_from_front(list);
        printf("\nRemoved value: %d\n", removed_value);
        print_list(list); // Print the list after each removal
    }

    return 0;
}