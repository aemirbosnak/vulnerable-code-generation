//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

void push(Stack *stack, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        exit(0);
    }
    int data = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    return stack->top->data;
}

bool isEmpty(Stack *stack) {
    if (stack->top == NULL) {
        return true;
    }
    return false;
}

void display(Stack *stack) {
    Node *temp = stack->top;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Peek: %d\n", peek(&stack));

    pop(&stack);

    display(&stack);

    printf("Peek: %d\n", peek(&stack));

    return 0;
}