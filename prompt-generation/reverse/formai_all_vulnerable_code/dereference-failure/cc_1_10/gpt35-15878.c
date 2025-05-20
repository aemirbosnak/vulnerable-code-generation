//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum and minimum length of the genome
#define MAX_GENOME_LENGTH 1000
#define MIN_GENOME_LENGTH 100

// Base pair symbols
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Generate random genome length
    int genome_length = rand() % (MAX_GENOME_LENGTH - MIN_GENOME_LENGTH + 1) + MIN_GENOME_LENGTH;

    // Allocate memory for genome sequence
    char *genome = (char *)malloc(genome_length * sizeof(char));

    // Randomly generate genome sequence
    for(int i = 0; i < genome_length; i++)
    {
        int random_number = rand() % 4;
        switch(random_number)
        {
            case 0:
                genome[i] = A;
                break;

            case 1:
                genome[i] = C;
                break;

            case 2:
                genome[i] = G;
                break;

            case 3:
                genome[i] = T;
                break;

            default:
                break;
        }
    }

    // Print genome sequence in 50 base pair chunks
    int chunks = genome_length / 50;
    for(int i = 0; i < chunks; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            printf("%c", genome[i*50 + j]);
        }
        printf("\n");
    }

    // Free memory
    free(genome);

    return 0;
}