//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

typedef struct {
    Node *array;
    int size;
} Stack;

void push(Stack *stack, int value) {
    if (stack->size == MAX_SIZE) {
        printf("Error: Stack overflow.\n");
        return;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->index = stack->size;
    stack->array[stack->size] = *node;
    stack->size++;
}

int pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Error: Stack underflow.\n");
        return -1;
    }
    Node *node = &stack->array[stack->size - 1];
    int value = node->data;
    stack->size--;
    free(node);
    return value;
}

void printStack(Stack *stack) {
    printf("Stack: ");
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->array[i].data);
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.size = 0;
    stack.array = (Node *)malloc(MAX_SIZE * sizeof(Node));
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);
    int value = pop(&stack);
    printf("Popped value: %d\n", value);
    printStack(&stack);
    return 0;
}