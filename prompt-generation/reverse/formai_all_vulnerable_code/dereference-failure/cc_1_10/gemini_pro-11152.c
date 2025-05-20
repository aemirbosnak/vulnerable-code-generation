//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_BASES 4
#define BASE_A 'A'
#define BASE_C 'C'
#define BASE_G 'G'
#define BASE_T 'T'

// Generate a random base
char generate_base() {
    int r = rand() % NUM_BASES;
    switch (r) {
        case 0:
            return BASE_A;
        case 1:
            return BASE_C;
        case 2:
            return BASE_G;
        case 3:
            return BASE_T;
    }
    return 0;  // Should never happen
}

// Generate a random sequence of bases
char *generate_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = generate_base();
    }
    sequence[length] = '\0';
    return sequence;
}

// Print a sequence of bases
void print_sequence(char *sequence) {
    printf("%s\n", sequence);
}

// Get the reverse complement of a sequence
char *reverse_complement(char *sequence) {
    int length = strlen(sequence);
    char *reverse_complement = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        switch (sequence[i]) {
            case BASE_A:
                reverse_complement[length - i - 1] = BASE_T;
                break;
            case BASE_C:
                reverse_complement[length - i - 1] = BASE_G;
                break;
            case BASE_G:
                reverse_complement[length - i - 1] = BASE_C;
                break;
            case BASE_T:
                reverse_complement[length - i - 1] = BASE_A;
                break;
        }
    }
    reverse_complement[length] = '\0';
    return reverse_complement;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random sequence of bases
    char *sequence = generate_sequence(100);

    // Print the sequence
    printf("Original sequence:\n");
    print_sequence(sequence);

    // Get the reverse complement of the sequence
    char *reverse_complement_sequence = reverse_complement(sequence);

    // Print the reverse complement sequence
    printf("Reverse complement sequence:\n");
    print_sequence(reverse_complement_sequence);

    // Free the allocated memory
    free(sequence);
    free(reverse_complement_sequence);

    return 0;
}