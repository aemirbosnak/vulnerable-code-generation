//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// DNA bases
char bases[] = {'A', 'C', 'G', 'T'};

// Generate a random DNA sequence of length n
char *generate_sequence(int n) {
    char *sequence = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        sequence[i] = bases[rand() % 4];
    }
    sequence[n] = '\0';
    return sequence;
}

// Simulate sequencing errors
char *simulate_errors(char *sequence, double error_rate) {
    int length = strlen(sequence);
    char *sequenced = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        if (rand() / (RAND_MAX + 1.0) < error_rate) {
            sequenced[i] = bases[rand() % 4];
        } else {
            sequenced[i] = sequence[i];
        }
    }
    sequenced[length] = '\0';
    return sequenced;
}

// Print a DNA sequence
void print_sequence(char *sequence) {
    printf("%s\n", sequence);
}

// Main function
int main() {
    // Set random seed
    srand(time(NULL));

    // Generate a random DNA sequence
    int length = 1000;
    char *sequence = generate_sequence(length);

    // Simulate sequencing errors
    double error_rate = 0.01;
    char *sequenced = simulate_errors(sequence, error_rate);

    // Print the original and sequenced DNA sequences
    printf("Original sequence:\n");
    print_sequence(sequence);
    printf("Sequenced sequence:\n");
    print_sequence(sequenced);

    // Free allocated memory
    free(sequence);
    free(sequenced);

    return 0;
}