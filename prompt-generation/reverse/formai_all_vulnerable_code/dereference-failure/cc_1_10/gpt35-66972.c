//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random nucleotide */
char generate_nucleotide()
{
    int rand_num = rand() % 4;

    if (rand_num == 0)
    {
        return 'A';
    }
    else if (rand_num == 1)
    {
        return 'C';
    }
    else if (rand_num == 2)
    {
        return 'G';
    }
    else
    {
        return 'T';
    }
}

/* Function to generate a random DNA sequence */
char* generate_DNA_sequence(int length)
{
    char* DNA_sequence = (char*) malloc(length * sizeof(char));
    int i;

    for (i = 0; i < length; i++)
    {
        DNA_sequence[i] = generate_nucleotide();
    }

    return DNA_sequence;
}

/* Function to print the DNA sequence */
void print_DNA_sequence(char* DNA_sequence, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%c", DNA_sequence[i]);
    }

    printf("\n");
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int sequence_length = 50; // Example sequence length
    char* DNA_sequence = generate_DNA_sequence(sequence_length);

    printf("Random DNA sequence:\n");
    print_DNA_sequence(DNA_sequence, sequence_length);

    free(DNA_sequence); // Free the dynamically allocated memory

    return 0;
}