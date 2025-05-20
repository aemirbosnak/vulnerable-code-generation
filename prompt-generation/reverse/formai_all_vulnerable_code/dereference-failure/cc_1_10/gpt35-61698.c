//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
// Data Structures Visualization Example Program
// Author: AI
// Date: 2021-10-15

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Cannot push element. Stack is full!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

void pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Cannot pop element. Stack is empty!\n");
        return;
    }
    stack->top--;
}

void display(Stack* stack) {
    if (stack->top == -1) {
        printf("Cannot display elements. Stack is empty!\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

void draw(Stack* stack) {
    printf("\n");
    printf("Stack Visualization:\n");
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        printf("|");
        if (i <= stack->top) {
            printf(" %d ", stack->data[i]);
        } else {
            printf("   ");
        }
        printf("|\n");
    }
    printf("+");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("---");
    }
    printf("+\n");
    printf("\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    draw(stack);
    push(stack, 20);
    draw(stack);
    push(stack, 30);
    draw(stack);
    push(stack, 40);
    draw(stack);

    pop(stack);
    draw(stack);
    pop(stack);
    draw(stack);

    display(stack);
    draw(stack);

    return 0;
}