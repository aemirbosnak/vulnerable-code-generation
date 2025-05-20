//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_SAMPLES 5

const char nucleotides[] = "ACGT";

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null termination of string
}

void mutate_sequence(char *sequence, int mutation_rate) {
    for (int i = 0; i < strlen(sequence); i++) {
        if (rand() % 100 < mutation_rate) {
            // Mutate the nucleotide
            char current_nucleotide = sequence[i];
            char new_nucleotide;
            do {
                new_nucleotide = nucleotides[rand() % 4];
            } while (new_nucleotide == current_nucleotide); // Ensure it's a different nucleotide
            sequence[i] = new_nucleotide;
        }
    }
}

void simulate_sequencing(char *sequence) {
    printf("Simulating sequencing on the DNA sequence...\n");
    // Simple simulation, just print and fake some noise
    for (int i = 0; i < strlen(sequence); i++) {
        if (rand() % 10 < 2) // Introduce some noise
            printf("N");
        else
            printf("%c", sequence[i]);
    }
    printf("\nSequencing complete!\n");
}

void print_usage() {
    printf("Genome Sequencing Simulator\n");
    printf("Usage: ./genome-sequencer <length_of_sequence> <mutation_rate>\n");
    printf("Example: ./genome-sequencer 50 10\n");
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed the random number generator

    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    int length_of_sequence = atoi(argv[1]);
    int mutation_rate = atoi(argv[2]);

    if (length_of_sequence <= 0 || length_of_sequence > MAX_SEQUENCE_LENGTH || mutation_rate < 0 || mutation_rate > 100) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Array to store generated sequences
    char sequences[NUM_SAMPLES][MAX_SEQUENCE_LENGTH + 1];

    // Generate and mutate sequences
    for (int i = 0; i < NUM_SAMPLES; i++) {
        generate_random_sequence(sequences[i], length_of_sequence);
        printf("Original Sequence %d: %s\n", i + 1, sequences[i]);
        mutate_sequence(sequences[i], mutation_rate);
        printf("Mutated Sequence %d: %s\n", i + 1, sequences[i]);
    }

    // Simulate sequencing
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("\nSequence %d:\n", i + 1);
        simulate_sequencing(sequences[i]);
    }

    return EXIT_SUCCESS;
}