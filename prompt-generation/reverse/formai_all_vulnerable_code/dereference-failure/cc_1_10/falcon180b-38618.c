//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node for Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Stack
typedef struct Stack {
    int top;
    Node** stackArray;
} Stack;

// Initialize an Empty Stack
void init(Stack* stack) {
    stack->top = -1;
    stack->stackArray = (Node**) malloc(10 * sizeof(Node*)); // Allocate Memory for Stack
}

// Check if Stack is Empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an Element into the Stack
void push(Stack* stack, int data) {
    if (stack->top >= 9) { // Check if Stack is Full
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->stackArray[stack->top] = (Node*) malloc(sizeof(Node)); // Allocate Memory for Node
    stack->stackArray[stack->top]->data = data;
    stack->stackArray[stack->top]->next = NULL;
}

// Pop an Element from the Stack
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return;
    }
    Node* temp = stack->stackArray[stack->top];
    free(temp);
    stack->top--;
}

// Display the Elements in the Stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return;
    }
    Node* temp = stack->stackArray[stack->top];
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    display(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    display(&stack);
    return 0;
}