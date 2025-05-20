//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUCLEOTIDES 4
#define ALPHABET_SIZE NUCLEOTIDES
#define SEQ_LENGTH 100
#define NUM_SEQUENCES 5

typedef enum { A, C, G, T } Nucleotide;

typedef struct Sequence {
    Nucleotide *data;
    size_t length;
} Sequence;

void generate_random_sequence(Sequence *seq) {
    srand(time(NULL));
    seq->length = (rand() % SEQ_LENGTH) + 1;
    seq->data = malloc(seq->length * sizeof(Nucleotide));

    for (size_t i = 0; i < seq->length; i++) {
        seq->data[i] = (Nucleotide)(rand() % NUCLEOTIDES);
    }
}

void print_sequence(Sequence seq) {
    for (size_t i = 0; i < seq.length; i++) {
        switch (seq.data[i]) {
            case A: printf("A"); break;
            case C: printf("C"); break;
            case G: printf("G"); break;
            case T: printf("T"); break;
        }
    }
    printf("\n");
}

int compare_sequences(Sequence a, Sequence b) {
    if (a.length != b.length) {
        return 1;
    }

    for (size_t i = 0; i < a.length; i++) {
        if (a.data[i] != b.data[i]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Sequence *sequences = malloc(NUM_SEQUENCES * sizeof(Sequence));

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generate_random_sequence(&sequences[i]);
        printf("Sequence %d:\n", i + 1);
        print_sequence(sequences[i]);
    }

    printf("\nSequencing...\n");

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        for (int j = i + 1; j < NUM_SEQUENCES; j++) {
            if (compare_sequences(sequences[i], sequences[j])) {
                printf("Mismatch found between Sequence %d and Sequence %d.\n", i + 1, j + 1);
            }
        }
    }

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i].data);
    }
    free(sequences);

    return 0;
}