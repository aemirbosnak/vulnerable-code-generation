//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 2

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

void generate_random_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

Sequence *generate_random_genome(int length) {
    Sequence *genome = malloc(sizeof(Sequence));
    genome->sequence = malloc(length + 1);
    generate_random_dna_sequence(genome->sequence, length);
    genome->length = length;
    return genome;
}

Read *generate_random_read(Sequence *genome, int read_length, int max_errors) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(read_length + 1);
    read->length = read_length;
    read->position = rand() % (genome->length - read_length);

    strncpy(read->sequence, &genome->sequence[read->position], read_length);
    for (int i = 0; i < max_errors; i++) {
        int position = rand() % read_length;
        read->sequence[position] = 'A' + rand() % 4;
    }
    read->sequence[read_length] = '\0';

    return read;
}

int main() {
    srand(time(NULL));

    Sequence *genome = generate_random_genome(MAX_SEQUENCE_LENGTH);
    Read *reads[MAX_READ_LENGTH];

    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        reads[i] = generate_random_read(genome, MAX_READ_LENGTH, MAX_ERRORS);
    }

    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        printf("Read %d: %s\n", i, reads[i]->sequence);
    }

    return 0;
}