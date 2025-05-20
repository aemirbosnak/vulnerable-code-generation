//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 50
#define MAX_ARRAY_SIZE 10

// Structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to allocate memory for a node
Node* allocate_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to free memory for a node
void free_node(Node* node) {
    free(node);
}

// Function to allocate memory for an array
int* allocate_array(int size) {
    int* array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
    return array;
}

// Function to free memory for an array
void free_array(int* array) {
    free(array);
}

// Function to allocate memory for a string
char* allocate_string(int length) {
    char* string = (char*) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + (rand() % 26);
    }
    string[length] = '\0';
    return string;
}

// Function to free memory for a string
void free_string(char* string) {
    free(string);
}

int main() {
    // Allocate memory for a linked list of integers
    Node* head = allocate_node(1);
    head->next = allocate_node(2);
    head->next->next = allocate_node(3);
    head->next->next->next = allocate_node(4);

    // Allocate memory for an array of integers
    int* array = allocate_array(5);
    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;
    }

    // Allocate memory for a string
    char* string = allocate_string(20);

    // Print the contents of the linked list, array, and string
    printf("Linked list: ");
    for (Node* current = head; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");

    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("String: %s\n", string);

    // Free the memory allocated for the linked list, array, and string
    free_node(head);
    free_array(array);
    free_string(string);

    return 0;
}