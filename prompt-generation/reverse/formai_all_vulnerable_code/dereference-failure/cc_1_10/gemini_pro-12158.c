//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structures and constants
typedef struct _Sequence {
    char* sequence;
    int length;
} Sequence;

#define MAX_SEQUENCE_LENGTH 1000

// Function prototypes
void generate_random_sequence(Sequence* sequence);
void print_sequence(Sequence* sequence);
void compare_sequences(Sequence* sequence1, Sequence* sequence2);

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create two sequences
    Sequence sequence1;
    Sequence sequence2;

    // Generate random sequences
    generate_random_sequence(&sequence1);
    generate_random_sequence(&sequence2);

    // Print the sequences
    printf("Sequence 1:\n");
    print_sequence(&sequence1);
    printf("\nSequence 2:\n");
    print_sequence(&sequence2);

    // Compare the sequences
    compare_sequences(&sequence1, &sequence2);

    // Free the sequences
    free(sequence1.sequence);
    free(sequence2.sequence);

    return 0;
}

// Generate a random sequence of characters
void generate_random_sequence(Sequence* sequence) {
    // Allocate memory for the sequence
    sequence->sequence = (char*)malloc(MAX_SEQUENCE_LENGTH * sizeof(char));

    // Generate random characters
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        sequence->sequence[i] = (char)(rand() % 4 + 'A');
    }

    // Set the length of the sequence
    sequence->length = MAX_SEQUENCE_LENGTH;
}

// Print a sequence of characters
void print_sequence(Sequence* sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
}

// Compare two sequences of characters
void compare_sequences(Sequence* sequence1, Sequence* sequence2) {
    // Check if the sequences are the same length
    if (sequence1->length != sequence2->length) {
        printf("The sequences are not the same length.\n");
        return;
    }

    // Compare the sequences character by character
    int mismatches = 0;
    for (int i = 0; i < sequence1->length; i++) {
        if (sequence1->sequence[i] != sequence2->sequence[i]) {
            mismatches++;
        }
    }

    // Print the number of mismatches
    printf("The sequences have %d mismatches.\n", mismatches);
}