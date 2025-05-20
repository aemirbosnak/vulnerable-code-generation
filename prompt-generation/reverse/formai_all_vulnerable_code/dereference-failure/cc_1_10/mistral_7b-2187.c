//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

typedef struct {
    int value;
    struct fibonacci* next;
} fibonacci;

void fibonacci_sequence(int n) {
    fibonacci* first = NULL;
    fibonacci* second = NULL;
    fibonacci* current = NULL;

    if (n <= 0) {
        printf("Invalid sequence length.\n");
        return;
    }

    if (n == 1) {
        first = malloc(sizeof(fibonacci));
        first->value = 0;
        first->next = NULL;
        printf("Fibonacci sequence of length %d:\n[%d]\n", n, first->value);
        free(first);
        return;
    }

    first = malloc(sizeof(fibonacci));
    first->value = 0;
    first->next = NULL;
    second = malloc(sizeof(fibonacci));
    second->value = 1;
    second->next = first;

    for (int i = 2; i < n; i++) {
        current = malloc(sizeof(fibonacci));
        current->value = first->value + second->value;
        current->next = second;
        second = current;
    }

    printf("Fibonacci sequence of length %d:\n", n);
    while (first != NULL) {
        printf("[%d] ", first->value);
        first = first->next;
    }
    printf("\b\b]\n");

    fibonacci* temp = first;
    while (first != NULL) {
        first = first->next;
        free(temp);
        temp = first;
    }
}

int main() {
    clock_t start, end;
    double elapsed_time;

    start = clock();
    fibonacci_sequence(N);
    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Calculation time: %f seconds\n", elapsed_time);

    return 0;
}