//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_BASE_TYPES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char base[MAX_BASE_TYPES];
    int count;
} BaseCount;

int main() {
    int i, j;
    int sequence_count = 10;
    int sequence_length = 1000;
    Sequence *sequences = malloc(sequence_count * sizeof(Sequence));
    BaseCount base_counts[MAX_BASE_TYPES];

    // Initialize base counts to zero
    for (i = 0; i < MAX_BASE_TYPES; i++) {
        base_counts[i].count = 0;
    }

    // Generate random sequences
    srand(time(NULL));
    for (i = 0; i < sequence_count; i++) {
        sequences[i].sequence = malloc(sequence_length + 1);
        sequences[i].length = sequence_length;
        for (j = 0; j < sequence_length; j++) {
            sequences[i].sequence[j] = 'A' + rand() % MAX_BASE_TYPES;
        }
        sequences[i].sequence[sequence_length] = '\0';
    }

    // Count base occurrences
    for (i = 0; i < sequence_count; i++) {
        for (j = 0; j < sequences[i].length; j++) {
            base_counts[sequences[i].sequence[j] - 'A'].count++;
        }
    }

    // Print base counts
    for (i = 0; i < MAX_BASE_TYPES; i++) {
        printf("Base %c: %d\n", 'A' + i, base_counts[i].count);
    }

    // Free memory
    for (i = 0; i < sequence_count; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}