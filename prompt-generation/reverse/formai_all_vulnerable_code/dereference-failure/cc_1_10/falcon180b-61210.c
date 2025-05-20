//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_MUTATIONS 10

// Function to generate a random DNA sequence
void generate_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        int choice = rand() % 4;
        switch (choice) {
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
            default:
                printf("Error: Invalid choice in generate_sequence()\n");
                exit(1);
        }
    }
    sequence[length] = '\0';
}

// Function to introduce mutations into a DNA sequence
void introduce_mutations(char* sequence, int num_mutations) {
    for (int i = 0; i < num_mutations; i++) {
        int position = rand() % strlen(sequence);
        switch (rand() % 4) {
            case 0:
                sequence[position] = (sequence[position] == 'A')? 'C' : 'A';
                break;
            case 1:
                sequence[position] = (sequence[position] == 'C')? 'G' : 'C';
                break;
            case 2:
                sequence[position] = (sequence[position] == 'G')? 'A' : 'G';
                break;
            case 3:
                sequence[position] = (sequence[position] == 'T')? 'C' : 'T';
                break;
            default:
                printf("Error: Invalid choice in introduce_mutations()\n");
                exit(1);
        }
    }
}

// Function to simulate sequencing a DNA fragment
void simulate_sequencing(char* sequence, int read_length) {
    int num_reads = (int) ceil((double) strlen(sequence) / (double) read_length);
    for (int i = 0; i < num_reads; i++) {
        int start_position = i * read_length;
        int end_position = (i == num_reads - 1)? strlen(sequence) - 1 : (i + 1) * read_length - 1;
        printf("Read %d: %.*s\n", i + 1, end_position - start_position + 1, &sequence[start_position]);
    }
}

int main() {
    srand(time(NULL));

    char* genome_sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    generate_sequence(genome_sequence, MAX_SEQUENCE_LENGTH);

    char* sequencing_reads = malloc((MAX_SEQUENCE_LENGTH / MAX_READ_LENGTH) * MAX_READ_LENGTH * sizeof(char));

    printf("Genome sequence:\n");
    simulate_sequencing(genome_sequence, MAX_READ_LENGTH);

    printf("\nIntroducing mutations...\n");
    introduce_mutations(genome_sequence, MAX_MUTATIONS);

    printf("\nSequencing reads after introducing mutations:\n");
    simulate_sequencing(genome_sequence, MAX_READ_LENGTH);

    free(genome_sequence);
    free(sequencing_reads);

    return 0;
}