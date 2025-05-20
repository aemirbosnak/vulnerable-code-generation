//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the linked list structure
typedef struct {
    int data;
    struct node *next;
} node;

// Define the array structure
typedef struct {
    int size;
    int capacity;
    int *data;
} array;

// Function to print the linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current!= NULL) {
        printf("Element: %d\n", current->data);
        current = current->next;
    }
}

// Function to print the array
void print_array(array *arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        printf("Element %d: %d\n", i, arr->data[i]);
    }
}

int main() {
    // Create a linked list
    node *head = NULL;
    node *current = NULL;
    for (int i = 0; i < 10; i++) {
        current = (node*)malloc(sizeof(node));
        current->data = i;
        if (head == NULL) {
            head = current;
        } else {
            current->next = head;
            head = current;
        }
    }

    // Create an array
    array *arr = (array*)malloc(sizeof(array));
    arr->size = 10;
    arr->capacity = 10;
    arr->data = (int*)malloc(sizeof(int) * arr->capacity);
    for (int i = 0; i < 10; i++) {
        arr->data[i] = i;
    }

    // Print the linked list
    printf("Linked List:\n");
    print_linked_list(head);

    // Print the array
    printf("Array:\n");
    print_array(arr);

    // Free the memory
    free(arr->data);
    free(arr);
    while (head!= NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}