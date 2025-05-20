//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push a node onto the top of the stack
void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *top_ref;
    *top_ref = new_node;
}

// Function to pop a node from the top of the stack
int pop(struct Node** top_ref) {
    struct Node* top_node = *top_ref;
    int popped_data = top_node->data;
    struct Node* next_node = top_node->next;
    free(top_node);
    *top_ref = next_node;
    return popped_data;
}

// Function to print the stack
void printStack(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* top = NULL;

    // Push elements onto the stack
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    // Print the stack
    printf("Stack: ");
    printStack(top);

    // Pop an element from the stack
    int popped_element = pop(&top);
    printf("Popped element: %d\n", popped_element);

    // Print the stack again
    printf("Stack after popping: ");
    printStack(top);

    return 0;
}