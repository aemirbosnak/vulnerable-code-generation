//Falcon-180B DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the structure of a stack node
typedef struct {
    int data;
    struct stackNode* next;
} StackNode;

// Define the structure of a stack
typedef struct {
    StackNode* top;
    int size;
} Stack;

// Initialize an empty stack
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Push an integer onto the stack
void push(Stack* stack, int data) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop an integer from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Display the contents of the stack
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    StackNode* current = stack->top;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Reverse the order of the elements in the stack
void reverseStack(Stack* stack) {
    StackNode* prev = NULL;
    StackNode* current = stack->top;
    while (current!= NULL) {
        StackNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->top = prev;
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Original stack:\n");
    display(&stack);

    reverseStack(&stack);

    printf("Reversed stack:\n");
    display(&stack);

    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);

    return 0;
}