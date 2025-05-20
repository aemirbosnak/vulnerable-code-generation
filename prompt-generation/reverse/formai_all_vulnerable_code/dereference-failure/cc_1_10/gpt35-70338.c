//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_SEQUENCE_LENGTH 5
#define MAX_SEQUENCE_LENGTH 10
#define DNA_BASES "ACGT"

/*
 * Generate a randomized DNA sequence of length between MIN_SEQUENCE_LENGTH and MAX_SEQUENCE_LENGTH.
 */
char* generate_sequence() {
    int sequence_length = (rand() % (MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1)) + MIN_SEQUENCE_LENGTH;
    char* sequence = malloc((sequence_length + 1) * sizeof(char)); // allocate for string length plus null terminator

    for (int i = 0; i < sequence_length; i++) {
        sequence[i] = DNA_BASES[rand() % strlen(DNA_BASES)]; // randomly select DNA base
    }

    sequence[sequence_length] = '\0';
    return sequence;
}

/*
 * Compare two DNA sequences and calculate the percentage of identical DNA bases.
 */
float compare_sequences(char* sequence1, char* sequence2) {
    int sequence_length = strlen(sequence1);
    int num_identical_bases = 0;

    for (int i = 0; i < sequence_length; i++) {
        if (sequence1[i] == sequence2[i]) {
            num_identical_bases++;
        }
    }

    return (float)num_identical_bases / sequence_length * 100;
}

int main() {
    srand(time(NULL)); // seed random number generator with current time

    char* sequence_1 = generate_sequence();
    char* sequence_2 = generate_sequence();

    printf("Sequence 1: %s\n", sequence_1);
    printf("Sequence 2: %s\n", sequence_2);

    float similarity = compare_sequences(sequence_1, sequence_2);
    printf("Similarity between the two sequences: %.2f%%\n", similarity);

    // Free memory allocated for sequences
    free(sequence_1);
    free(sequence_2);

    return 0;
}