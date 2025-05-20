//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define STACK_SIZE 100

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

void init_stack(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (int *) malloc(capacity * sizeof(int));
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
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack *s) {
    if (s->top == -1) {
        printf("Empty stack\n");
    } else {
        printf("Stack: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->stack[i]);
        }
        printf("\n");
    }
}

void move_disk(int n, char from_rod, char to_rod, char aux_rod, Stack *stack) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    } else {
        printf("Move %d disks from rod %c to rod %c using rod %c as auxiliary\n", n, from_rod, to_rod, aux_rod);
        move_disk(n - 1, from_rod, aux_rod, to_rod, stack);
        push(stack, n);
        move_disk(n - 1, aux_rod, to_rod, from_rod, stack);
        pop(stack);
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_DISKS + 1;

    printf("Tower of Hanoi problem with %d disks:\n", n);

    Stack stack;
    init_stack(&stack, STACK_SIZE);

    move_disk(n, 'A', 'C', 'B', &stack);

    print_stack(&stack);

    return 0;
}