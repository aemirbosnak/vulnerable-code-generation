//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_BASES 4

const char bases[NUM_BASES] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide sequence
void generate_sequence(char* sequence, int length, int position) {
    if (position == length) {
        sequence[position] = '\0';
        return;
    }

    // Randomly select a base
    sequence[position] = bases[rand() % NUM_BASES];
    generate_sequence(sequence, length, position + 1);
}

// Function to simulate sequencing by introducing random errors
void simulate_sequencing_error(char* sequence, char* simulated_sequence, int length, int position, double error_rate) {
    if (position == length) {
        simulated_sequence[position] = '\0';
        return;
    }

    // Determine if we should introduce an error
    if ((double)rand() / RAND_MAX < error_rate) {
        // Introduce an error: randomly change the base
        simulated_sequence[position] = bases[rand() % NUM_BASES];
    } else {
        simulated_sequence[position] = sequence[position];
    }

    simulate_sequencing_error(sequence, simulated_sequence, length, position + 1, error_rate);
}

// Function to print out the sequence in a formatted way
void print_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        putchar(sequence[i]);
        // Print a newline every 50 bases for better readability
        if ((i + 1) % 50 == 0) {
            putchar('\n');
        }
    }
    putchar('\n'); // Final newline
}

int main() {
    srand(time(NULL));

    int length;
    double error_rate;

    // Get user input for sequence length and error rate
    printf("Enter the length of the genomic sequence (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &length);

    // Validate length
    if (length <= 0 || length > MAX_SEQUENCE_LENGTH) {
        fprintf(stderr, "Invalid sequence length.\n");
        return 1;
    }

    printf("Enter the error rate (0.0 to 1.0): ");
    scanf("%lf", &error_rate);

    // Validate error rate
    if (error_rate < 0.0 || error_rate > 1.0) {
        fprintf(stderr, "Invalid error rate. Must be between 0.0 and 1.0.\n");
        return 1;
    }

    char* original_sequence = malloc((length + 1) * sizeof(char));
    char* simulated_sequence = malloc((length + 1) * sizeof(char));

    // Generate the original sequence
    generate_sequence(original_sequence, length, 0);

    // Simulate sequencing with errors
    simulate_sequencing_error(original_sequence, simulated_sequence, length, 0, error_rate);

    // Print the sequences
    printf("Original Sequence:\n");
    print_sequence(original_sequence, length);

    printf("Simulated Sequence (with errors):\n");
    print_sequence(simulated_sequence, length);

    // Free allocated memory
    free(original_sequence);
    free(simulated_sequence);

    return 0;
}