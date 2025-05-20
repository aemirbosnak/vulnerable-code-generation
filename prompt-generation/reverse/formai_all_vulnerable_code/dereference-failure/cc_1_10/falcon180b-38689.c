//Falcon-180B DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data;
    struct node* next;
};

struct stack {
    struct node* top;
};

void push(struct stack* stack, char data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

char pop(struct stack* stack) {
    char data;
    struct node* temp = stack->top;

    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }

    data = stack->top->data;
    stack->top = stack->top->next;
    free(temp);

    return data;
}

int isEmpty(struct stack* stack) {
    return (stack->top == NULL);
}

int main() {
    struct stack stack;
    stack.top = NULL;

    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C');

    printf("Top element is: %c\n", pop(&stack));
    printf("Top element is: %c\n", pop(&stack));

    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}