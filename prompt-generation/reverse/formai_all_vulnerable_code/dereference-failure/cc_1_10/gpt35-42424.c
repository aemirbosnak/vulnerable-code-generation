//FormAI DATASET v1.0 Category: Computer Biology ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Defining a structure to represent a DNA sequence
typedef struct {
    char *sequence;
    int length;
} DNA;

// Define a function to randomly generate DNA sequences
void generate_DNA_sequence(DNA *sequence) {
    // Allocate memory for the DNA sequence
    sequence->sequence = malloc(sizeof(char) * sequence->length);

    // Generate random base pairs for the sequence
    char base_pairs[] = "ATCG";
    for (int i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = base_pairs[rand() % 4];
    }
}

// Define a function to calculate the GC content of a DNA sequence
float calculate_GC_content(DNA *sequence) {
    int gc_count = 0;
    for (int i = 0; i < sequence->length; i++) {
        if (sequence->sequence[i] == 'G' || sequence->sequence[i] == 'C') {
            gc_count++;
        }
    }
    return (float) gc_count / sequence->length;
}

int main() {
    // Generate a random DNA sequence of length 100
    DNA sequence;
    sequence.length = 100;
    generate_DNA_sequence(&sequence);

    // Print the DNA sequence to the console
    printf("Generated DNA sequence of length %d:\n%s\n\n", sequence.length, sequence.sequence);

    // Calculate the GC content of the DNA sequence
    float gc_content = calculate_GC_content(&sequence);
    printf("GC content: %.2f%%\n", gc_content * 100);

    // Free memory allocated for the DNA sequence
    free(sequence.sequence);

    return 0;
}