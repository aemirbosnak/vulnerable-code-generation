//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define STACK_SIZE 100

void push(int *stack, int *top, int value) {
    if (*top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    *(stack + (*top)++) = value;
}

int pop(int *stack, int *top) {
    if (*top <= 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return *(stack + (*top)--);
}

void display(int *stack, int top) {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void towerOfHanoi(int n, char from, char to, char aux) {
    int stack[STACK_SIZE];
    int top = -1;

    push(stack, &top, n);

    printf("Move %d disks from %c to %c using %c\n", n, from, to, aux);

    while (top >= 0) {
        n = pop(stack, &top);

        if (n == 1) {
            printf("%c -> %c\n", from, to);
            push(stack, &top, n);
        } else {
            printf("%c -> %c\n", from, aux);
            push(stack, &top, n - 1);
            printf("%c -> %c\n", aux, to);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}