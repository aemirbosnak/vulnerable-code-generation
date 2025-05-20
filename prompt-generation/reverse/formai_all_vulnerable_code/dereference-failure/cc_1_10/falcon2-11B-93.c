//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a DNA sequence from a file
char *read_sequence(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }
    char *sequence = (char *) malloc(sizeof(char) * 4000);
    fread(sequence, sizeof(char), 4000, fp);
    fclose(fp);
    return sequence;
}

// Function to reverse complement a DNA sequence
void reverse_complement(char *sequence) {
    int len = strlen(sequence);
    for (int i = 0; i < len; i++) {
        char base = sequence[i];
        switch (base) {
            case 'A':
                sequence[i] = 'T';
                break;
            case 'T':
                sequence[i] = 'A';
                break;
            case 'G':
                sequence[i] = 'C';
                break;
            case 'C':
                sequence[i] = 'G';
                break;
            default:
                printf("Invalid base: %c\n", base);
                exit(1);
        }
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = sequence[i];
        sequence[i] = sequence[len - i - 1];
        sequence[len - i - 1] = temp;
    }
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(const char *filename) {
    char *sequence = read_sequence(filename);
    reverse_complement(sequence);
    printf("Sequence: %s\n", sequence);
    free(sequence);
}

int main() {
    const char *filename = "genome.txt";
    simulate_genome_sequencing(filename);
    return 0;
}