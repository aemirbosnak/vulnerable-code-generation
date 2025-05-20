//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 3
#define MAX_NUM_READS 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int errors;
} Read;

Sequence *generate_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc((length + 1) * sizeof(char));
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';

    return seq;
}

Read *generate_read(Sequence *sequence, int read_length, int num_errors) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc((read_length + 1) * sizeof(char));
    read->length = read_length;
    read->errors = num_errors;

    int start_pos = rand() % (sequence->length - read_length + 1);
    strncpy(read->sequence, sequence->sequence + start_pos, read_length);
    read->sequence[read_length] = '\0';

    for (int i = 0; i < num_errors; i++) {
        int pos = rand() % read_length;
        char base = 'A' + rand() % 4;
        read->sequence[pos] = base;
    }

    return read;
}

void print_sequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

void print_read(Read *read) {
    printf("%s\n", read->sequence);
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);
    Read *reads[MAX_NUM_READS];

    int num_reads = 0;
    while (num_reads < MAX_NUM_READS) {
        Read *read = generate_read(sequence, MAX_READ_LENGTH, MAX_ERRORS);
        int found = 0;

        for (int i = 0; i < num_reads; i++) {
            if (strcmp(read->sequence, reads[i]->sequence) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            reads[num_reads++] = read;
        } else {
            free(read->sequence);
            free(read);
        }
    }

    for (int i = 0; i < num_reads; i++) {
        print_read(reads[i]);
    }

    return 0;
}