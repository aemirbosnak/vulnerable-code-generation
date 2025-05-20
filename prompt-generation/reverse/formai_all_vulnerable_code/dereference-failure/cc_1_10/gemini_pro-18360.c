//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Random number generator
static unsigned int seed = 1;
unsigned int rand32(void) {
    seed = seed * 1103515245 + 12345;
    return seed >> 16;
}

// Benchmarking function
struct node {
    int value;
    struct node *next;
};
int benchmark(int n) {
    struct node *head = NULL;
    struct node *curr = NULL;
    for (int i = 0; i < n; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = rand32();
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            curr = new_node;
        } else {
            curr->next = new_node;
            curr = new_node;
        }
    }
    int sum = 0;
    curr = head;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <number of elements>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    clock_t start = clock();
    int result = benchmark(n);
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", elapsed);
    printf("Result: %d\n", result);
    return EXIT_SUCCESS;
}