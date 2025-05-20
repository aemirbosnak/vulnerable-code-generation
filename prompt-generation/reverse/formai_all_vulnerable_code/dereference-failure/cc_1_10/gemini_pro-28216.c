//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random nucleotide sequence of length n
char *generate_sequence(int n) {
    char *sequence = malloc(n + 1); // +1 for null-terminator

    for (int i = 0; i < n; i++) {
        // Generate a random number between 0 and 3
        int rand_num = rand() % 4;

        // Assign the corresponding nucleotide to the sequence
        switch (rand_num) {
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

    // Null-terminate the sequence
    sequence[n] = '\0';

    return sequence;
}

// Print a sequence of nucleotides
void print_sequence(char *sequence) {
    printf("%s\n", sequence);
}

// Generate a random read length between min_length and max_length
int generate_read_length(int min_length, int max_length) {
    return min_length + rand() % (max_length - min_length + 1);
}

// Generate a random read from a given sequence
char *generate_read(char *sequence, int min_length, int max_length) {
    // Generate a random start position for the read
    int start_pos = rand() % (strlen(sequence) - min_length + 1);

    // Generate a random read length
    int read_length = generate_read_length(min_length, max_length);

    // Create a buffer to store the read
    char *read = malloc(read_length + 1); // +1 for null-terminator

    // Copy the read from the sequence into the buffer
    strncpy(read, sequence + start_pos, read_length);

    // Null-terminate the read
    read[read_length] = '\0';

    return read;
}

// Print a list of reads
void print_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Free the allocated memory for a sequence
void free_sequence(char *sequence) {
    free(sequence);
}

// Free the allocated memory for a list of reads
void free_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the parameters of the simulation
    int genome_length = 100000;
    int min_read_length = 50;
    int max_read_length = 150;
    int num_reads = 1000;

    // Generate a random genome sequence
    char *genome = generate_sequence(genome_length);

    // Print the genome sequence
    printf("Genome sequence:\n");
    print_sequence(genome);

    // Generate a list of random reads from the genome
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_read(genome, min_read_length, max_read_length);
    }

    // Print the list of reads
    printf("\nReads:\n");
    print_reads(reads, num_reads);

    // Free the allocated memory
    free_sequence(genome);
    free_reads(reads, num_reads);

    return 0;
}