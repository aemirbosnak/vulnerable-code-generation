//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000

char nucleotides[] = {'A', 'C', 'G', 'T'};

void generate_sequence(char* sequence, int length) {
    // Generate a random DNA sequence of the given length
    int i;
    for (i = 0; i < length; i++) {
        int r = rand() % 4;
        sequence[i] = nucleotides[r];
    }
    sequence[length] = '\0';
}

void mutate_sequence(char* sequence, int length, int num_mutations) {
    // Mutate the given sequence by randomly changing nucleotides
    int i;
    for (i = 0; i < num_mutations; i++) {
        int r = rand() % length;
        int r2 = rand() % 4;
        sequence[r] = nucleotides[r2];
    }
}

void print_sequence(char* sequence, int length) {
    // Print the given sequence with line breaks for readability
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", sequence[i]);
        if ((i+1) % 50 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void print_stats(int num_sequences, int sequence_length, int num_mutations) {
    // Print statistics about the generated and mutated sequences
    printf("Generated %d sequences of length %d\n", num_sequences, sequence_length);
    printf("Mutated %d of those sequences with %d mutations each\n", num_sequences/2, num_mutations);
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    char sequences[MAX_SEQ_LENGTH][MAX_SEQ_LENGTH+1];  // Store all the generated sequences
    
    int num_sequences = 0;
    int sequence_length = 0;
    int num_mutations = 0;
    
    printf("Welcome to the DNA sequencing simulator!\n");
    printf("How many sequences would you like to generate? ");
    scanf("%d", &num_sequences);
    printf("What should be the length of each sequence? ");
    scanf("%d", &sequence_length);
    printf("How many mutations should each sequence have? ");
    scanf("%d", &num_mutations);
    
    int i;
    for (i = 0; i < num_sequences; i++) {
        char* sequence = sequences[i];
        
        // Generate a random sequence
        generate_sequence(sequence, sequence_length);
        
        // Mutate the sequence
        if (i < num_sequences/2) {
            mutate_sequence(sequence, sequence_length, num_mutations);
        }
        
        // Print the sequence
        printf("Sequence %d:\n", i+1);
        print_sequence(sequence, sequence_length);
    }
    
    // Print statistics
    print_stats(num_sequences, sequence_length, num_mutations);
    
    return 0;
}