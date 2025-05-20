//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100

// Function to generate a random DNA sequence
char* generate_dna_sequence(int length) {
    char* sequence = malloc(length + 1);
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

// Function to simulate the sequencing process
char** simulate_sequencing(char* dna_sequence, int num_reads) {
    char** reads = malloc(num_reads * sizeof(char*));
    for (int i = 0; i < num_reads; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        int start_position = rand() % (strlen(dna_sequence) - read_length);
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], dna_sequence + start_position, read_length);
        reads[i][read_length] = '\0';
    }
    return reads;
}

// Function to print the DNA sequence and the simulated reads
void print_results(char* dna_sequence, char** reads, int num_reads) {
    printf("DNA Sequence:\n");
    printf("%s\n", dna_sequence);
    printf("\nSimulated Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA sequence
    int dna_length = 1000;
    char* dna_sequence = generate_dna_sequence(dna_length);

    // Simulate the sequencing process
    int num_reads = 100;
    char** reads = simulate_sequencing(dna_sequence, num_reads);

    // Print the results
    print_results(dna_sequence, reads, num_reads);

    // Free the allocated memory
    free(dna_sequence);
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}