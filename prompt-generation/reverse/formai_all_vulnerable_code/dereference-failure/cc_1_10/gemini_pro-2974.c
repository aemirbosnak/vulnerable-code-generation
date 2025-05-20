//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_LENGTH 100

// Function to generate a random DNA sequence of a given length
char* generate_random_dna_sequence(int length) {
    char* sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        switch (rand() % 4) {
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
char** simulate_sequencing(char* fragment, int read_length) {
    int num_reads = (strlen(fragment) + read_length - 1) / read_length;
    char** reads = malloc(num_reads * sizeof(char*));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], fragment + i * read_length, read_length);
        reads[i][read_length] = '\0';
    }
    return reads;
}

// Function to print the simulated reads
void print_reads(char** reads, int num_reads) {
    printf("Simulated reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Function to free the memory allocated for the reads
void free_reads(char** reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA fragment of length 1000
    char* fragment = generate_random_dna_sequence(1000);

    // Simulate the sequencing of the fragment with a read length of 100
    char** reads = simulate_sequencing(fragment, 100);

    // Print the simulated reads
    print_reads(reads, (strlen(fragment) + 100 - 1) / 100);

    // Free the memory allocated for the reads
    free_reads(reads, (strlen(fragment) + 100 - 1) / 100);

    // Free the memory allocated for the fragment
    free(fragment);

    return 0;
}