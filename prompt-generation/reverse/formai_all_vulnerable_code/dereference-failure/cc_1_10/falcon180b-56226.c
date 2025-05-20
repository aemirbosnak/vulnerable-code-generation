//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }

    return sequence;
}

Read *generate_random_read(Sequence *sequence, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(read_length * sizeof(char));
    read->length = read_length;
    read->position = rand() % (sequence->length - read_length);

    for (int i = 0; i < read_length; i++) {
        read->sequence[i] = sequence->sequence[read->position + i];
    }

    return read;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Read *reads[NUM_READS];

    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = generate_random_read(sequence, MAX_READ_LENGTH);
    }

    for (int i = 0; i < NUM_READS; i++) {
        print_read(reads[i]);
    }

    return 0;
}