//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define STACK_SIZE 100

typedef struct {
    int top;
    int *stack;
} Stack;

void initialize_stack(Stack *s) {
    s->top = -1;
    s->stack = (int *) malloc(STACK_SIZE * sizeof(int));
}

void push(Stack *s, int value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack s) {
    if (s.top == -1) {
        printf("Empty Stack\n");
    } else {
        printf("Stack: ");
        for (int i = s.top; i >= 0; i--) {
            printf("%d ", s.stack[i]);
        }
        printf("\n");
    }
}

void move_tower(int n, Stack *src, Stack *dest, Stack *aux) {
    if (n == 1) {
        push(dest, pop(src));
        return;
    }
    move_tower(n - 1, src, aux, dest);
    push(dest, pop(src));
    move_tower(n - 1, aux, dest, src);
}

int main() {
    Stack src, dest, aux;
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    srand(time(NULL));
    int disks[n];
    for (int i = 0; i < n; i++) {
        disks[i] = rand() % 100;
    }
    printf("Initial Tower:\n");
    for (int i = n - 1; i >= 0; i--) {
        push(&src, disks[i]);
        print_stack(src);
    }
    printf("Moving Tower to Destination:\n");
    move_tower(n, &src, &dest, &aux);
    print_stack(dest);
    return 0;
}