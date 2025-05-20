//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
} Stack;

// A utility function to create a stack of given capacity
Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// A utility function to push a value onto a stack
void push(Stack *stack, int value)
{
    if (stack->top == stack->capacity - 1) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// A utility function to pop a value from a stack
int pop(Stack *stack)
{
    if (stack->top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// A function to move the top element of one stack to another stack
void move(Stack *fromStack, Stack *toStack)
{
    int value = pop(fromStack);
    push(toStack, value);
}

// A function to print the contents of a stack
void printStack(Stack *stack)
{
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// A function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, Stack *fromStack, Stack *toStack, Stack *auxStack)
{
    if (n == 1) {
        move(fromStack, toStack);
        return;
    }
    towerOfHanoi(n - 1, fromStack, auxStack, toStack);
    move(fromStack, toStack);
    towerOfHanoi(n - 1, auxStack, toStack, fromStack);
}

// A utility function to create a stack of given capacity and push the given values onto the stack
Stack *createAndPush(int n)
{
    Stack *stack = createStack(n);
    for (int i = n; i >= 1; i--) {
        push(stack, i);
    }
    return stack;
}

// A utility function to print the stacks
void printStacks(Stack *fromStack, Stack *toStack, Stack *auxStack)
{
    printf("From: ");
    printStack(fromStack);
    printf("To: ");
    printStack(toStack);
    printf("Aux: ");
    printStack(auxStack);
    printf("\n");
}

int main()
{
    int n = 3;

    Stack *fromStack = createAndPush(n);
    Stack *toStack = createStack(n);
    Stack *auxStack = createStack(n);

    printStacks(fromStack, toStack, auxStack);
    towerOfHanoi(n, fromStack, toStack, auxStack);
    printStacks(fromStack, toStack, auxStack);

    return 0;
}