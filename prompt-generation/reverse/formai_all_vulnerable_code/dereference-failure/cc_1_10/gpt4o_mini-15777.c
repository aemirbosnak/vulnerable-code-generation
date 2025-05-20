//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQ_LENGTH 1000
#define NUM_SEQUENCES 10

// Function to generate a random DNA sequence
void generate_dna_sequence(char *seq, int length) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        seq[i] = nucleotides[rand() % 4];
    }
    seq[length] = '\0'; // Null terminate the string
}

// Function to simulate a sequencing error
void introduce_errors(char *seq, int error_rate) {
    for (int i = 0; i < SEQ_LENGTH; i++) {
        if (rand() % 100 < error_rate) { // Probability of introducing an error
            seq[i] = "ACGT"[rand() % 4]; // Replace with a random nucleotide
        }
    }
}

// Function to compare two sequences and count differences
int compare_sequences(const char *seq1, const char *seq2) {
    int differences = 0;
    for (int i = 0; i < SEQ_LENGTH; i++) {
        if (seq1[i] != seq2[i]) {
            differences++;
        }
    }
    return differences;
}

// Function to print a sequence
void print_sequence(const char *seq, int seq_num) {
    printf("Sequence %d: %s\n", seq_num, seq);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char *actual_sequence = (char *)malloc(SEQ_LENGTH + 1);
    char **simulated_sequences = (char **)malloc(NUM_SEQUENCES * sizeof(char *));
    
    // Create the actual DNA sequence
    generate_dna_sequence(actual_sequence, SEQ_LENGTH);

    // Create simulated sequences
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        simulated_sequences[i] = (char *)malloc(SEQ_LENGTH + 1);
        strcpy(simulated_sequences[i], actual_sequence);
        introduce_errors(simulated_sequences[i], 5); // 5% error rate
    }

    // Print the actual sequence
    print_sequence(actual_sequence, 0);

    // Print simulated sequences and compare with the actual sequence
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        print_sequence(simulated_sequences[i], i + 1);
        int differences = compare_sequences(actual_sequence, simulated_sequences[i]);
        printf("Differences with Sequence %d: %d\n", i + 1, differences);
    }

    // Clean up allocated memory
    free(actual_sequence);
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(simulated_sequences[i]);
    }
    free(simulated_sequences);

    return 0;
}