//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function to generate a random DNA sequence
char *generate_dna_sequence(int length)
{
    char *sequence = (char *)malloc(length + 1);
    int i;

    // Initialize the random number generator
    srand(time(NULL));

    // Generate the random DNA sequence
    for (i = 0; i < length; i++)
    {
        int random_number = rand() % 4;
        switch (random_number)
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

    // Terminate the string
    sequence[length] = '\0';

    return sequence;
}

// Function to write the DNA sequence to a file
void write_dna_sequence_to_file(char *sequence, char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "%s", sequence);

    fclose(file);
}

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments have been provided
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <length> <filename>\n", argv[0]);
        exit(1);
    }

    // Get the length of the DNA sequence
    int length = atoi(argv[1]);

    // Generate the DNA sequence
    char *sequence = generate_dna_sequence(length);

    // Write the DNA sequence to a file
    write_dna_sequence_to_file(sequence, argv[2]);

    // Free the memory allocated for the DNA sequence
    free(sequence);

    return 0;
}