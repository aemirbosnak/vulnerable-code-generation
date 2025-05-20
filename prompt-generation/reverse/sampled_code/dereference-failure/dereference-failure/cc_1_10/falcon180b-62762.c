//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100
#define STACK_SIZE 1000

typedef struct {
    int size;
    int capacity;
    int *stack;
} Stack;

void initStack(Stack *s) {
    s->size = 0;
    s->capacity = STACK_SIZE;
    s->stack = (int *)malloc(s->capacity * sizeof(int));
}

void push(Stack *s, int value) {
    if (s->size >= s->capacity) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[s->size++] = value;
}

int pop(Stack *s) {
    if (s->size == 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[--s->size];
}

void printStack(Stack *s) {
    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void moveDisk(int n, char from, char to, char aux) {
    Stack s;
    initStack(&s);

    printf("Move disk %d from %c to %c\n", n, from, to);
    push(&s, n);

    while (s.size > 1) {
        pop(&s);
        printf("Move disk %d from %c to %c\n", s.stack[s.size - 1], from, to);
        push(&s, s.stack[s.size - 1]);
    }

    printf("Move disk %d from %c to %c\n", s.stack[s.size - 1], from, to);
    pop(&s);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    moveDisk(n, 'A', 'C', 'B');

    return 0;
}