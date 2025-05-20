//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack {
    int top;
    int capacity;
    char* data[MAX_SIZE];
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, char* data) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = data;
}

char* pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    char* data = stack->data[stack->top];
    stack->top--;
    return data;
}

char* peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is Empty\n");
        return NULL;
    }
    return stack->data[stack->top];
}

void destroyStack(Stack* stack) {
    free(stack);
}

int main() {
    Stack* stack = createStack(MAX_SIZE);
    push(stack, "Claude");
    push(stack, "Shannon");
    push(stack, "Data");
    push(stack, "Structures");
    printf("Top element is: %s\n", peek(stack));
    pop(stack);
    printf("Top element after pop is: %s\n", peek(stack));
    destroyStack(stack);
    return 0;
}