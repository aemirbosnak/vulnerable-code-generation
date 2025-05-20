//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char base;
    int count;
} base_count;

typedef struct {
    base_count bases[4];
    int size;
} sequence;

void simulate_read(sequence* seq, int read_length, int start_pos) {
    int i;
    sequence read_seq;
    read_seq.size = 0;

    for (i = start_pos; i < start_pos + read_length && i < seq->size; i++) {
        read_seq.bases[seq->bases[i].base - 'A']
            .count++;
        read_seq.size++;
    }

    if (read_seq.size > 0) {
        printf("Read %d: %s\n", read_seq.size,
            read_seq.bases[(int)read_seq.bases[0].base - 'A']
            .base == 'A' ? "A" :
            read_seq.bases[(int)read_seq.bases[0].base - 'A']
            .base == 'C' ? "C" :
            read_seq.bases[(int)read_seq.bases[0].base - 'A']
            .base == 'G' ? "G" : "T");
        for (i = 1; i < read_seq.size; i++) {
            printf("%c%c", read_seq.bases[i].base,
                read_seq.bases[i - 1].base == read_seq.bases[i].base ? ":" : "-");
        }
        printf("\n");
        simulate_read(seq, read_length, i);
    }
}

void simulate_sequencing(sequence* seq, int read_length) {
    int i, start_pos;

    srand(time(NULL));
    start_pos = rand() % seq->size;

    printf("Sequence: %s\n", seq->bases[(int)seq->bases[0].base - 'A']
        .base == 'A' ? "A" :
        seq->bases[(int)seq->bases[0].base - 'A']
        .base == 'C' ? "C" :
        seq->bases[(int)seq->bases[0].base - 'A']
        .base == 'G' ? "G" : "T");

    for (i = 1; i < seq->size; i++) {
        printf("%c%c", seq->bases[i].base,
            seq->bases[i - 1].base == seq->bases[i].base ? ":" : "-");
    }

    printf("\n");
    simulate_read(seq, read_length, start_pos);
}

int main() {
    int i, read_length;
    sequence seq;
    char input[100];

    printf("Enter genome sequence length: ");
    scanf("%d", &seq.size);

    seq.bases[0].base = seq.bases[0].count = 0;

    for (i = 1; i <= seq.size; i++) {
        scanf("%c", &input[0]);
        seq.bases[i].base = input[0];
        seq.bases[i].count = 0;
    }

    printf("Enter read length: ");
    scanf("%d", &read_length);

    simulate_sequencing(&seq, read_length);

    return 0;
}