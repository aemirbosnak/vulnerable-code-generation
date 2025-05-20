//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define NUM_SEQUENCES 10
#define SEQUENCE_LENGTH 100

char* generate_random_sequence(int length) {
    char* sequence = (char*)malloc((length + 1) * sizeof(char));
    char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null terminate the string
    return sequence;
}

void print_sequence(const char* seq, int line_length) {
    int length = strlen(seq);
    for (int i = 0; i < length; i++) {
        putchar(seq[i]);
        if ((i + 1) % line_length == 0) {
            putchar('\n');
        }
    }
    putchar('\n'); // Print a new line at the end
}

void save_sequence_to_file(const char* filename, const char* sequence) {
    FILE* fptr = fopen(filename, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(fptr, "%s\n", sequence);
    fclose(fptr);
}

void simulate_genome_sequencing() {
    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        char filename[20];
        sprintf(filename, "genome_%d.txt", i + 1);
        
        char* sequence = generate_random_sequence(SEQUENCE_LENGTH);
        printf("Generated Sequence %d: \n", i + 1);
        print_sequence(sequence, 50); // Print the sequence with 50 characters per line
        save_sequence_to_file(filename, sequence);
        
        free(sequence);
    }

    printf("Genome sequencing simulation complete. Check files for generated sequences.\n");
}

int main() {
    printf("Welcome to the C Genome Sequencing Simulator!\n");
    simulate_genome_sequencing();
    return 0;
}