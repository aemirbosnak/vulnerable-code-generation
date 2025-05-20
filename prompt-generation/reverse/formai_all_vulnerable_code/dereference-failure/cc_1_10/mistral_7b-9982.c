//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#define MAX_DEPTH 35

typedef struct fib_t {
    int value;
    struct fib_t *prev;
} fib_t;

void fibonacci(int depth, fib_t **fib_head) {
    fib_t *new_fib, *curr, *prev;

    if (depth < 0 || depth > MAX_DEPTH) {
        printf("Invalid depth. Depth should be between 0 and %d\n", MAX_DEPTH);
        exit(EXIT_FAILURE);
    }

    if (depth <= 0) {
        *fib_head = NULL;
        return;
    }

    if (*fib_head == NULL) {
        *fib_head = malloc(sizeof(fib_t));
        (*fib_head)->value = 0;
        (*fib_head)->prev = NULL;
    } else {
        curr = *fib_head;
        prev = NULL;

        while (curr->prev != NULL) {
            prev = curr;
            curr = curr->prev;
        }

        new_fib = malloc(sizeof(fib_t));
        new_fib->value = curr->value + curr->prev->value;
        new_fib->prev = curr;
        curr->prev = new_fib;
    }

    fibonacci(depth - 1, fib_head);
}

int main() {
    fib_t *fib_head = NULL;
    fibonacci(10, &fib_head);

    fib_t *curr = fib_head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->prev;
    }

    printf("\n");

    fib_t *to_free = fib_head;
    while (to_free != NULL) {
        fib_t *next = to_free->prev;
        free(to_free);
        to_free = next;
    }

    return EXIT_SUCCESS;
}