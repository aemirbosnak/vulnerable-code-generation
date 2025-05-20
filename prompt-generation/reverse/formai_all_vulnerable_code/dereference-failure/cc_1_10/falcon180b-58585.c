//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 5
#define MAX_NUM_OF_SEQUENCES 10

// define the alphabet
char alphabet[] = "ACGTU";

// define the sequence length
int sequence_length;

// define the number of sequences to generate
int num_of_sequences;

// define the sequences
char *sequences[MAX_NUM_OF_SEQUENCES];

// define the function to generate a random sequence
void generate_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        char base = alphabet[rand() % strlen(alphabet)];
        sequence[i] = base;
    }
    sequence[length] = '\0';
}

// define the function to print a sequence
void print_sequence(char *sequence) {
    printf("%s\n", sequence);
}

// define the main function
int main() {
    // seed the random number generator
    srand(time(NULL));

    // prompt the user for the sequence length
    printf("Enter the sequence length: ");
    scanf("%d", &sequence_length);

    // prompt the user for the number of sequences to generate
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &num_of_sequences);

    // generate the sequences
    for (int i = 0; i < num_of_sequences; i++) {
        sequences[i] = (char *)malloc(sequence_length + 1);
        generate_sequence(sequences[i], sequence_length);
    }

    // print the sequences
    for (int i = 0; i < num_of_sequences; i++) {
        print_sequence(sequences[i]);
    }

    // free the memory
    for (int i = 0; i < num_of_sequences; i++) {
        free(sequences[i]);
    }

    return 0;
}