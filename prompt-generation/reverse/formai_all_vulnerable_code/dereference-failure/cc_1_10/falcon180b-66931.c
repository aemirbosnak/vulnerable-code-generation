//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DISKS 10
#define STACK_SIZE 10000

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
    s->capacity = STACK_SIZE;
    s->stack = (int *)malloc(s->capacity * sizeof(int));
}

void push(Stack *s, int x) {
    if (s->top >= s->capacity - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    s->top++;
    s->stack[s->top] = x;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        exit(0);
    }
    int x = s->stack[s->top];
    s->top--;
    return x;
}

void move_tower(int n, char from_rod, char to_rod, char aux_rod) {
    Stack s;
    init_stack(&s);

    int steps = 0;

    for (int i = n; i > 0; i--) {
        push(&s, i);
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            push(&s, pop(&s));
        }
        pop(&s);
        push(&s, pop(&s));
    }

    for (int i = 1; i <= n; i++) {
        printf("%d moved from %c to %c\n", i, from_rod, to_rod);
        steps++;
    }

    printf("Total number of steps: %d\n", steps);
}

int main() {
    srand(time(NULL));

    int n = rand() % NUM_DISKS + 1;
    char from_rod = 'A' + rand() % 3;
    char to_rod = 'A' + rand() % 3;
    char aux_rod = 'A' + (rand() % 3 + 1) % 3;

    printf("Solving Tower of Hanoi problem with %d disks\n", n);
    printf("Moving the tower from %c to %c using %c as auxiliary rod\n", from_rod, to_rod, aux_rod);

    move_tower(n, from_rod, to_rod, aux_rod);

    return 0;
}