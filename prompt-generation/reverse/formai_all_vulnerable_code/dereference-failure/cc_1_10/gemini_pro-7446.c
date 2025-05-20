//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the Towers of Hanoi problem
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node to the top of a stack
void push(node **stack, int data) {
    node *new_node = create_node(data);
    new_node->next = *stack;
    *stack = new_node;
}

// Function to pop a node from the top of a stack
int pop(node **stack) {
    if (*stack == NULL) {
        return -1;
    }
    int data = (*stack)->data;
    *stack = (*stack)->next;
    return data;
}

// Function to print the contents of a stack
void print_stack(node *stack) {
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Function to solve the Towers of Hanoi problem
void towers_of_hanoi(int n, node **source, node **destination, node **auxiliary) {
    // Base case: If there is only one disk, move it from the source to the destination
    if (n == 1) {
        push(destination, pop(source));
        return;
    }

    // Recursive case:
    // 1. Move the top n-1 disks from the source to the auxiliary tower
    towers_of_hanoi(n-1, source, auxiliary, destination);

    // 2. Move the nth disk from the source to the destination tower
    push(destination, pop(source));

    // 3. Move the n-1 disks from the auxiliary tower to the destination tower
    towers_of_hanoi(n-1, auxiliary, destination, source);
}

int main() {
    // Create the three towers
    node *source = NULL;
    node *destination = NULL;
    node *auxiliary = NULL;

    // Push the disks onto the source tower
    for (int i = 0; i < 3; i++) {
        push(&source, i+1);
    }

    // Print the initial state of the towers
    printf("Source: ");
    print_stack(source);
    printf("Destination: ");
    print_stack(destination);
    printf("Auxiliary: ");
    print_stack(auxiliary);

    // Solve the Towers of Hanoi problem
    towers_of_hanoi(3, &source, &destination, &auxiliary);

    // Print the final state of the towers
    printf("\nSource: ");
    print_stack(source);
    printf("Destination: ");
    print_stack(destination);
    printf("Auxiliary: ");
    print_stack(auxiliary);

    return 0;
}