//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_GENOME_SIZE 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *genome;
    int length;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

int compare_sequences(const void *a, const void *b) {
    Sequence *seq_a = (Sequence *)a;
    Sequence *seq_b = (Sequence *)b;
    return strcmp(seq_a->sequence, seq_b->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%s\n", genome->genome[i].sequence);
    }
}

int main() {
    int alphabet_size = rand() % MAX_ALPHABET_SIZE + 1;
    int genome_size = rand() % MAX_GENOME_SIZE + 1;
    Genome *genome = malloc(genome_size * sizeof(Genome));
    for (int i = 0; i < genome_size; i++) {
        genome[i].genome = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        generate_random_sequence(genome[i].genome, rand() % MAX_SEQUENCE_LENGTH + 1);
        genome[i].length = strlen(genome[i].genome);
    }
    qsort(genome, genome_size, sizeof(Genome), compare_sequences);
    printf("Alphabet size: %d\n", alphabet_size);
    printf("Genome size: %d\n", genome_size);
    printf("Sequences:\n");
    for (int i = 0; i < genome_size; i++) {
        printf("%s\n", genome[i].genome);
    }
    free(genome);
    return 0;
}