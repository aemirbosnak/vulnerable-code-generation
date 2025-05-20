//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure to hold a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to allocate memory for a node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to free memory for a node
void freeNode(struct Node* node) {
    free(node);
}

// Function to allocate memory for a linked list
struct Node** newList(int size) {
    struct Node** list = (struct Node**) malloc(sizeof(struct Node*) * size);
    for (int i = 0; i < size; i++) {
        list[i] = newNode(i);
    }
    return list;
}

// Function to free memory for a linked list
void freeList(struct Node** list) {
    for (int i = 0; list[i] != NULL; i++) {
        freeNode(list[i]);
    }
    free(list);
}

int main() {
    // Allocate memory for a linked list with 5 nodes
    struct Node** list = newList(5);

    // Set the data for each node
    list[0]->data = 1;
    list[1]->data = 2;
    list[2]->data = 3;
    list[3]->data = 4;
    list[4]->data = 5;

    // Print the linked list
    for (int i = 0; list[i] != NULL; i++) {
        printf("%d -> ", list[i]->data);
    }
    printf("\n");

    // Free memory for the linked list
    freeList(list);

    return 0;
}