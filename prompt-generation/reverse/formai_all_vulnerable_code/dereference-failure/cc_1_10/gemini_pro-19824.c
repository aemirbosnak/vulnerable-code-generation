//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 3
#define NUM_DISKS 3

typedef struct {
    int num_disks;
    int *disks;
} stack;

stack *create_stack(int num_disks) {
    stack *new_stack = malloc(sizeof(stack));
    new_stack->num_disks = num_disks;
    new_stack->disks = malloc(sizeof(int) * num_disks);
    return new_stack;
}

void push(stack *s, int disk) {
    if (s->num_disks == STACK_SIZE) {
        printf("Error: stack is full\n");
        return;
    }
    s->disks[s->num_disks++] = disk;
}

int pop(stack *s) {
    if (s->num_disks == 0) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return s->disks[--s->num_disks];
}

int peek(stack *s) {
    if (s->num_disks == 0) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return s->disks[s->num_disks - 1];
}

void move_disk(stack *from, stack *to) {
    int disk = pop(from);
    push(to, disk);
}

void move_disks(stack *from, stack *to, stack *aux, int num_disks) {
    if (num_disks == 1) {
        move_disk(from, to);
    } else {
        move_disks(from, aux, to, num_disks - 1);
        move_disk(from, to);
        move_disks(aux, to, from, num_disks - 1);
    }
}

void print_stack(stack *s) {
    for (int i = s->num_disks - 1; i >= 0; i--) {
        printf("%d ", s->disks[i]);
    }
    printf("\n");
}

int main() {
    stack *a = create_stack(STACK_SIZE);
    stack *b = create_stack(STACK_SIZE);
    stack *c = create_stack(STACK_SIZE);

    for (int i = NUM_DISKS; i >= 1; i--) {
        push(a, i);
    }

    move_disks(a, c, b, NUM_DISKS);

    print_stack(a);
    print_stack(b);
    print_stack(c);

    return 0;
}