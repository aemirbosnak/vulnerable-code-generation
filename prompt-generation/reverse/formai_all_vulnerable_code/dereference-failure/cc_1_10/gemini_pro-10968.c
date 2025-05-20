//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>

// Data structure to store a stack
typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

// Function to create a stack of a given capacity
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int item)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to move a disk from one stack to another
void moveDisk(Stack *from, Stack *to)
{
    int disk = pop(from);
    push(to, disk);
}

// Function to perform the Tower of Hanoi puzzle
void towerOfHanoi(int numDisks, Stack *from, Stack *to, Stack *aux)
{
    if (numDisks == 1)
    {
        moveDisk(from, to);
        return;
    }
    towerOfHanoi(numDisks - 1, from, aux, to);
    moveDisk(from, to);
    towerOfHanoi(numDisks - 1, aux, to, from);
}

// Driver code
int main()
{
    int numDisks = 3;
    Stack *from = createStack(numDisks);
    Stack *to = createStack(numDisks);
    Stack *aux = createStack(numDisks);

    for (int i = numDisks; i >= 1; i--)
    {
        push(from, i);
    }

    printf("Initial state:\n");
    printf("From: ");
    for (int i = from->top; i >= 0; i--)
    {
        printf("%d ", from->array[i]);
    }
    printf("\nTo: ");
    for (int i = to->top; i >= 0; i--)
    {
        printf("%d ", to->array[i]);
    }
    printf("\nAux: ");
    for (int i = aux->top; i >= 0; i--)
    {
        printf("%d ", aux->array[i]);
    }
    printf("\n");

    printf("\nSteps:\n");
    towerOfHanoi(numDisks, from, to, aux);

    printf("\nFinal state:\n");
    printf("From: ");
    for (int i = from->top; i >= 0; i--)
    {
        printf("%d ", from->array[i]);
    }
    printf("\nTo: ");
    for (int i = to->top; i >= 0; i--)
    {
        printf("%d ", to->array[i]);
    }
    printf("\nAux: ");
    for (int i = aux->top; i >= 0; i--)
    {
        printf("%d ", aux->array[i]);
    }
    printf("\n");

    return 0;
}