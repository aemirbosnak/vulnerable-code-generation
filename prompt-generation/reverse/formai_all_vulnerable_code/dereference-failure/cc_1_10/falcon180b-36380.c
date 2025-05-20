//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }

    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
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
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->top->data;
}

void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node* temp = stack->top;

    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;
    stack.size = 0;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    int poppedElement = pop(&stack);
    printf("Popped element is: %d\n", poppedElement);

    display(&stack);

    return 0;
}