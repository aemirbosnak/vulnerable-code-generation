//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Stack structure definition
struct Stack {
    struct Node* top;
};

// Stack initialization
void init(struct Stack* stack) {
    stack->top = NULL;
}

// Push operation
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop operation
int pop(struct Stack* stack) {
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Display stack elements
void display(struct Stack stack) {
    struct Node* temp = stack.top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Stack elements before popping: ");
    display(stack);

    int poppedValue = pop(&stack);
    printf("\nPopped value: %d\n", poppedValue);

    printf("Stack elements after popping: ");
    display(stack);

    return 0;
}