//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure using linked lists
typedef struct Stack {
    Node* top;
} Stack;

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Heap overflow\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    int value = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Testing push function
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    display(&stack);

    // Testing pop function
    int value = pop(&stack);
    printf("Popped element: %d\n", value);
    display(&stack);

    // Testing stack overflow and underflow errors
    for (int i = 0; i < 10; i++) {
        push(&stack, i * 10);
    }
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}