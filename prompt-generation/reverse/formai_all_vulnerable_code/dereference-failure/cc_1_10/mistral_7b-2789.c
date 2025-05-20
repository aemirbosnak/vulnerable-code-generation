//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define ALPHABET_SIZE 128
#define HASH_TABLE_SIZE 1024

typedef struct {
    int count;
    unsigned char symbol;
} hash_node;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int i, j, k;
    int sequence_length;
    int *fib_sequence = calloc(MAX_SEQUENCE_LENGTH, sizeof(int));
    hash_node *hash_table = calloc(HASH_TABLE_SIZE, sizeof(hash_node));

    sequence_length = 0;
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    printf("Fibonacci sequence of length %d:\n", MAX_SEQUENCE_LENGTH);
    for (i = 0; i < MAX_SEQUENCE_LENGTH; ++i) {
        printf("%d ", fib_sequence[i]);
        if (i >= sequence_length) {
            sequence_length++;
            fib_sequence[i + 1] = fib_sequence[i] + fib_sequence[i - 1];
        }
    }
    printf("\n");

    for (i = 0; i < sequence_length; ++i) {
        hash_table[fib_sequence[i] & HASH_TABLE_SIZE].count++;
    }

    printf("Patterns of length 2 in the Fibonacci sequence:\n");
    for (i = 0; i < HASH_TABLE_SIZE; ++i) {
        if (hash_table[i].count > 1) {
            for (j = i, k = i; k < i + ALPHABET_SIZE && k < HASH_TABLE_SIZE; ++k) {
                if (hash_table[k].symbol == j && hash_table[k].count > 1) {
                    printf("%c%c ", j, k);
                    break;
                }
            }
        }
    }
    printf("\n");

    free(hash_table);
    free(fib_sequence);

    return 0;
}