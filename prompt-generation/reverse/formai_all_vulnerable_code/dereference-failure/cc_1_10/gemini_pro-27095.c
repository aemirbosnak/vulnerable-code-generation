//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000000

// Define the base pair probabilities
#define P_A 0.3
#define P_C 0.2
#define P_G 0.2
#define P_T 0.3

// Function to generate a random base pair
char generate_base_pair() {
    double r = (double)rand() / RAND_MAX;
    if (r < P_A) {
        return 'A';
    } else if (r < P_A + P_C) {
        return 'C';
    } else if (r < P_A + P_C + P_G) {
        return 'G';
    } else {
        return 'T';
    }
}

// Function to generate a random read
char *generate_read(int length) {
    char *read = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        read[i] = generate_base_pair();
    }
    read[length] = '\0';
    return read;
}

// Function to simulate C genome sequencing
char **simulate_sequencing(int num_reads, int read_length) {
    char **reads = (char **)malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_read(read_length);
    }
    return reads;
}

// Function to print the reads
void print_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Function to free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Simulate C genome sequencing
    char **reads = simulate_sequencing(MAX_NUM_READS, MAX_READ_LENGTH);

    // Print the reads
    print_reads(reads, MAX_NUM_READS);

    // Free the memory allocated for the reads
    free_reads(reads, MAX_NUM_READS);

    return 0;
}