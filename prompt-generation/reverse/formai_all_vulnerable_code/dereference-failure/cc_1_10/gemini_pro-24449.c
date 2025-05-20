//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} stack;

stack *stack_new(int size) {
    stack *s = malloc(sizeof(stack));
    s->array = malloc(sizeof(int) * size);
    s->size = size;
    return s;
}

void stack_free(stack *s) {
    free(s->array);
    free(s);
}

int stack_push(stack *s, int value) {
    if (s->size <= 0) {
        return -1;
    }
    s->array[s->size++] = value;
    return 0;
}

int stack_pop(stack *s) {
    if (s->size <= 0) {
        return -1;
    }
    return s->array[--s->size];
}

int stack_peek(stack *s) {
    if (s->size <= 0) {
        return -1;
    }
    return s->array[s->size - 1];
}

int tower_of_hanoi(int n, stack *from, stack *to, stack *aux) {
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        stack_push(to, stack_pop(from));
        return 0;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    stack_push(to, stack_pop(from));
    tower_of_hanoi(n - 1, aux, to, from);
    return 0;
}

int main(void) {
    int n;
    stack *from, *to, *aux;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    from = stack_new(n);
    to = stack_new(n);
    aux = stack_new(n);

    for (int i = n; i > 0; i--) {
        stack_push(from, i);
    }

    tower_of_hanoi(n, from, to, aux);

    printf("The disks have been moved from the first stack to the third stack.\n");

    stack_free(from);
    stack_free(to);
    stack_free(aux);

    return 0;
}