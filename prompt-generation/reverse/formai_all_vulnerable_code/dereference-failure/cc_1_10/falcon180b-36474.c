//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 1000
#define MAX_NUM_BASES 4
#define MIN_SEQUENCE_LENGTH 10
#define MIN_NUM_SEQUENCES 2
#define MIN_NUM_BASES 2

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    const char bases[] = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = bases[rand() % 4];
    }
    sequence[length] = '\0';
}

Genome *generate_random_genome(int num_sequences, int min_length, int max_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->num_sequences = num_sequences;
    genome->sequences = malloc(num_sequences * sizeof(Sequence));

    for (int i = 0; i < num_sequences; i++) {
        Sequence *sequence = &genome->sequences[i];
        int length = rand() % (max_length - min_length + 1) + min_length;
        generate_random_sequence(sequence->sequence, length);
        sequence->length = length;
    }

    return genome;
}

void print_sequence(const Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

void print_genome(const Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        print_sequence(&genome->sequences[i]);
    }
}

int main() {
    srand(time(NULL));

    int num_sequences = MIN_NUM_SEQUENCES + rand() % (MAX_NUM_SEQUENCES - MIN_NUM_SEQUENCES + 1);
    int min_length = MIN_SEQUENCE_LENGTH + rand() % (MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1);
    int max_length = min_length + rand() % (MAX_SEQUENCE_LENGTH - min_length + 1);

    Genome *genome = generate_random_genome(num_sequences, min_length, max_length);

    printf("Genome with %d sequences generated:\n", genome->num_sequences);
    print_genome(genome);

    free(genome->sequences);
    free(genome);

    return 0;
}