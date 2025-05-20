//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the possible nucleotides
#define NUCLEOTIDES "ACGT"

// Function to generate a random nucleotide
char generate_random_nucleotide() {
    return NUCLEOTIDES[rand() % 4];
}

// Function to simulate sequence generation
char* generate_random_sequence(int length) {
    char* sequence = (char*) malloc((length + 1) * sizeof(char));
    if (!sequence) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        sequence[i] = generate_random_nucleotide();
    }
    sequence[length] = '\0'; // Null-terminate the string
    return sequence;
}

// Function to simulate mutations in a sequence
void mutate_sequence(char* sequence, int mutation_rate) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if (rand() % 100 < mutation_rate) {
            sequence[i] = generate_random_nucleotide(); // Replace with a random nucleotide
        }
    }
}

// Function to display a sequence
void display_sequence(char* sequence) {
    printf("Generated Sequence: %s\n", sequence);
}

// Function to write the sequence to a file
void write_sequence_to_file(char* filename, char* sequence) {
    FILE* file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s\n", sequence);
        fclose(file);
        printf("Sequence written to %s\n", filename);
    } else {
        fprintf(stderr, "Error writing to file %s\n", filename);
    }
}

// Picking a case for error generation
char* generate_random_with_error(int length, int error_chance) {
    char* sequence = (char*) malloc((length + 1) * sizeof(char));
    if (!sequence) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < length; i++) {
        if (rand() % 100 < error_chance) {
            // Introduce an error by adding a non-standard character
            sequence[i] = 'X';  // Non-nucleotide character
        } else {
            sequence[i] = generate_random_nucleotide();
        }
    }
    sequence[length] = '\0'; // Null-terminate the string
    return sequence;
}

// Main function to simulate the whole process
int main(int argc, char* argv[]) {
    srand(time(NULL)); // Seed the random number generator

    // Set parameters for the simulation
    int sequence_length = 100; // Length of the genome
    int mutation_rate = 5;      // 5% mutation rate
    char filename[256] = "genome_sequence.txt"; // Default filename

    // Check for user input arguments
    if (argc > 1) {
        sequence_length = atoi(argv[1]);
    }
  
    if (argc > 2) {
        mutation_rate = atoi(argv[2]);
    }
  
    if (argc > 3) {
        strncpy(filename, argv[3], sizeof(filename) - 1);
        filename[sizeof(filename) - 1] = '\0'; // Ensure null-termination
    }

    // Generate and display the original sequence
    char* original_sequence = generate_random_sequence(sequence_length);
    display_sequence(original_sequence);

    // Simulate and display the mutated sequence
    char* mutated_sequence = strdup(original_sequence);
    mutate_sequence(mutated_sequence, mutation_rate);
    display_sequence(mutated_sequence);

    // Introduce errors and display the erroneous sequence
    char* erroneous_sequence = generate_random_with_error(sequence_length, 10); // 10% chance of error
    display_sequence(erroneous_sequence);

    // Write all sequences to file
    write_sequence_to_file(filename, original_sequence);
    write_sequence_to_file(filename, mutated_sequence);
    write_sequence_to_file(filename, erroneous_sequence);

    // Cleanup
    free(original_sequence);
    free(mutated_sequence);
    free(erroneous_sequence);

    return 0; // Success
}