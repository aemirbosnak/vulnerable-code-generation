//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

void init_stack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool is_empty(Stack* stack) {
    return stack->top == NULL;
}

bool is_full(Stack* stack) {
    return stack->size == MAX_SIZE;
}

void push(Stack* stack, int data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

void print_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        Node* temp = stack->top;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    init_stack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    print_stack(&stack);

    int popped_element = pop(&stack);
    printf("Popped element is: %d\n", popped_element);

    print_stack(&stack);

    return 0;
}