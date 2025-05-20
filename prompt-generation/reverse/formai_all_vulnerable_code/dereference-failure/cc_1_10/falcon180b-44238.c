//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000000 // Maximum length of DNA sequence
#define MAX_READ_LENGTH 100 // Maximum length of reads
#define NUM_READS 1000000 // Number of reads to generate

typedef struct {
    char *sequence;
    int length;
} DNA;

DNA *generate_dna(int length) {
    DNA *dna = (DNA *) malloc(sizeof(DNA));
    dna->sequence = (char *) malloc(length + 1);
    dna->length = length;

    // Fill DNA sequence with random nucleotides
    for (int i = 0; i < length; i++) {
        dna->sequence[i] = 'A' + rand() % 4;
    }
    dna->sequence[length] = '\0';

    return dna;
}

void print_dna(DNA *dna) {
    printf("%s\n", dna->sequence);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    DNA *dna = generate_dna(MAX_LENGTH);
    printf("Generated DNA sequence of length %d:\n", dna->length);
    print_dna(dna);

    DNA *reads[NUM_READS];

    // Generate reads
    for (int i = 0; i < NUM_READS; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        reads[i] = generate_dna(read_length);
        printf("Generated read #%d of length %d: ", i+1, read_length);
        print_dna(reads[i]);
    }

    return 0;
}