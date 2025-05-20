//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_ALLELES 4
#define MAX_SNP_DENSITY 0.01
#define MIN_SNP_DENSITY 0.001

typedef struct {
    char allele1;
    char allele2;
    int frequency;
} AlleleFrequency;

typedef struct {
    int length;
    int snp_density;
    AlleleFrequency *allele_frequencies;
} GenomeSequence;

void generate_sequence(GenomeSequence *sequence, int length) {
    int i;
    for (i = 0; i < length; i++) {
        sequence->allele_frequencies[i].allele1 = rand() % 4 + 'A';
        sequence->allele_frequencies[i].allele2 = rand() % 4 + 'A';
        sequence->allele_frequencies[i].frequency = rand() % 101;
    }
}

void print_sequence(GenomeSequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        if (sequence->allele_frequencies[i].allele1 == sequence->allele_frequencies[i].allele2) {
            printf("%c", sequence->allele_frequencies[i].allele1);
        } else {
            printf("%c/%c", sequence->allele_frequencies[i].allele1, sequence->allele_frequencies[i].allele2);
        }
    }
}

int main() {
    srand(time(NULL));
    GenomeSequence *sequence = malloc(sizeof(GenomeSequence));
    sequence->length = MAX_SEQUENCE_LENGTH;
    sequence->snp_density = (rand() % 1000) * 0.001;
    if (sequence->snp_density < MIN_SNP_DENSITY) {
        sequence->snp_density = MIN_SNP_DENSITY;
    }
    sequence->allele_frequencies = malloc(sequence->length * sizeof(AlleleFrequency));
    generate_sequence(sequence, sequence->length);
    printf("Sequence generated: ");
    print_sequence(sequence);
    printf("\n");
    free(sequence->allele_frequencies);
    free(sequence);
    return 0;
}