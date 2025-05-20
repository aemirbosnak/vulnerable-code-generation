//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000

// Function to generate a random DNA sequence
void generate_sequence(char *sequence, int length) {
    const char bases[] = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = bases[rand() % 4];
    }
    sequence[length] = '\0';
}

// Function to print a DNA sequence
void print_sequence(const char *sequence) {
    printf("%s\n", sequence);
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(int num_reads, int read_length, int sequence_length) {
    srand(time(NULL));

    // Generate the reference sequence
    char reference_sequence[MAX_SEQUENCE_LENGTH];
    generate_sequence(reference_sequence, sequence_length);

    // Simulate reads
    char *reads[num_reads];
    for (int i = 0; i < num_reads; i++) {
        reads[i] = malloc(read_length + 1);
        generate_sequence(reads[i], read_length);
    }

    // Map reads to the reference sequence
    int *positions[num_reads];
    for (int i = 0; i < num_reads; i++) {
        positions[i] = malloc(sizeof(int));
        *positions[i] = -1;
    }

    for (int i = 0; i < num_reads; i++) {
        int j = 0;
        while (j < sequence_length - read_length + 1) {
            int k;
            for (k = 0; k < read_length && reference_sequence[j + k] == reads[i][k]; k++) {
                // Do nothing
            }
            if (k == read_length) {
                *positions[i] = j;
                break;
            }
            j++;
        }
    }

    // Print the results
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d maps to position %d\n", i + 1, *positions[i] + 1);
        print_sequence(reads[i]);
    }

    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
        free(positions[i]);
    }
}

int main() {
    int num_reads, read_length, sequence_length;
    printf("Enter the number of reads: ");
    scanf("%d", &num_reads);
    printf("Enter the read length: ");
    scanf("%d", &read_length);
    printf("Enter the sequence length: ");
    scanf("%d", &sequence_length);

    simulate_genome_sequencing(num_reads, read_length, sequence_length);

    return 0;
}