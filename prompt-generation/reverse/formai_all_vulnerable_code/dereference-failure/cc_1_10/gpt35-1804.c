//FormAI DATASET v1.0 Category: Computer Biology ; Style: imaginative
#include <stdio.h>

// Defining a struct for DNA sequence
typedef struct DNA_sequence {
    int length;
    char* sequence;
} DNA_sequence;

// Function to compute the reverse complement of a DNA sequence
void reverse_complement(DNA_sequence* dna) {
    char* reverse_seq = malloc(dna->length * sizeof(char)); // Allocate memory for the reverse sequence
    // Reverse the original sequence and store it in 'reverse_seq'
    for(int i = dna->length - 1; i >= 0; i--) {
        switch(dna->sequence[i]) {
            case 'A':
                reverse_seq[dna->length - 1 - i] = 'T';
                break;
            case 'T':
                reverse_seq[dna->length - 1 - i] = 'A';
                break;
            case 'G':
                reverse_seq[dna->length - 1 - i] = 'C';
                break;
            case 'C':
                reverse_seq[dna->length - 1 - i] = 'G';
                break;
            default:
                printf("Invalid nucleotide in DNA sequence!\n");
                exit(1);
        }
    }
    // Copy the reverse sequence to the DNA sequence
    for(int i = 0; i < dna->length; i++) {
        dna->sequence[i] = reverse_seq[i];
    }
    free(reverse_seq); // Free memory allocated for reverse sequence
}

// Main function
int main() {
    DNA_sequence dna1 = {6, "ATGGCT"};
    DNA_sequence dna2 = {12, "AGCTTAGCTGAC"};

    reverse_complement(&dna1);
    reverse_complement(&dna2);

    printf("Reverse complement of dna1: %s\n", dna1.sequence);
    printf("Reverse complement of dna2: %s\n", dna2.sequence);

    return 0;
}