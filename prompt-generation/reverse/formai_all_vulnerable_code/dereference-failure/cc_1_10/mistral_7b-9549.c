//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Donald Knuth
/*
 * Title: Knuth's Shuffle Algorithm
 * Author: Anonymous
 * Compiler: gcc
 * Usage: gcc -o knuth_shuffle knuth_shuffle.c && ./knuth_shuffle <number>
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * Integers are signed by default, so we need to define an unsigned type for our
 * permutations.
 */
typedef uint32_t perm_t;

/*
 * Define a constant for the maximum size of the array that will be used to store
 * the shuffle sequence.
 */
#define MAX_PERM_SIZE (1 << 16)

/*
 * Define a structure for our permutation arrays.
 */
struct permutation {
    perm_t *p;
    size_t size;
};

/*
 * Initialize a new permutation array with the given size.
 */
void permutation_init(struct permutation *p, size_t size) {
    p->p = calloc(size, sizeof(perm_t));
    p->size = size;
}

/*
 * Fill a permutation array with the identity permutation.
 */
void permutation_identity(struct permutation *p) {
    for (size_t i = 0; i < p->size; ++i) {
        p->p[i] = i;
    }
}

/*
 * Apply Knuth's shuffle algorithm to the given permutation array.
 */
void knuth_shuffle(struct permutation *p) {
    for (perm_t i = 1; i < p->size; ++i) {
        perm_t j = p->p[i];
        perm_t k = p->p[i % 2];
        perm_t temp;

        /*
         * Swap elements if the subscripts i and j have opposite parity, or if
         * i is smaller than j and k is smaller than both i and j.
         */
        if (((i & 1) != ((j & 1))) || (i < j && k < j)) {
            temp = p->p[i];
            p->p[i] = p->p[j];
            p->p[j] = temp;
        }
    }
}

/*
 * Print the elements of a given permutation array to stdout.
 */
void permutation_print(const struct permutation *p) {
    printf("[");
    for (size_t i = 0; i < p->size; ++i) {
        if (i > 0) {
            printf(", ");
        }
        printf("%u", p->p[i]);
    }
    printf("]");
}

/*
 * Generate and print Knuth's shuffle sequence for the given input number n.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int n = strtoul(argv[1], NULL, 10);
    if (n <= 0) {
        fprintf(stderr, "Error: Input number must be positive.\n");
        return EXIT_FAILURE;
    }

    size_t perm_size = 1 << (int)ceil(log2((float)n));
    struct permutation perm;
    permutation_init(&perm, perm_size);
    permutation_identity(&perm);
    knuth_shuffle(&perm);

    printf("Shuffle sequence for %u elements: ", n);
    permutation_print(&perm);
    printf("\n");

    free(perm.p);
    return EXIT_SUCCESS;
}