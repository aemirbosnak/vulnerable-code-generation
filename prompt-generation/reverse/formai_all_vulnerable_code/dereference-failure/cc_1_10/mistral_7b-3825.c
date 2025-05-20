//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 100
#define NUM_SEQUENCES 5

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    char complement[MAX_SEQUENCE_LENGTH];
} Sequence;

void read_sequence_from_file(FILE *file, Sequence *sequence) {
    fgets(sequence->sequence, MAX_SEQUENCE_LENGTH, file);
    sequence->sequence[strlen(sequence->sequence) - 1] = '\0'; // remove newline character
}

void generate_complement(Sequence *sequence) {
    int i;

    for (i = 0; sequence->sequence[i] != '\0'; i++) {
        if (sequence->sequence[i] == 'A') {
            sequence->complement[i] = 'T';
        } else if (sequence->sequence[i] == 'C') {
            sequence->complement[i] = 'G';
        } else if (sequence->sequence[i] == 'G') {
            sequence->complement[i] = 'C';
        } else if (sequence->sequence[i] == 'T') {
            sequence->complement[i] = 'A';
        } else {
            sequence->complement[i] = sequence->sequence[i];
        }
    }
    sequence->complement[i] = '\0';
}

int main() {
    FILE *file;
    Sequence sequences[NUM_SEQUENCES];
    int i;

    file = fopen("sequences.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < NUM_SEQUENCES; i++) {
        read_sequence_from_file(file, &sequences[i]);
        generate_complement(&sequences[i]);
        printf("Sequence: %s\n", sequences[i].sequence);
        printf("Complement: %s\n", sequences[i].complement);
    }

    fclose(file);
    return 0;
}