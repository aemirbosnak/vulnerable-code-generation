//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int *arr;
    int top;
    int capacity;
};

struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->arr = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void towerOfHanoi(int disks, struct Stack *src, struct Stack *dst, struct Stack *aux) {
    if (disks == 1) {
        int data = pop(src);
        push(dst, data);
        printf("Move disk %d from rod %d to rod %d\n", data, src->capacity, dst->capacity);
        return;
    }

    towerOfHanoi(disks - 1, src, aux, dst);
    int data = pop(src);
    push(dst, data);
    printf("Move disk %d from rod %d to rod %d\n", data, src->capacity, dst->capacity);
    towerOfHanoi(disks - 1, aux, dst, src);
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    struct Stack *src = createStack(disks);
    struct Stack *dst = createStack(disks);
    struct Stack *aux = createStack(disks);

    for (int i = disks; i >= 1; i--) {
        push(src, i);
    }

    towerOfHanoi(disks, src, dst, aux);

    return 0;
}