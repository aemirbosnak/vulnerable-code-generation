//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define STACK_SIZE 100

void push(int *stack, int *top, int value) {
    if (*top >= STACK_SIZE - 1) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    *(stack + (*top)++) = value;
}

int pop(int *stack, int *top) {
    if (*top <= 0) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return *(stack + (*top)--);
}

void print_stack(int *stack, int top) {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    int *stack1 = malloc(STACK_SIZE * sizeof(int));
    int *stack2 = malloc(STACK_SIZE * sizeof(int));
    int top1 = -1, top2 = -1;

    push(stack1, &top1, n);

    while (top1!= -1) {
        int disk = pop(stack1, &top1);

        if (disk == n) {
            printf("Move disk %d from rod %d to rod %d\n", disk, from_rod, to_rod);
        } else {
            push(stack2, &top2, disk);
        }
    }

    while (top2!= -1) {
        int disk = pop(stack2, &top2);

        if (disk == n) {
            printf("Move disk %d from rod %d to rod %d\n", disk, to_rod, from_rod);
        } else {
            push(stack1, &top1, disk);
        }
    }

    free(stack1);
    free(stack2);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    hanoi(n, 1, 3, 2);

    return 0;
}