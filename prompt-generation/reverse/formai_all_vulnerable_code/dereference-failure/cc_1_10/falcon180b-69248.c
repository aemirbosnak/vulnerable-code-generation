//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence* sequences;
    int num_sequences;
    int alphabet_size;
} Genome;

void generate_random_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

int compare_sequences(const void* a, const void* b) {
    const Sequence* seq1 = (const Sequence*)a;
    const Sequence* seq2 = (const Sequence*)b;

    if (seq1->length > seq2->length) {
        return 1;
    } else if (seq1->length < seq2->length) {
        return -1;
    } else {
        return 0;
    }
}

void print_sequence(const Sequence* sequence) {
    printf("%s\n", sequence->sequence);
}

Genome* create_genome(int num_sequences, int alphabet_size) {
    Genome* genome = (Genome*)malloc(sizeof(Genome));
    genome->sequences = (Sequence*)malloc(num_sequences * sizeof(Sequence));
    genome->num_sequences = num_sequences;
    genome->alphabet_size = alphabet_size;

    for (int i = 0; i < num_sequences; i++) {
        generate_random_sequence(genome->sequences[i].sequence, rand() % MAX_SEQUENCE_LENGTH + 1);
        genome->sequences[i].length = strlen(genome->sequences[i].sequence);
    }

    qsort(genome->sequences, num_sequences, sizeof(Sequence), compare_sequences);

    return genome;
}

void destroy_genome(Genome* genome) {
    free(genome->sequences);
    free(genome);
}

int main() {
    srand(time(NULL));

    Genome* genome = create_genome(MAX_NUM_SEQUENCES, MAX_ALPHABET_SIZE);

    for (int i = 0; i < genome->num_sequences; i++) {
        print_sequence(&genome->sequences[i]);
    }

    destroy_genome(genome);

    return 0;
}