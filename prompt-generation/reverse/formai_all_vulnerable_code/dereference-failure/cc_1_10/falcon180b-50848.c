//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 500

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int start;
} Read;

Sequence *generate_sequence(int length) {
    Sequence *seq = (Sequence *)malloc(sizeof(Sequence));
    seq->sequence = (char *)malloc(length * sizeof(char));
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }

    return seq;
}

Read *generate_read(Sequence *sequence, int read_length) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->sequence = (char *)malloc(read_length * sizeof(char));
    read->length = read_length;
    read->start = rand() % (sequence->length - read_length);

    for (int i = 0; i < read_length; i++) {
        read->sequence[i] = sequence->sequence[read->start + i];
    }

    return read;
}

void print_sequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
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

    Sequence *ref_seq = generate_sequence(MAX_SEQUENCE_LENGTH);
    Sequence *query_seq = generate_sequence(MAX_SEQUENCE_LENGTH);

    Read *read1 = generate_read(ref_seq, MAX_READ_LENGTH);
    Read *read2 = generate_read(query_seq, MAX_READ_LENGTH);

    printf("Reference sequence:\n");
    print_sequence(ref_seq);

    printf("Query sequence:\n");
    print_sequence(query_seq);

    printf("Read 1:\n");
    print_read(read1);

    printf("Read 2:\n");
    print_read(read2);

    free(ref_seq->sequence);
    free(ref_seq);
    free(query_seq->sequence);
    free(query_seq);
    free(read1->sequence);
    free(read1);
    free(read2->sequence);
    free(read2);

    return 0;
}