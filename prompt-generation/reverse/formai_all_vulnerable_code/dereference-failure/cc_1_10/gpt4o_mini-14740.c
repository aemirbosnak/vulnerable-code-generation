//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define NUM_SEQUENCES 5
#define BASES "ACGT"

// Function to generate a random nucleotide sequence
void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4]; // Pick random base
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to simulate a mutation in the sequence
void mutate_sequence(char *sequence, double mutation_rate) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            sequence[i] = BASES[rand() % 4]; // Mutate to a different base
        }
    }
}

// Function to simulate a sequencing run
void simulate_sequencing(char **sequences, int num_sequences, double mutation_rate) {
    for (int i = 0; i < num_sequences; i++) {
        char mutated_sequence[MAX_SEQUENCE_LENGTH];
        strcpy(mutated_sequence, sequences[i]); // Copy original sequence
        mutate_sequence(mutated_sequence, mutation_rate); // Mutate the sequence
        printf("Original sequence: %s\n", sequences[i]);
        printf("Mutated sequence: %s\n", mutated_sequence);
        printf("---------------------------------------\n");
    }
}

// Function to create a report of the sequences
void create_report(char **sequences, int num_sequences) {
    FILE *report = fopen("genome_report.txt", "w");
    if (report == NULL) {
        perror("Error creating report file");
        return;
    }
    fprintf(report, "Genome Sequencing Report\n");
    fprintf(report, "========================\n");
    for (int i = 0; i < num_sequences; i++) {
        fprintf(report, "Sequence %d: %s\n", i + 1, sequences[i]);
    }
    fclose(report);
    printf("Report generated: genome_report.txt\n");
}

// Function to visualize the sequences (basic representation)
void visualize_sequences(char **sequences, int num_sequences) {
    printf("Visualizing Sequences:\n");
    printf("======================\n");
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: ", i + 1);
        for (int j = 0; j < strlen(sequences[i]); j++) {
            if (j % 50 == 0 && j > 0) {
                printf("\n               ");
            }
            printf("%c", sequences[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    char *sequences[NUM_SEQUENCES];
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequences[i] = (char *)malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        generate_random_sequence(sequences[i], rand() % (MAX_SEQUENCE_LENGTH - 1) + 1);
    }

    double mutation_rate = 0.05; // 5% mutation rate
    simulate_sequencing(sequences, NUM_SEQUENCES, mutation_rate); // Simulate sequencing
    create_report(sequences, NUM_SEQUENCES); // Create report
    visualize_sequences(sequences, NUM_SEQUENCES); // Visualize the sequences

    // Free dynamically allocated memory
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i]);
    }
    
    return 0;
}