//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_SIZE 100000

char *generateRandomGenome(int genomeSize)
{
    char *genome = (char *)malloc(genomeSize * sizeof(char));
    int i;

    srand(time(NULL));

    for (i = 0; i < genomeSize; i++)
    {
        switch (rand() % 4)
        {
        case 0:
            genome[i] = 'A';
            break;
        case 1:
            genome[i] = 'C';
            break;
        case 2:
            genome[i] = 'G';
            break;
        case 3:
            genome[i] = 'T';
            break;
        }
    }

    genome[genomeSize] = '\0';

    return genome;
}

int main(int argc, char *argv[])
{
    char *genome, *genomeCopy;
    int genomeSize;

    if (argc != 2)
    {
        printf("Usage: %s <size_of_genome>\n", argv[0]);
        return 1;
    }

    genomeSize = atoi(argv[1]);

    if (genomeSize > MAX_GENOME_SIZE)
    {
        printf("Error: maximum genome size is %d\n", MAX_GENOME_SIZE);
        return 1;
    }

    genome = generateRandomGenome(genomeSize);
    genomeCopy = (char *)malloc((genomeSize + 1) * sizeof(char));

    printf("Original genome: %s\n", genome);

    strcpy(genomeCopy, genome);
    printf("Copied genome: %s\n", genomeCopy);

    free(genome);
    free(genomeCopy);

    return 0;
}