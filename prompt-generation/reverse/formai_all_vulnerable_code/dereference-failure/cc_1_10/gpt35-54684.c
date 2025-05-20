//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int genomeSize, numSequences; //variables to store user input
    int *genome; //variable to store genome sequence dynamically
    int **sequences; //variable to store generated sequences dynamically
    int i, j, k; //iterative variables
    
    //get user input for genome size and number of sequences to generate
    printf("Enter genome size: ");
    scanf("%d", &genomeSize);
    printf("Enter number of sequences to generate: ");
    scanf("%d", &numSequences);
    
    //allocate memory for genome and sequences arrays
    genome = malloc(genomeSize * sizeof(int));
    sequences = malloc(numSequences * sizeof(int *));
    for(i = 0; i < numSequences; i++)
        sequences[i] = malloc(genomeSize * sizeof(int));
    
    //populate genome with random nucleotides (represented as integers)
    srand(time(NULL));
    for(i = 0; i < genomeSize; i++)
    {
        genome[i] = rand() % 4; //4 possible nucleotides: 0=A, 1=C, 2=T, 3=G
        printf("%d ", genome[i]);
    }
    printf("\n");
    
    //generate sequences by randomly mutating genome
    for(i = 0; i < numSequences; i++)
    {
        for(j = 0; j < genomeSize; j++)
        {
            sequences[i][j] = genome[j]; //copy genome to sequence
            if(rand() % 10 == 0) //10% chance to mutate nucleotide
            {
                sequences[i][j] = rand() % 4; //replace nucleotide with random new nucleotide
            }
        }
    }
    
    //print generated sequences
    for(i = 0; i < numSequences; i++)
    {
        for(j = 0; j < genomeSize; j++)
        {
            printf("%d ", sequences[i][j]);
        }
        printf("\n");
    }
    
    //free dynamically allocated memory
    free(genome);
    for(i = 0; i < numSequences; i++)
        free(sequences[i]);
    free(sequences);
    
    return 0;
}