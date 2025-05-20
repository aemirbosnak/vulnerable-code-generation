//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define READ_LENGTH 100
#define COVERAGE 10
#define ERROR_RATE 0.01

// Function to generate a random DNA sequence
char *generate_sequence(int length) {
    char *sequence = malloc(length + 1);  // +1 for the null terminator
    for (int i = 0; i < length; i++) {
        int base = rand() % 4;
        switch (base) {
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

// Function to simulate sequencing errors
char *simulate_errors(char *sequence) {
    int length = strlen(sequence);
    char *sequenced_sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        if ((double)rand() / RAND_MAX < ERROR_RATE) {
            int base = rand() % 4;
            switch (base) {
                case 0:
                    sequenced_sequence[i] = 'A';
                    break;
                case 1:
                    sequenced_sequence[i] = 'C';
                    break;
                case 2:
                    sequenced_sequence[i] = 'G';
                    break;
                case 3:
                    sequenced_sequence[i] = 'T';
                    break;
            }
        } else {
            sequenced_sequence[i] = sequence[i];
        }
    }
    sequenced_sequence[length] = '\0';
    return sequenced_sequence;
}

// Function to generate simulated reads
char **generate_reads(char *sequence, int length, int coverage) {
    int num_reads = length * coverage / READ_LENGTH;
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        int start = rand() % (length - READ_LENGTH);
        reads[i] = malloc(READ_LENGTH + 1);
        strncpy(reads[i], sequence + start, READ_LENGTH);
        reads[i][READ_LENGTH] = '\0';
    }
    return reads;
}

// Function to print reads
void print_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

int main() {
    srand(time(NULL));

    // Generate a random DNA sequence
    char *sequence = generate_sequence(1000);

    // Simulate sequencing errors
    char *sequenced_sequence = simulate_errors(sequence);

    // Generate simulated reads
    char **reads = generate_reads(sequenced_sequence, 1000, 10);

    // Print reads
    print_reads(reads, 100);

    // Free allocated memory
    free(sequence);
    free(sequenced_sequence);
    for (int i = 0; i < 100; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}