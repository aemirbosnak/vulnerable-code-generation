//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 100
#define NUM_DISKS 6

typedef struct {
    int top;
    int *stack;
} Stack;

void push(Stack *s, int value) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void print_stack(Stack s) {
    printf("Stack: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.stack[i]);
    }
    printf("\n");
}

void move_disk(Stack *from, Stack *to, int n) {
    if (n == 1) {
        int disk = pop(from);
        push(to, disk);
        printf("Move disk %d from %s to %s\n", disk, "tower", "destination");
    } else {
        move_disk(from, to, n - 1);
        int disk = pop(from);
        push(to, disk);
        printf("Move disk %d from %s to %s\n", disk, "tower", "destination");
        move_disk(from, to, n - 1);
    }
}

int main() {
    srand(time(NULL));
    Stack from, to, temp;
    from.top = -1;
    to.top = -1;
    temp.top = -1;
    int disks[NUM_DISKS] = {5, 4, 3, 2, 1};
    for (int i = NUM_DISKS - 1; i >= 0; i--) {
        push(&from, disks[i]);
    }
    printf("Initial state:\n");
    print_stack(from);
    move_disk(&from, &to, NUM_DISKS);
    printf("Final state:\n");
    print_stack(to);
    return 0;
}