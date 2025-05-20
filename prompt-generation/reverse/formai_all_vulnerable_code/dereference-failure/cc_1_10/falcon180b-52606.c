//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_ALLELES 10

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int allele_count;
    int alleles[MAX_ALLELES];
} AlleleCount;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4; // A, C, G, T
    }

    return seq;
}

AlleleCount *count_alleles(Sequence *seq, int k) {
    AlleleCount *counts = malloc(sizeof(AlleleCount));
    counts->allele_count = 0;

    for (int i = 0; i < k; i++) {
        counts->alleles[i] = 0;
    }

    for (int i = 0; i < seq->length; i++) {
        if (seq->sequence[i] == 'A' || seq->sequence[i] == 'C' || seq->sequence[i] == 'G' || seq->sequence[i] == 'T') {
            counts->alleles[seq->sequence[i] - 'A']++;
            counts->allele_count++;
        }
    }

    return counts;
}

void print_allele_counts(AlleleCount *counts) {
    for (int i = 0; i < counts->allele_count; i++) {
        printf("%c: %d\n", 'A' + i, counts->alleles[i]);
    }
}

int main() {
    srand(time(NULL));

    Sequence *seq = generate_random_sequence(MAX_SEQ_LENGTH);
    AlleleCount *counts = count_alleles(seq, MAX_ALLELES);

    printf("Sequence: %s\n", seq->sequence);
    printf("Allele counts:\n");
    print_allele_counts(counts);

    free(seq->sequence);
    free(seq);
    free(counts);

    return 0;
}