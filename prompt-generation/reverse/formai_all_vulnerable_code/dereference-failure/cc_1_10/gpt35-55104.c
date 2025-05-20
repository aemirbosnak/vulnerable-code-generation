//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Define the structure of our data node
typedef struct node {
    int data;
    struct node* next;
} NODE;

// Define the structure of our linked list
typedef struct list {
    NODE* head;
    int size;
} LIST;

// Function to create a new node
NODE* create_node(int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
LIST* create_list() {
    LIST* new_list = (LIST*)malloc(sizeof(LIST));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to insert a node at the beginning of the linked list
void insert_node(LIST* list, int data) {
    NODE* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// Function to print the list to console
void print_list(LIST* list) {
    NODE* current_node = list->head;
    printf("Linked list (size %d): ", list->size);
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to swap two nodes in a linked list
void swap_nodes(NODE** head_ref, NODE* x, NODE* y) {
    if (x == y) {
        return;
    }
    NODE* prev_x = NULL;
    NODE* current_x = *head_ref;
    while (current_x != NULL && current_x != x) {
        prev_x = current_x;
        current_x = current_x->next;
    }
    NODE* prev_y = NULL;
    NODE* current_y = *head_ref;
    while (current_y != NULL && current_y != y) {
        prev_y = current_y;
        current_y = current_y->next;
    }
    if (prev_x != NULL) {
        prev_x->next = y;
    } else {
        *head_ref = y;
    }
    if (prev_y != NULL) {
        prev_y->next = x;
    } else {
        *head_ref = x;
    }
    NODE* temp = x->next;
    x->next = y->next;
    y->next = temp;
}

// Function to perform a bubble sort on our linked list
void bubble_sort(LIST* list) {
    int swapped;
    NODE* current_node;
    NODE* last_node = NULL;
    if (list->head == NULL) {
        return;
    }
    do {
        swapped = 0;
        current_node = list->head;
        while (current_node->next != last_node) {
            if (current_node->data > current_node->next->data) {
                swap_nodes(&(list->head), current_node, current_node->next);
                swapped = 1;
            }
            current_node = current_node->next;
        }
        last_node = current_node;
    } while (swapped);
}

int main() {
    // Seed the random number generator for testing purposes
    srand(time(NULL));
    // Create a linked list and populate it with random integers
    LIST* my_list = create_list();
    for (int i = 0; i < MAX_SIZE; i++) {
        insert_node(my_list, rand() % 100);
    }
    // Print the list before sorting
    printf("Before sorting...\n");
    print_list(my_list);
    // Sort the list using bubble sort
    bubble_sort(my_list);
    // Print the list after sorting
    printf("After sorting...\n");
    print_list(my_list);
    // Free all the memory used by the linked list
    NODE* current_node = my_list->head;
    NODE* next_node;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(my_list);
    return 0;
}