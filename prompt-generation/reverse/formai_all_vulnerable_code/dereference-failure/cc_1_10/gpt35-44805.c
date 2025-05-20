//FormAI DATASET v1.0 Category: Computer Biology ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a constant for the number of nucleotide bases in DNA
#define NUM_BASES 4

// Define the structure for a DNA sequence
typedef struct {
    int length; // length of the sequence
    char* sequence; // pointer to the sequence
} DNA;

// Define the function to count the number of each nucleotide base in a DNA sequence
void countBases(DNA dna) {
    int counts[NUM_BASES] = {0}; // initialize the counts for each base to 0
    
    // loop through each base in the sequence and tally the counts
    for (int i = 0; i < dna.length; i++) {
        switch(dna.sequence[i]) {
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
            default:
                printf("Invalid base: %c\n", dna.sequence[i]);
                break;
        }
    }
    
    // print the counts for each base
    printf("Counts:\n");
    printf("A: %d\n", counts[0]);
    printf("C: %d\n", counts[1]);
    printf("G: %d\n", counts[2]);
    printf("T: %d\n", counts[3]);
}

int main() {
    char* dnaStr = "GGCACTGATATGCGCGTAGCTCTCGGTAAATCGTCCGTGGCGCTCCAAGAGGTCACGAACTGAGTACCGTCTC";
    int dnaLength = 65;
    
    // dynamically allocate memory for the DNA sequence
    char* dnaSeq = (char*)malloc(dnaLength * sizeof(char));
    
    // copy the string into the allocated memory
    for (int i = 0; i < dnaLength; i++) {
        dnaSeq[i] = dnaStr[i];
    }
    
    // create a DNA structure and initialize it with the sequence
    DNA myDNA;
    myDNA.length = dnaLength;
    myDNA.sequence = dnaSeq;
    
    // call the function to count the bases in the DNA sequence
    countBases(myDNA);
    
    // free the dynamically allocated memory
    free(dnaSeq);
    
    return 0;
}