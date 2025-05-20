//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void init_genome(Genome *genome) {
    genome->sequences = NULL;
    genome->num_sequences = 0;
}

void add_sequence(Genome *genome, char *sequence, int length) {
    Sequence *new_sequence = (Sequence *)malloc(sizeof(Sequence));
    new_sequence->sequence = (char *)malloc(length * sizeof(char));
    strcpy(new_sequence->sequence, sequence);
    new_sequence->length = length;
    genome->sequences = (Sequence *)realloc(genome->sequences, genome->num_sequences + 1 * sizeof(Sequence));
    genome->sequences[genome->num_sequences] = *new_sequence;
    genome->num_sequences++;
}

void print_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->num_sequences; i++) {
        printf("Sequence %d: %s\n", i+1, genome->sequences[i].sequence);
        printf("Length: %d\n\n", genome->sequences[i].length);
    }
}

void free_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    genome->sequences = NULL;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    Genome genome;
    init_genome(&genome);

    int i;
    for (i = 0; i < MAX_NUM_SEQUENCES; i++) {
        int length = rand() % MAX_SEQUENCE_LENGTH + 1;
        char *sequence = (char *)malloc(length * sizeof(char));
        int j;
        for (j = 0; j < length; j++) {
            sequence[j] = 'A' + rand() % MAX_ALPHABET_SIZE;
        }
        add_sequence(&genome, sequence, length);
        free(sequence);
    }

    print_genome(&genome);

    free_genome(&genome);

    return 0;
}