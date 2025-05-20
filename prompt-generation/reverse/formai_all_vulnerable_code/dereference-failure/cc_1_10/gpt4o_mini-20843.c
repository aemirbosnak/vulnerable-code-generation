//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define READ_LENGTH 100
#define NUM_READS 10
#define NUM_BASES 4

typedef struct {
    char *genome_sequence;
    int length;
} Genome;

// Function prototypes
Genome* create_genome(int length);
void free_genome(Genome *genome);
void generate_random_genome(Genome *genome);
void print_genome(Genome *genome);
char* get_read(const Genome *genome, int position);
void simulate_sequencing(const Genome *genome);
void write_results_to_file(const char *filename, const char *results);

// Main function
int main() {
    // Seed random number generator for genome generation
    srand((unsigned int)time(NULL));

    // Create a genome
    Genome *genome = create_genome(MAX_GENOME_LENGTH);
    generate_random_genome(genome);
    print_genome(genome);

    // Simulate sequencing
    simulate_sequencing(genome);

    // Free allocated memory
    free_genome(genome);
    return 0;
}

// Function to create a new genome
Genome* create_genome(int length) {
    Genome *genome = (Genome*)malloc(sizeof(Genome));
    genome->length = length;
    genome->genome_sequence = (char*)malloc(length + 1);
    genome->genome_sequence[length] = '\0'; // Null-terminate the string
    return genome;
}

// Function to free the genome memory
void free_genome(Genome *genome) {
    free(genome->genome_sequence);
    free(genome);
}

// Function to generate a random genome sequence
void generate_random_genome(Genome *genome) {
    const char bases[NUM_BASES] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < genome->length; i++) {
        genome->genome_sequence[i] = bases[rand() % NUM_BASES];
    }
}

// Function to print the genome sequence
void print_genome(Genome *genome) {
    printf("Generated Genome Sequence:\n");
    printf("%s\n", genome->genome_sequence);
}

// Function to get a read from the genome at a specified position
char* get_read(const Genome *genome, int position) {
    if (position < 0 || position + READ_LENGTH > genome->length) {
        return NULL; // Invalid position for read
    }

    char *read = (char*)malloc(READ_LENGTH + 1);
    strncpy(read, genome->genome_sequence + position, READ_LENGTH);
    read[READ_LENGTH] = '\0'; // Null-terminate the read
    return read;
}

// Function to simulate sequencing of the genome
void simulate_sequencing(const Genome *genome) {
    printf("Simulating Sequencing...\n");
    char *results = (char*)malloc(NUM_READS * (READ_LENGTH + 1));

    for (int i = 0; i < NUM_READS; i++) {
        int position = rand() % (genome->length - READ_LENGTH);
        char *read = get_read(genome, position);
        if (read) {
            sprintf(results + i * (READ_LENGTH + 1), "Read %d: %s\n", i + 1, read);
            free(read); // Free the allocated read memory
        }
    }

    // Write results to the output file
    write_results_to_file("sequencing_results.txt", results);
    free(results);
}

// Function to write sequencing results to a file
void write_results_to_file(const char *filename, const char *results) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", results);
        fclose(file);
        printf("Sequencing results written to %s\n", filename);
    } else {
        printf("Error writing to file %s\n", filename);
    }
}