//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int end;
} Read;

Sequence *generate_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    Sequence *s = malloc(sizeof(Sequence));
    s->sequence = sequence;
    s->length = length;
    return s;
}

Read *generate_read(Sequence *sequence, int read_length) {
    int start = rand() % (sequence->length - read_length);
    int end = start + read_length;
    char *read_sequence = malloc(read_length + 1);
    strncpy(read_sequence, sequence->sequence + start, read_length);
    read_sequence[read_length] = '\0';
    Read *r = malloc(sizeof(Read));
    r->sequence = read_sequence;
    r->start = start;
    r->end = end;
    return r;
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);
    Read *reads[NUM_READS];

    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = generate_read(sequence, MAX_READ_LENGTH);
    }

    printf("Sequence:\n%s\n", sequence->sequence);

    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i+1, reads[i]->sequence);
        printf("Start position: %d\n", reads[i]->start);
        printf("End position: %d\n\n", reads[i]->end);
    }

    return 0;
}