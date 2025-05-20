//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

enum {
    STACK_A,
    STACK_B,
    STACK_C
};

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

void createStack(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (int *)malloc(capacity * sizeof(int));
}

void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack *s) {
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void moveDisk(Stack *src, Stack *dest, int n) {
    if (n == 1) {
        int value = pop(src);
        push(dest, value);
        printf("Move disk %d from stack %d to stack %d\n", value, STACK_A, STACK_C);
    } else {
        moveDisk(src, dest, n - 1);
        int value = pop(src);
        push(dest, value);
        printf("Move disk %d from stack %d to stack %d\n", value, STACK_A, STACK_C);
        moveDisk(src, dest, n - 1);
    }
}

int main() {
    Stack stackA, stackB, stackC;
    createStack(&stackA, MAX_DISKS);
    createStack(&stackB, MAX_DISKS);
    createStack(&stackC, MAX_DISKS);

    for (int i = MAX_DISKS; i >= 1; i--) {
        push(&stackA, i);
    }

    printf("Initial state:\n");
    printf("Stack A: ");
    for (int i = stackA.top; i >= 0; i--) {
        printf("%d ", stackA.stack[i]);
    }
    printf("\n");

    moveDisk(&stackA, &stackC, MAX_DISKS);

    printf("Final state:\n");
    printf("Stack A: ");
    for (int i = stackA.top; i >= 0; i--) {
        printf("%d ", stackA.stack[i]);
    }
    printf("\n");
    printf("Stack C: ");
    for (int i = stackC.top; i >= 0; i--) {
        printf("%d ", stackC.stack[i]);
    }
    printf("\n");

    return 0;
}