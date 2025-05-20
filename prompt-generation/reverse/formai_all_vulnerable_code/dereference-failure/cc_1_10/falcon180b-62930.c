//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 500
#define MAX_NUM_READS 1000000
#define MAX_NUM_MISMATCHES 3

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *read_sequence;
    int read_length;
    int position;
    int num_mismatches;
} Read;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = (Sequence *)malloc(sizeof(Sequence));
    sequence->sequence = (char *)malloc(length + 1);
    sequence->length = length;

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

Read *generate_random_read(Sequence *sequence, int read_length) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->read_sequence = (char *)malloc(read_length + 1);
    read->read_length = read_length;
    read->position = rand() % sequence->length;
    read->num_mismatches = rand() % MAX_NUM_MISMATCHES + 1;

    for (int i = 0; i < read_length; i++) {
        read->read_sequence[i] = sequence->sequence[read->position + i];
    }
    read->read_sequence[read_length] = '\0';

    return read;
}

int main() {
    Sequence *genome = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    int num_reads = rand() % MAX_NUM_READS + 1;
    Read **reads = (Read **)malloc(sizeof(Read *) * num_reads);

    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_random_read(genome, MAX_READ_LENGTH);
    }

    printf("Genome sequence:\n%s\n", genome->sequence);
    printf("Number of reads: %d\n", num_reads);
    printf("Reads:\n");

    for (int i = 0; i < num_reads; i++) {
        printf("Read %d:\nSequence: %s\nPosition: %d\nNum mismatches: %d\n", i+1, reads[i]->read_sequence, reads[i]->position, reads[i]->num_mismatches);
    }

    return 0;
}