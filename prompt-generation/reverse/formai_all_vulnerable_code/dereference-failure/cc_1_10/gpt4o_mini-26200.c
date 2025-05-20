//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function prototypes
char *generate_random_dna_sequence(int length);
void pairwise_dna_sequence_comparison(char *dna1, char *dna2, int length);
void display_dna_sequence_and_affinity(char *dna1, char *dna2, float affinity);

int main() {
    srand(time(NULL)); // Initialize random seed

    printf("In a world where genetics meets love...\n");
    printf("Generating the DNA sequences of two loving souls...\n\n");

    // Generate random DNA sequences for two lovers
    char *lover1_dna = generate_random_dna_sequence(MAX_LENGTH);
    char *lover2_dna = generate_random_dna_sequence(MAX_LENGTH);

    // Display generated sequences
    printf("Lover 1's DNA: %s\n", lover1_dna);
    printf("Lover 2's DNA: %s\n\n", lover2_dna);

    // Analyze their affinity
    pairwise_dna_sequence_comparison(lover1_dna, lover2_dna, MAX_LENGTH);

    // Free allocated memory
    free(lover1_dna);
    free(lover2_dna);

    return 0;
}

char *generate_random_dna_sequence(int length) {
    char *dna = (char *)malloc(length + 1);
    const char *nucleotides = "ATCG";
    
    for (int i = 0; i < length; i++) {
        dna[i] = nucleotides[rand() % 4]; // Choose a random nucleotide
    }
    dna[length] = '\0'; // Null terminate the string

    return dna;
}

void pairwise_dna_sequence_comparison(char *dna1, char *dna2, int length) {
    int match_count = 0;
    int total_count = length;

    for (int i = 0; i < total_count; i++) {
        if (dna1[i] == dna2[i]) {
            match_count++;
        }
    }

    float affinity = (float)match_count / total_count;
    printf("In the DNA of love, they match at %d out of %d positions.\n", match_count, total_count);
    printf("Their genetic affinity is a beautiful %.2f%%\n\n", affinity * 100);

    // Display their compatibility
    display_dna_sequence_and_affinity(dna1, dna2, affinity);
}

void display_dna_sequence_and_affinity(char *dna1, char *dna2, float affinity) {
    if (affinity > 0.75) {
        printf("Their souls dance in harmony, like a perfect duet of DNA!\n");
    } else if (affinity > 0.5) {
        printf("While they share a bond, there are still notes of dissonance.\n");
    } else {
        printf("Though there is love, their genetic paths diverge...\n");
    }
    printf("Together, their love story is etched in the sequences of the stars!\n");
}