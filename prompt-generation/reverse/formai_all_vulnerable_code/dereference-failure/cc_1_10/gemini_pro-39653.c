//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of a DNA sequence
#define MAX_SEQ_LEN 1000

// Nucleotide types
enum nt { A, C, G, T };

// Nucleotide probabilities
double nt_probs[] = { 0.25, 0.25, 0.25, 0.25 };

// Generate a random nucleotide
enum nt random_nt() {
    double r = (double)rand() / RAND_MAX;
    for (int i = 0; i < 4; i++) {
        if (r < nt_probs[i]) {
            return i;
        }
        r -= nt_probs[i];
    }
    return -1;  // Should never reach here
}

// Generate a random DNA sequence
char *random_dna(int len) {
    char *seq = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        switch (random_nt()) {
            case A: seq[i] = 'A'; break;
            case C: seq[i] = 'C'; break;
            case G: seq[i] = 'G'; break;
            case T: seq[i] = 'T'; break;
        }
    }
    seq[len] = '\0';
    return seq;
}

// Simulate a genome sequencing experiment
void simulate_sequencing(int num_reads, int read_len) {
    // Generate a random DNA sequence
    char *genome = random_dna(1000000);

    // Simulate sequencing reads
    for (int i = 0; i < num_reads; i++) {
        // Generate a random starting position
        int start = rand() % (strlen(genome) - read_len);

        // Get the read sequence
        char *read = strndup(genome + start, read_len);

        // Add some sequencing errors
        for (int j = 0; j < read_len; j++) {
            if ((double)rand() / RAND_MAX < 0.01) {
                switch (read[j]) {
                    case 'A': read[j] = 'C'; break;
                    case 'C': read[j] = 'G'; break;
                    case 'G': read[j] = 'T'; break;
                    case 'T': read[j] = 'A'; break;
                }
            }
        }

        // Print the read
        printf("%s\n", read);
    }

    // Free the memory
    free(genome);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Simulate a genome sequencing experiment
    simulate_sequencing(1000, 100);

    return 0;
}