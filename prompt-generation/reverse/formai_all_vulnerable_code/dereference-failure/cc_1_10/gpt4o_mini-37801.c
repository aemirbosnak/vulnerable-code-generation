//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 1000
#define NUM_READS 100
#define ERROR_RATE 0.05

// Function to generate a random DNA base
char random_base() {
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: return 'N'; // Should never reach here
    }
}

// Function to introduce random errors into a sequence
void introduce_errors(char* seq, double error_rate) {
    int len = strlen(seq);
    for (int i = 0; i < len; i++) {
        if ((double)rand() / RAND_MAX < error_rate) {
            seq[i] = random_base();
        }
    }
}

// Function to generate a random DNA sequence of given length
void generate_random_sequence(char* seq, int length) {
    for (int i = 0; i < length; i++) {
        seq[i] = random_base();
    }
    seq[length] = '\0'; // Null terminate the string
}

// Function to simulate sequencing reads from a given DNA sequence
void simulate_read_generation(const char* original_seq, char reads[NUM_READS][MAX_READ_LENGTH]) {
    int original_length = strlen(original_seq);
    for (int i = 0; i < NUM_READS; i++) {
        int start = rand() % (original_length - MAX_READ_LENGTH);
        int read_length = rand() % MAX_READ_LENGTH + 1;
        strncpy(reads[i], original_seq + start, read_length);
        reads[i][read_length] = '\0'; // Null terminate the read
        introduce_errors(reads[i], ERROR_RATE);
    }
}

// Function to print the DNA sequence and reads
void print_sequences(const char* original_seq, char reads[NUM_READS][MAX_READ_LENGTH]) {
    printf("Original Sequence: %s\n\n", original_seq);
    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    char original_sequence[MAX_SEQUENCE_LENGTH];
    char reads[NUM_READS][MAX_READ_LENGTH];

    // Generate random original DNA sequence
    generate_random_sequence(original_sequence, rand() % (MAX_SEQUENCE_LENGTH - 1) + 1);

    // Simulate reading from the DNA sequence
    simulate_read_generation(original_sequence, reads);
    
    // Print the original sequence and all reads
    print_sequences(original_sequence, reads);

    return 0;
}