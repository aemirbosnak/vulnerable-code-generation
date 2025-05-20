//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(Stack* stack) {
    int data;
    Node* temp_node = stack->top;
    if (temp_node == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    stack->size--;
    return data;
}

void print_stack(Stack* stack) {
    Node* current_node = stack->top;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);
    int popped_data = pop(stack);
    printf("Popped data: %d\n", popped_data);
    print_stack(stack);
    return 0;
}