//Falcon-180B DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return '\0';
    }
    char data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isEmpty(Stack* stack) {
    if (stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Stack* stack) {
    return 0;
}

void display(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    push(stack, 'a');
    push(stack, 'b');
    push(stack, 'c');
    display(stack);
    printf("Popped element: %c\n", pop(stack));
    display(stack);
    return 0;
}