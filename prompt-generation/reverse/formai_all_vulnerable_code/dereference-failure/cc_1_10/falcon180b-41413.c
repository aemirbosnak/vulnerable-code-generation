//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
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

void init_stack(Stack *s) {
    s->top = -1;
    s->capacity = STACK_SIZE;
    s->stack = (int *)malloc(s->capacity * sizeof(int));
    if (s->stack == NULL) {
        printf("Error: Failed to allocate memory for stack.\n");
        exit(1);
    }
}

void push(Stack *s, int value) {
    if (s->top >= s->capacity - 1) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void print_stack(Stack *s) {
    if (s->top < 0) {
        printf("Empty stack.\n");
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
        push(stack, 1);
        push(stack, 0);
        push(stack, 0);
        push(stack, 1);
        push(stack, 0);
        push(stack, 0);
        push(stack, 1);
        push(stack, 0);
        push(stack, 0);
        push(stack, 1);
    } else {
        move_disk(n - 1, from_rod, aux_rod, to_rod, stack);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        push(stack, n);
    }
}

int main() {
    srand(time(NULL));
    int num_disks = rand() % MAX_DISKS + 1;
    printf("Solving Tower of Hanoi problem with %d disks...\n", num_disks);
    Stack stack;
    init_stack(&stack);
    move_disk(num_disks, 'A', 'C', 'B', &stack);
    print_stack(&stack);
    while (stack.top >= 0) {
        int value = pop(&stack);
        printf("Popped value: %d\n", value);
    }
    return 0;
}