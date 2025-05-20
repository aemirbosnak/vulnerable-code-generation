//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char base;
    int position;
} Nucleotide;

typedef struct {
    int length;
    Nucleotide *sequence;
} Genome;

void generateSequence(Genome *genome, int length) {
    genome->length = length;
    genome->sequence = (Nucleotide *)malloc(length * sizeof(Nucleotide));
    for (int i = 0; i < length; i++) {
        genome->sequence[i].base = 'A' + rand() % 4;
        genome->sequence[i].position = i;
    }
}

void printSequence(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i].base);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Genome genome;
    int length = 1000000;
    generateSequence(&genome, length);
    printf("Original sequence:\n");
    printSequence(&genome);
    printf("Sequence after mutation:\n");
    for (int i = 0; i < length; i++) {
        int mutation = rand() % 4;
        if (mutation == 0) {
            genome.sequence[i].base = 'A';
        } else if (mutation == 1) {
            genome.sequence[i].base = 'C';
        } else if (mutation == 2) {
            genome.sequence[i].base = 'G';
        } else {
            genome.sequence[i].base = 'T';
        }
    }
    printSequence(&genome);
    return 0;
}