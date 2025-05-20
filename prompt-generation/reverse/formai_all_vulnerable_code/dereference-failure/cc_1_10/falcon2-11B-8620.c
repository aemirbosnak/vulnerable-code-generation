//Falcon2-11B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

// Function to print the elements of the stack
void printStack(struct Node* top) {
    while (top!= NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    // Create a new stack
    struct Node* stack = NULL;

    // Push some elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // Print the elements of the stack
    printStack(stack);

    // Pop the top element from the stack
    pop(&stack);

    // Print the elements of the stack again
    printStack(stack);

    // Free the memory used by the stack
    while (stack!= NULL) {
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}