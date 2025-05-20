//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// A, C, G, T
const char bases[4] = {'A', 'C', 'G', 'T'};

// Transition probability matrix:
//      A  C  G  T
// A   0.5 0.2 0.1 0.2
// C   0.2 0.5 0.2 0.1
// G   0.1 0.2 0.5 0.2
// T   0.2 0.1 0.2 0.5
const double tpm[4][4] = {
    {0.5, 0.2, 0.1, 0.2},
    {0.2, 0.5, 0.2, 0.1},
    {0.1, 0.2, 0.5, 0.2},
    {0.2, 0.1, 0.2, 0.5}
};

// Random number generator
unsigned int seed;
double rand_double() {
    seed = (seed * 1103515245 + 12345) & UINT_MAX;
    return (double)seed / UINT_MAX;
}

// Simulate the sequencing of a given string
char *simulate_sequencing(char *sequence, int length) {
    char *sequenced = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        char base = sequence[i];
        double r = rand_double();
        for (int j = 0; j < 4; j++) {
            if (r < tpm[base - 'A'][j]) {
                sequenced[i] = bases[j];
                break;
            } else {
                r -= tpm[base - 'A'][j];
            }
        }
    }
    sequenced[length] = '\0';
    return sequenced;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sequence> <length>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *sequence = argv[1];
    int length = atoi(argv[2]);
    seed = time(NULL);
    char *sequenced = simulate_sequencing(sequence, length);
    printf("%s\n", sequenced);
    free(sequenced);
    return EXIT_SUCCESS;
}