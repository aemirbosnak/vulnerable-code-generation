//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *reads;
    int num_reads;
} ReadSet;

Sequence *generate_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    for (int i = 0; i < length; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                sequence->sequence[i] = 'A';
                break;
            case 1:
                sequence->sequence[i] = 'C';
                break;
            case 2:
                sequence->sequence[i] = 'G';
                break;
            case 3:
                sequence->sequence[i] = 'T';
                break;
        }
    }

    sequence->sequence[length] = '\0';

    return sequence;
}

ReadSet *generate_read_set(Sequence *sequence, int num_reads, int read_length) {
    ReadSet *read_set = malloc(sizeof(ReadSet));
    read_set->reads = malloc(num_reads * sizeof(Sequence));
    read_set->num_reads = num_reads;

    for (int i = 0; i < num_reads; i++) {
        int start = rand() % (sequence->length - read_length);
        Sequence *read = malloc(sizeof(Sequence));
        read->sequence = malloc(read_length + 1);
        read->length = read_length;

        for (int j = 0; j < read_length; j++) {
            read->sequence[j] = sequence->sequence[start + j];
        }

        read->sequence[read_length] = '\0';

        read_set->reads[i] = *read;
        free(read);
    }

    return read_set;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }

    printf("\n");
}

void print_read_set(ReadSet *read_set) {
    for (int i = 0; i < read_set->num_reads; i++) {
        print_sequence(&read_set->reads[i]);
    }
}

int main() {
    Sequence *sequence = generate_sequence(MAX_SEQ_LENGTH);
    ReadSet *read_set = generate_read_set(sequence, 1000, MAX_READ_LENGTH);

    print_sequence(sequence);
    print_read_set(read_set);

    free(sequence->sequence);
    free(sequence);

    for (int i = 0; i < read_set->num_reads; i++) {
        free(read_set->reads[i].sequence);
    }

    free(read_set->reads);
    free(read_set);

    return 0;
}