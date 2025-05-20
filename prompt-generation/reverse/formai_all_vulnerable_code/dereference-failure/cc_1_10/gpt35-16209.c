//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the DNA sequence structure
typedef struct {
    char* sequence;
    int length;
} DNASequence;

// Read a DNA sequence from a file
DNASequence readDNASequence(char* filename) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    DNASequence seq;
    seq.length = 0;
    seq.sequence = NULL;

    // Allocate memory for the sequence
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Ignore comment lines that start with '>'
        if (buffer[0] == '>') {
            continue;
        }

        // Append the line to the sequence
        seq.sequence = realloc(seq.sequence, (seq.length + strlen(buffer) + 1) * sizeof(char));
        memcpy(seq.sequence + seq.length, buffer, strlen(buffer) + 1);
        seq.length += strlen(buffer);
    }

    fclose(fp);

    return seq;
}

// Find the most common nucleotide in a DNA sequence
char findMostCommonNucleotide(DNASequence seq) {
    int counts[4] = {0, 0, 0, 0};

    for (int i = 0; i < seq.length; i++) {
        switch (seq.sequence[i]) {
            case 'A':
                counts[0]++;
                break;
            case 'C':
                counts[1]++;
                break;
            case 'G':
                counts[2]++;
                break;
            case 'T':
                counts[3]++;
                break;
        }
    }

    // Find the index of the max count
    int maxCount = counts[0];
    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            maxIndex = i;
        }
    }

    // Return the most common nucleotide
    return "ACGT"[maxIndex];
}

int main() {
    DNASequence seq = readDNASequence("sample.dna");
    char mostCommonNucleotide = findMostCommonNucleotide(seq);

    printf("Most common nucleotide: %c\n", mostCommonNucleotide);

    free(seq.sequence);

    return 0;
}