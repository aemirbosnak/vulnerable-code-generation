//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define STACK_SIZE 1000

struct disk {
    int size;
    int top;
    int *stack;
};

void push(struct disk *d, int value) {
    if (d->top >= d->size) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    d->stack[++d->top] = value;
}

int pop(struct disk *d) {
    if (d->top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return d->stack[d->top--];
}

void print_stack(struct disk *d) {
    for (int i = d->top; i >= 0; i--) {
        printf("%d ", d->stack[i]);
    }
    printf("\n");
}

void move_disk(struct disk *from, struct disk *to, int n) {
    if (n == 1) {
        push(to, pop(from));
    } else {
        move_disk(from, to, n - 1);
        push(to, pop(from));
        move_disk(from, to, n - 1);
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_DISKS + 1;
    printf("Number of disks: %d\n", n);

    struct disk from, to, aux;
    from.size = n;
    from.top = -1;
    from.stack = malloc(STACK_SIZE * sizeof(int));
    to.size = n;
    to.top = -1;
    to.stack = malloc(STACK_SIZE * sizeof(int));
    aux.size = n;
    aux.top = -1;
    aux.stack = malloc(STACK_SIZE * sizeof(int));

    printf("Initial state:\n");
    print_stack(&from);

    move_disk(&from, &to, n);

    printf("\nFinal state:\n");
    print_stack(&to);

    free(from.stack);
    free(to.stack);
    free(aux.stack);

    return 0;
}