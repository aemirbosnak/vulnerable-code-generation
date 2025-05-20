//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// "Ken Thompson style" is a bit vague. I'll interpret it as
// "code that is short, efficient, and uses clever tricks".

// This program simulates the sequencing of a DNA genome.
// It generates a random string of DNA bases (A, C, G, or T)
// and then simulates the sequencing process by randomly
// introducing errors into the sequence.

// The following function generates a random DNA sequence of
// length n.
char *generate_dna_sequence(int n)
{
    char *sequence = malloc(n + 1);  // +1 for the null terminator
    for (int i = 0; i < n; i++)
    {
        int base = rand() % 4;
        switch (base)
        {
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
        }
    }

    sequence[n] = '\0';  // null terminate the string
    return sequence;
}

// The following function simulates the sequencing process by
// randomly introducing errors into the sequence.
char *sequence_sequencing(char *sequence, double error_rate)
{
    int n = strlen(sequence);
    char *sequenced_sequence = malloc(n + 1);  // +1 for the null terminator
    for (int i = 0; i < n; i++)
    {
        // Generate a random number between 0 and 1.
        double r = (double)rand() / (double)RAND_MAX;

        // If the random number is less than the error rate,
        // then introduce an error into the sequence.
        if (r < error_rate)
        {
            int base = rand() % 4;
            switch (base)
            {
            case 0:
                sequenced_sequence[i] = 'A';
                break;
            case 1:
                sequenced_sequence[i] = 'C';
                break;
            case 2:
                sequenced_sequence[i] = 'G';
                break;
            case 3:
                sequenced_sequence[i] = 'T';
                break;
            }
        }
        else
        {
            sequenced_sequence[i] = sequence[i];
        }
    }

    sequenced_sequence[n] = '\0';  // null terminate the string
    return sequenced_sequence;
}

int main(int argc, char **argv)
{
    // Generate a random DNA sequence of length 1000.
    char *sequence = generate_dna_sequence(1000);

    // Simulate the sequencing process with an error rate of 1%.
    char *sequenced_sequence = sequence_sequencing(sequence, 0.01);

    // Print the original sequence and the sequenced sequence.
    printf("Original sequence: %s\n", sequence);
    printf("Sequenced sequence: %s\n", sequenced_sequence);

    free(sequence);
    free(sequenced_sequence);

    return 0;
}