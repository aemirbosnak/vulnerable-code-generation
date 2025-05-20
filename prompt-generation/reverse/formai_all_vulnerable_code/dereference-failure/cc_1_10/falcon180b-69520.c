//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack* stack) {
    int data = -1;
    if (stack->top!= NULL) {
        Node* temp = stack->top;
        data = temp->data;
        stack->top = temp->next;
        free(temp);
    }
    return data;
}

void display_stack(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display_stack(stack);
    pop(stack);
    display_stack(stack);
    pop(stack);
    display_stack(stack);
    pop(stack);
    display_stack(stack);
    return 0;
}