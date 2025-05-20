//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_BASE_TYPES 4

// Define the base types
#define A 0
#define C 1
#define G 2
#define T 3

int main(int argc, char *argv[]) {
    int seq_length;
    int base_type;
    char *genome_sequence;

    // Get the sequence length from the user
    printf("Enter the sequence length: ");
    scanf("%d", &seq_length);

    // Allocate memory for the genome sequence
    genome_sequence = (char *) malloc(seq_length * sizeof(char));

    // Generate a random genome sequence
    srand(time(NULL));
    for (int i = 0; i < seq_length; i++) {
        base_type = rand() % MAX_BASE_TYPES;
        switch (base_type) {
            case A:
                genome_sequence[i] = 'A';
                break;
            case C:
                genome_sequence[i] = 'C';
                break;
            case G:
                genome_sequence[i] = 'G';
                break;
            case T:
                genome_sequence[i] = 'T';
                break;
        }
    }

    // Print the genome sequence
    printf("\nGenome Sequence:\n");
    for (int i = 0; i < seq_length; i++) {
        printf("%c", genome_sequence[i]);
    }
    printf("\n");

    // Free the memory
    free(genome_sequence);

    return 0;
}