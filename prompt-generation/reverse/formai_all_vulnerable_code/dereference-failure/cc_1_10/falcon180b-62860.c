//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// node structure
typedef struct node {
    int data;
    int next;
} Node;

// stack structure
typedef struct stack {
    Node *top;
    int size;
} Stack;

// create a new node
Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = -1;
    return node;
}

// create a new stack
Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// push a node onto the stack
void push(Stack *stack, int data) {
    Node *node = createNode(data);
    if (stack->size >= MAX_SIZE) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        node->next = stack->top;
        stack->top = node;
        stack->size++;
    }
}

// pop a node from the stack
int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        Node *node = stack->top;
        int data = node->data;
        stack->top = node->next;
        free(node);
        stack->size--;
        return data;
    }
}

// check if the stack is empty
int isEmpty(Stack *stack) {
    return (stack->top == NULL);
}

// get the size of the stack
int getSize(Stack *stack) {
    return stack->size;
}

// print the stack
void printStack(Stack *stack) {
    Node *node = stack->top;
    printf("Stack: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("Size of stack: %d\n", getSize(stack));
    printStack(stack);
    int data = pop(stack);
    printf("Popped data: %d\n", data);
    printStack(stack);
    printf("Size of stack: %d\n", getSize(stack));
    return 0;
}