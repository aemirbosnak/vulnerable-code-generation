//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000
#define NUM_BASES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *read;
    int length;
    int start_pos;
} Read;

Sequence *generate_random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % NUM_BASES;
    }
    sequence[length] = '\0';
    Sequence *s = malloc(sizeof(Sequence));
    s->sequence = sequence;
    s->length = length;
    return s;
}

Read *generate_random_read(int length, Sequence *sequence) {
    int start_pos = rand() % (sequence->length - length);
    char *read = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        read[i] = sequence->sequence[start_pos + i];
    }
    read[length] = '\0';
    Read *r = malloc(sizeof(Read));
    r->read = read;
    r->length = length;
    r->start_pos = start_pos;
    return r;
}

int main(int argc, char **argv) {
    srand(time(NULL));

    Sequence *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Read **reads = malloc(MAX_NUM_READS * sizeof(Read *));
    int num_reads = 0;

    for (int i = 0; i < MAX_NUM_READS && num_reads < MAX_NUM_READS; i++) {
        Read *read = generate_random_read(MAX_READ_LENGTH, sequence);
        reads[num_reads++] = read;
    }

    printf("Sequence:\n%s\n", sequence->sequence);
    printf("Number of reads: %d\n", num_reads);
    printf("Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]->read);
    }

    return 0;
}