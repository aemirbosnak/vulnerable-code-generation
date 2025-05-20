//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (stack->top == NULL) {
        stack->top = new_node;
    } else {
        Node* temp = stack->top;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

int is_empty(Stack* stack) {
    return stack->top == NULL;
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Size of stack: %d\n", stack->size);
    printf("Top element of stack: %d\n", peek(stack));
    pop(stack);
    printf("Size of stack after popping: %d\n", stack->size);
    printf("Top element of stack after popping: %d\n", peek(stack));
    return 0;
}