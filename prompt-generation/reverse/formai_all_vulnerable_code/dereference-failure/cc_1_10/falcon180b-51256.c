//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_BASES 4
#define NUM_AMINO_ACIDS 20
#define NUM_CODON_TYPES 61

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    char amino_acid;
    int frequency;
} AminoAcid;

typedef struct {
    char codon[3];
    int frequency;
} Codon;

Sequence generateRandomSequence(int length) {
    Sequence sequence;
    srand(time(NULL));
    for(int i=0; i<length; i++) {
        switch(rand()%NUM_BASES) {
            case 0: sequence.sequence[i] = 'A'; break;
            case 1: sequence.sequence[i] = 'C'; break;
            case 2: sequence.sequence[i] = 'G'; break;
            case 3: sequence.sequence[i] = 'T'; break;
        }
    }
    sequence.length = length;
    return sequence;
}

void printSequence(Sequence sequence) {
    printf("Sequence: %s\n", sequence.sequence);
    printf("Length: %d\n", sequence.length);
}

int main() {
    int num_sequences = 10;
    int sequence_length = 100;
    Sequence* sequences = (Sequence*)malloc(num_sequences*sizeof(Sequence));
    for(int i=0; i<num_sequences; i++) {
        sequences[i] = generateRandomSequence(sequence_length);
        printSequence(sequences[i]);
    }
    return 0;
}