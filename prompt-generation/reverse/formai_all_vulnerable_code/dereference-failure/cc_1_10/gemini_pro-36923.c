//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

// Function to generate a random DNA sequence of a given length
char *generate_random_dna_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 4;
        switch (random_number) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to simulate the sequencing of a DNA fragment
char **simulate_sequencing(char *fragment, int read_length) {
    int num_reads = (strlen(fragment) - read_length) / (read_length - 1) + 1;
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], fragment + i * (read_length - 1), read_length);
        reads[i][read_length] = '\0';
    }
    return reads;
}

// Function to print the reads
void print_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA fragment of length 1000
    char *fragment = generate_random_dna_sequence(1000);

    // Simulate the sequencing of the fragment with a read length of 100
    char **reads = simulate_sequencing(fragment, 100);

    // Print the reads
    print_reads(reads, (strlen(fragment) - 100) / 99 + 1);

    // Free the allocated memory
    free(fragment);
    for (int i = 0; i < (strlen(fragment) - 100) / 99 + 1; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}