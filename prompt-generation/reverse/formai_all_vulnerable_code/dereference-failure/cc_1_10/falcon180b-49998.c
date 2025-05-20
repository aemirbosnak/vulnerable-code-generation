//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define STACK_SIZE 1000

typedef struct {
    int top;
    int *stack;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
    s->stack = (int *) malloc(STACK_SIZE * sizeof(int));
}

void push(Stack *s, int value) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack *s) {
    if (s->top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void move_disk(Stack *src, Stack *dest, Stack *aux, int n) {
    if (n == 1) {
        push(dest, pop(src));
    } else {
        move_disk(src, aux, dest, n - 1);
        push(dest, pop(src));
        move_disk(aux, dest, src, n - 1);
    }
}

void hanoi(int n, Stack *src, Stack *dest, Stack *aux) {
    if (n <= 0) {
        return;
    }
    int mid = n / 2;
    hanoi(mid, src, aux, dest);
    hanoi(n - mid, src, dest, aux);
    move_disk(src, dest, aux, n);
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_DISKS + 1;
    printf("Solving Tower of Hanoi problem with %d disks\n", n);
    Stack src, dest, aux;
    init_stack(&src);
    init_stack(&dest);
    init_stack(&aux);
    push(&src, n);
    hanoi(n, &src, &dest, &aux);
    print_stack(&dest);
    return 0;
}