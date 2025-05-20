//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_SIZE 1000

typedef struct nucleotide {
    char nitrogenous_base;
    struct nucleotide *next;
} Nucleotide;

// Function to create a random DNA sequence
void create_seq(Nucleotide **head_ref) {
    char nitrogenous_bases[] = {'A', 'C', 'G', 'T'};
    srand(time(NULL));
    int i;
    for (i = 0; i < DNA_SIZE; i++) {
        Nucleotide *new_nucleotide = (Nucleotide *) malloc(sizeof(Nucleotide));
        new_nucleotide->nitrogenous_base = nitrogenous_bases[rand() % 4];
        new_nucleotide->next = (*head_ref);
        (*head_ref) = new_nucleotide;
    }
}

// Function to compare two DNA sequences and find their degree of similarity
float compare_seqs(Nucleotide *seq1_head, Nucleotide *seq2_head) {
    int matches = 0;
    int i;
    for (i = 0; i < DNA_SIZE; i++) {
        if (seq1_head->nitrogenous_base == seq2_head->nitrogenous_base) matches++;
        seq1_head = seq1_head->next;
        seq2_head = seq2_head->next;
    }
    return (float) matches/DNA_SIZE;
}

int main() {
    Nucleotide *seq1 = NULL;
    Nucleotide *seq2 = NULL;

    create_seq(&seq1);
    create_seq(&seq2);

    float similarity = compare_seqs(seq1, seq2);

    printf("DNA Sequence 1: ");
    while (seq1 != NULL) {
        printf("%c", seq1->nitrogenous_base);
        seq1 = seq1->next;
    }

    printf("\n\nDNA Sequence 2: ");
    while (seq2 != NULL) {
        printf("%c", seq2->nitrogenous_base);
        seq2 = seq2->next;
    }

    printf("\n\nSimilarity between DNA sequences = %.2f%%", similarity*100);

    return 0;
}