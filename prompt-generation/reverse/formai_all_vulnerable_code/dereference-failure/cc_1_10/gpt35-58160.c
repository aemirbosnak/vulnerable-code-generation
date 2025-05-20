//FormAI DATASET v1.0 Category: Computer Biology ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a structure for DNA sequence
struct DNA_sequence {
    char sequence[1000];
    int length;
};

//Define a function that reads a DNA sequence from file
struct DNA_sequence read_DNA_sequence(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    char buffer[1000];
    struct DNA_sequence dna_seq;
    dna_seq.length = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (buffer[0] != '>') {
            int n = strlen(buffer);
            memcpy(dna_seq.sequence + dna_seq.length, buffer, n);
            dna_seq.length += n - 1;
        }
    }

    fclose(fp);
    return dna_seq;
}

//Define a function that finds the reverse complement of a DNA sequence
void reverse_complement(struct DNA_sequence* dna_seq) {
    char complement[256];
    complement['A'] = 'T';
    complement['T'] = 'A';
    complement['C'] = 'G';
    complement['G'] = 'C';

    char temp[dna_seq->length];
    for (int i = 0; i < dna_seq->length; i++) {
        temp[i] = complement[dna_seq->sequence[dna_seq->length - 1 - i]];
    }

    memcpy(dna_seq->sequence, temp, dna_seq->length);
}

int main() {
    //Read the DNA sequence from a file
    struct DNA_sequence dna_seq = read_DNA_sequence("dna_sequence.txt");

    //Print the original DNA sequence
    printf("Original DNA Sequence:\n");
    printf("%s\n", dna_seq.sequence);

    //Find the reverse complement of the DNA sequence
    reverse_complement(&dna_seq);

    //Print the reverse complement DNA sequence
    printf("\nReverse Complement DNA Sequence:\n");
    printf("%s\n", dna_seq.sequence);

    return 0;
}