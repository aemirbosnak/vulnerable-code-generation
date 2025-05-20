//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FIB_NUM 20

typedef struct fib_stack {
    int data;
    struct fib_stack *next;
} fib_stack;

void fibonacci_stack(int limit) {
    fib_stack *stack = NULL;
    int i = 0, a = 0, b = 1;

    printf("Fibonacci sequence up to %d:\n", limit);

    while (a < limit) {
        printf("%d ", a);
        fib_stack *new_node = (fib_stack *) malloc(sizeof(fib_stack));
        new_node->data = a;
        new_node->next = stack;
        stack = new_node;
        i++;

        int temp = a + b;
        a = b;
        b = temp;
    }

    while (stack != NULL) {
        fib_stack *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

double time_elapsed(clock_t start, clock_t end) {
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    clock_t start, end;

    fibonacci_stack(MAX_FIB_NUM);

    start = clock();
    fibonacci_stack(MAX_FIB_NUM);
    end = clock();

    printf("Time elapsed: %.9f seconds\n", time_elapsed(start, end));

    return 0;
}