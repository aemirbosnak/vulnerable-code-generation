//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
    int max_sequence_length;
} Genome;

void init_genome(Genome *genome, int num_sequences, int max_sequence_length) {
    genome->num_sequences = num_sequences;
    genome->max_sequence_length = max_sequence_length;
    genome->sequences = (Sequence *)malloc(num_sequences * sizeof(Sequence));
    for (int i = 0; i < num_sequences; i++) {
        genome->sequences[i].sequence = NULL;
        genome->sequences[i].length = 0;
    }
}

void destroy_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        if (genome->sequences[i].sequence!= NULL) {
            free(genome->sequences[i].sequence);
        }
    }
    free(genome->sequences);
}

void generate_random_sequence(char *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 26;
    }
    sequence[length] = '\0';
}

void print_sequence(const char *sequence) {
    printf("%s\n", sequence);
}

int main() {
    Genome genome;
    init_genome(&genome, 10, 100);

    for (int i = 0; i < genome.num_sequences; i++) {
        generate_random_sequence(genome.sequences[i].sequence, rand() % 100 + 1);
        genome.sequences[i].length = strlen(genome.sequences[i].sequence);
    }

    for (int i = 0; i < genome.num_sequences; i++) {
        print_sequence(genome.sequences[i].sequence);
    }

    destroy_genome(&genome);

    return 0;
}