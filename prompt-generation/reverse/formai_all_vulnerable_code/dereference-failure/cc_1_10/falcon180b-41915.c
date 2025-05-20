//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_MUTATION_RATE 0.01
#define MAX_SEQUENCE_COUNT 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

void mutate_sequence(char *sequence, float mutation_rate) {
    for (int i = 0; i < strlen(sequence); i++) {
        if (rand() % 100 < mutation_rate * 100) {
            sequence[i] = 'A' + rand() % 4;
        }
    }
}

int compare_sequences(const void *a, const void *b) {
    Sequence *seq_a = (Sequence *)a;
    Sequence *seq_b = (Sequence *)b;

    return strcmp(seq_a->sequence, seq_b->sequence);
}

int main() {
    srand(time(NULL));

    int sequence_count = rand() % MAX_SEQUENCE_COUNT + 1;
    Sequence *sequences = malloc(sequence_count * sizeof(Sequence));

    for (int i = 0; i < sequence_count; i++) {
        sequences[i].sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        generate_random_sequence(sequences[i].sequence, sequences[i].length);
    }

    qsort(sequences, sequence_count, sizeof(Sequence), compare_sequences);

    FILE *output_file = fopen("genome_sequences.txt", "w");

    for (int i = 0; i < sequence_count; i++) {
        fprintf(output_file, "Sequence %d:\n%s\n", i + 1, sequences[i].sequence);
    }

    fclose(output_file);

    return 0;
}