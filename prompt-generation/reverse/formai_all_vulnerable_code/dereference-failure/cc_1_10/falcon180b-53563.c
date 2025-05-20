//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

typedef struct {
    int top;
    int* stack;
    int capacity;
} Stack;

void push(Stack* s, int value) {
    if (s->top >= s->capacity) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

void moveDisk(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c using %c\n", n, from, to, aux);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        moveDisk(1, from, to, aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    moveDisk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = n;
    stack->stack = malloc(n * sizeof(int));

    hanoi(n, 'A', 'C', 'B');

    free(stack->stack);
    free(stack);

    return 0;
}