//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 1000
#define NUM_READS 1000
#define NUM_SEQUENCES 10

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int start_pos;
} Read;

Sequence *sequences;
Read *reads;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

void generate_sequences() {
    sequences = malloc(NUM_SEQUENCES * sizeof(Sequence));
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequences[i].sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        generate_random_sequence(sequences[i].sequence, sequences[i].length);
    }
}

void generate_reads() {
    reads = malloc(NUM_READS * sizeof(Read));
    for (int i = 0; i < NUM_READS; i++) {
        reads[i].sequence = malloc(MAX_READ_LENGTH * sizeof(char));
        reads[i].length = rand() % MAX_READ_LENGTH + 1;
        reads[i].start_pos = rand() % sequences[0].length;
        strncpy(reads[i].sequence, sequences[0].sequence + reads[i].start_pos, reads[i].length);
        reads[i].sequence[reads[i].length - 1] = '\0';
    }
}

void print_sequences() {
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i].sequence);
    }
}

void print_reads() {
    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i + 1, reads[i].sequence);
    }
}

int main() {
    srand(time(NULL));
    generate_sequences();
    generate_reads();
    print_sequences();
    print_reads();
    return 0;
}