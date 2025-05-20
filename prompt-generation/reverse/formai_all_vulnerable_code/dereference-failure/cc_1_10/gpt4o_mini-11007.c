//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define SEQUENCE_TYPES 4

const char *BASES[SEQUENCE_TYPES] = {"A", "C", "G", "T"};

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        int index = rand() % SEQUENCE_TYPES;
        strcpy(&sequence[i], BASES[index]);
        i++;  // Move to the next position for the next base
    }
    sequence[length] = '\0';  // Null terminate the string
}

void mutate_sequence(char *sequence, float mutation_rate) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if (((float)rand() / RAND_MAX) < mutation_rate) {
            int index = rand() % SEQUENCE_TYPES;
            sequence[i] = *BASES[index];  // Replace base with a random base
        }
    }
}

void simulate_sequencing(char *sequence, char *simulated_sequence, float error_rate) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if (((float)rand() / RAND_MAX) < error_rate) {
            int index = rand() % SEQUENCE_TYPES;
            simulated_sequence[i] = *BASES[index];  // Introduce an error in the sequence
        } else {
            simulated_sequence[i] = sequence[i];  // No error, copy base
        }
    }
    simulated_sequence[length] = '\0';  // Null terminate the string
}

void write_sequence_to_file(const char *filename, const char *sequence) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        exit(1);
    }
    fprintf(file, "%s\n", sequence);
    fclose(file);
}

void read_sequence_from_file(const char *filename, char *sequence) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        exit(1);
    }
    if (fgets(sequence, MAX_GENOME_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading sequence from file.\n");
        fclose(file);
        exit(1);
    }
    fclose(file);
}

void print_sequence(const char *sequence) {
    printf("Sequence: %s\n", sequence);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <length> <mutation_rate> <error_rate> <output_file>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);
    float mutation_rate = atof(argv[2]);
    float error_rate = atof(argv[3]);
    const char *output_file = argv[4];

    if (length <= 0 || length > MAX_GENOME_LENGTH) {
        fprintf(stderr, "Length must be a positive integer and less than %d.\n", MAX_GENOME_LENGTH);
        return 1;
    }
    if (mutation_rate < 0.0 || mutation_rate > 1.0) {
        fprintf(stderr, "Mutation rate must be between 0.0 and 1.0.\n");
        return 1;
    }
    if (error_rate < 0.0 || error_rate > 1.0) {
        fprintf(stderr, "Error rate must be between 0.0 and 1.0.\n");
        return 1;
    }

    srand(time(NULL));  // Initialize random number generator

    char original_sequence[MAX_GENOME_LENGTH + 1];
    char mutated_sequence[MAX_GENOME_LENGTH + 1];
    char simulated_sequence[MAX_GENOME_LENGTH + 1];

    // Step 1: Generate random sequence
    generate_random_sequence(original_sequence, length);
    printf("Original ");
    print_sequence(original_sequence);

    // Step 2: Mutate the original sequence based on mutation rate
    strcpy(mutated_sequence, original_sequence);  // Copy original sequence
    mutate_sequence(mutated_sequence, mutation_rate);
    printf("Mutated ");
    print_sequence(mutated_sequence);

    // Step 3: Simulate sequencing process
    simulate_sequencing(mutated_sequence, simulated_sequence, error_rate);
    printf("Simulated Sequencing Result ");
    print_sequence(simulated_sequence);

    // Step 4: Write the simulated sequence to a file
    write_sequence_to_file(output_file, simulated_sequence);
    printf("Simulated sequence written to %s\n", output_file);

    return 0;
}