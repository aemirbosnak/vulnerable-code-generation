//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generates random DNA sequence
char rand_base() {
    char bases[] = {'A', 'C', 'T', 'G'};
    return bases[rand() % 4];
}

// Generates a random sequence of given length
char* rand_sequence(int length) {
    char* sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence[i] = rand_base();
    }
    return sequence;
}

// Main function to simulate genome sequencing
int main() {
    // Set up variables
    int length = 1000; // Length of genome to sequence
    int reads = 10000; // Number of reads to take
    int read_length = 50; // Length of each read
    int overlap = 25; // Amount of overlap between adjacent reads
    char* genome = rand_sequence(length); // Generate random genome
    printf("Genome: %s\n", genome); // Print the genome
    
    // Generate reads
    char** read_list = malloc(reads * sizeof(char*));
    for (int i = 0; i < reads; i++) {
        read_list[i] = malloc(read_length * sizeof(char));
        int start = i*(read_length - overlap);
        for (int j = 0; j < read_length; j++) {
            if (start + j >= length) { // If going past the end of the genome, wrap around
                read_list[i][j] = genome[start + j - length];
            } else {
                read_list[i][j] = genome[start + j];
            }
        }
    }
    
    // Print first few reads
    printf("Reads:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", read_list[i]);
    }
    
    // Clean up memory
    free(genome);
    for (int i = 0; i < reads; i++) {
        free(read_list[i]);
    }
    free(read_list);
    
    return 0;
}