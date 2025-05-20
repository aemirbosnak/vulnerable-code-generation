//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int start;
    int end;
    int strand;
} Read;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(length + 1);
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4 + 'A';
    }
    seq->sequence[length] = '\0';

    return seq;
}

Read *generate_random_read(Sequence *sequence, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->start = rand() % sequence->length;
    read->end = read->start + read_length - 1;
    read->strand = rand() % 2;

    return read;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    printf("Read: %d-%d (%d)\n", read->start, read->end, read->strand);
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    printf("Random sequence:\n");
    print_sequence(sequence);

    Read *read = generate_random_read(sequence, MAX_READ_LENGTH);
    printf("Random read:\n");
    print_read(read);

    return 0;
}