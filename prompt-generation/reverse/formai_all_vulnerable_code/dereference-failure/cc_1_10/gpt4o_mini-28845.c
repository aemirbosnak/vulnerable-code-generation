//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000 // Maximum length of the DNA sequence
#define READ_LENGTH 50  // Length of each sequencing read
#define NUM_READS 20    // Number of reads to generate
#define MUTATION_RATE 0.05 // Probability of mutation

// Function declarations
char *generate_random_dna(int length);
char *generate_read(char *dna_sequence, int start);
void mutate_sequence(char *sequence);
void print_sequence(char *sequence, int length);
void free_memory(char *ptr);

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Step 1: Generate a random DNA sequence
    char *dna_sequence = generate_random_dna(MAX_LENGTH);
    printf("Original DNA Sequence:\n");
    print_sequence(dna_sequence, MAX_LENGTH);
    
    // Step 2: Simulate sequencing reads
    char **reads = (char **)malloc(NUM_READS * sizeof(char *));
    for (int i = 0; i < NUM_READS; i++) {
        int start = rand() % (MAX_LENGTH - READ_LENGTH);
        reads[i] = generate_read(dna_sequence, start);
        printf("\nGenerated Read %d:\n", i + 1);
        print_sequence(reads[i], READ_LENGTH);
        mutate_sequence(reads[i]);
        printf("Mutated Read %d:\n", i + 1);
        print_sequence(reads[i], READ_LENGTH);
    }

    // Step 3: Free allocated memory
    free_memory(dna_sequence);
    for (int i = 0; i < NUM_READS; i++) {
        free_memory(reads[i]);
    }
    free_memory((char *)reads);
    
    return 0;
}

// Function to generate a random DNA sequence of given length
char *generate_random_dna(int length) {
    char *sequence = (char *)malloc(length * sizeof(char));
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    return sequence;
}

// Function to generate a DNA read from the given sequence starting from a specific position
char *generate_read(char *dna_sequence, int start) {
    char *read = (char *)malloc((READ_LENGTH + 1) * sizeof(char));
    strncpy(read, dna_sequence + start, READ_LENGTH);
    read[READ_LENGTH] = '\0'; // Null-terminate the string
    return read;
}

// Function to introduce mutations into the sequence based on the mutation rate
void mutate_sequence(char *sequence) {
    for (int i = 0; i < READ_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            const char *nucleotides = "ACGT";
            char original = sequence[i];
            do {
                sequence[i] = nucleotides[rand() % 4];
            } while (sequence[i] == original); // Ensure it's a different nucleotide
        }
    }
}

// Function to print the DNA sequence
void print_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        if (sequence[i] == '\0') break; // Break if null terminator is found
        putchar(sequence[i]);
    }
    putchar('\n');
}

// Function to free allocated memory
void free_memory(char *ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}