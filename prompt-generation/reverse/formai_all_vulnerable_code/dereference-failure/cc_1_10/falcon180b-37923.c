//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = (Sequence *) malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = (char *) malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

int main() {
    srand(time(NULL));

    Sequence genome = {0};
    genome.sequence = (char *) malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    genome.length = 0;

    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        char base = 'A' + rand() % 4;
        if (base!= 'T') {
            strncat(genome.sequence, &base, 1);
            genome.length++;
        }
    }
    genome.sequence[genome.length] = '\0';

    printf("Genome sequence:\n%s\n", genome.sequence);

    Sequence *reads[NUM_READS];

    for (int i = 0; i < NUM_READS; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        reads[i] = generate_random_sequence(read_length);
    }

    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]->sequence);
    }

    return 0;
}