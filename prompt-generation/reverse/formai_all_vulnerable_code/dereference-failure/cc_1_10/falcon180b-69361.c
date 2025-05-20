//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_MUTATION_RATE 0.01
#define MAX_SEED_VALUE 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(Sequence *sequence, int length) {
    sequence->length = length;
    sequence->sequence = (char *)malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
}

void mutate_sequence(Sequence *sequence, double mutation_rate) {
    for (int i = 0; i < sequence->length; i++) {
        if (rand() % 100 < mutation_rate * 100) {
            sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
        }
    }
}

int compare_sequences(Sequence *sequence1, Sequence *sequence2) {
    for (int i = 0; i < sequence1->length && i < sequence2->length; i++) {
        if (sequence1->sequence[i]!= sequence2->sequence[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    srand(time(NULL));

    Sequence genome1, genome2;
    int population_size = 100;
    double mutation_rate = MAX_MUTATION_RATE;
    int seed_value = rand() % MAX_SEED_VALUE;

    printf("Initializing population of %d genomes with seed value %d...\n", population_size, seed_value);

    for (int i = 0; i < population_size; i++) {
        generate_random_sequence(&genome1, MAX_SEQUENCE_LENGTH);
        mutate_sequence(&genome1, mutation_rate);

        generate_random_sequence(&genome2, MAX_SEQUENCE_LENGTH);
        mutate_sequence(&genome2, mutation_rate);

        if (compare_sequences(&genome1, &genome2)) {
            printf("Genomes %d and %d have the same sequence.\n", i + 1, i + population_size - 1);
        } else {
            printf("Genomes %d and %d have different sequences.\n", i + 1, i + population_size - 1);
        }
    }

    return 0;
}