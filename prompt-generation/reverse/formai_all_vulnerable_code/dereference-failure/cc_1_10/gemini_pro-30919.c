//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    Node *old_top = stack->top;
    int value = old_top->value;
    stack->top = old_top->next;
    free(old_top);
    return value;
}

int main() {
    // Initialize the stacks
    Stack a;
    Stack b;
    Stack c;
    a.top = NULL;
    b.top = NULL;
    c.top = NULL;

    // Push the initial disks onto stack A
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    for (int i = num_disks; i >= 1; i--) {
        push(&a, i);
    }

    // Perform the Tower of Hanoi moves
    int num_moves = 0;
    while (c.top != NULL) {
        // Move the smallest disk from the source stack to the destination stack
        Stack *source_stack;
        Stack *destination_stack;
        if (a.top != NULL && (b.top == NULL || a.top->value < b.top->value)) {
            source_stack = &a;
            destination_stack = &b;
        } else if (b.top != NULL && (c.top == NULL || b.top->value < c.top->value)) {
            source_stack = &b;
            destination_stack = &c;
        } else if (c.top != NULL && (a.top == NULL || c.top->value < a.top->value)) {
            source_stack = &c;
            destination_stack = &a;
        }
        push(destination_stack, pop(source_stack));

        // Increment the number of moves
        num_moves++;
    }

    // Print the number of moves
    printf("The number of moves is: %d\n", num_moves);

    return 0;
}