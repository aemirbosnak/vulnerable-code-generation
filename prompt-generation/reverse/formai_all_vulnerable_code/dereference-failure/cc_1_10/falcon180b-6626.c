//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_NUM_SEQUENCES 1000
#define MAX_SEQUENCE_NAME_LENGTH 50

typedef struct {
    char name[MAX_SEQUENCE_NAME_LENGTH];
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

int main() {
    int num_sequences;
    Sequence *sequences;

    // Get number of sequences from user
    printf("Enter number of sequences: ");
    scanf("%d", &num_sequences);

    // Allocate memory for sequences
    sequences = (Sequence *) malloc(num_sequences * sizeof(Sequence));

    // Get sequence names and sequences from user
    for (int i = 0; i < num_sequences; i++) {
        printf("Enter sequence name: ");
        scanf("%s", sequences[i].name);

        printf("Enter sequence: ");
        scanf("%s", sequences[i].sequence);

        sequences[i].length = strlen(sequences[i].sequence);
    }

    // Perform sequencing simulation
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequencing %s...\n", sequences[i].name);
        for (int j = 0; j < sequences[i].length; j++) {
            printf("%c", sequences[i].sequence[j]);
        }
        printf("\n");
    }

    // Free memory
    free(sequences);

    return 0;
}