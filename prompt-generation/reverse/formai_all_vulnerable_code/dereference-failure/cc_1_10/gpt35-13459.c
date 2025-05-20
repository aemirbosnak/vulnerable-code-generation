//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n~**~ Welcome to the C Genome Sequencing Simulator ~**~\n");
    printf("In this program, we'll simulate the process of sequencing a genome.\n");

    srand(time(NULL)); //seed rand function with current time

    //Ask user for the length of genome to be sequenced
    int genomeLength;
    printf("\nPlease enter the length of the genome to be sequenced: ");
    scanf("%d", &genomeLength);

    //Allocate memory for array to store nucleotides
    char* genome = (char*)malloc(sizeof(char) * genomeLength);

    //Loop through the genome array and randomly assign nucleotides
    for (int i = 0; i < genomeLength; i++)
    {
        int nucleotide = rand() % 4; //generate random number between 0-3 to select nucleotide

        switch (nucleotide)
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

    //Print the sequenced genome
    printf("\n\nThe sequenced genome is:\n");
    for (int i = 0; i < genomeLength; i++)
    {
        printf("%c", genome[i]);
    }

    //Free allocated memory
    free(genome);

    printf("\n\n~**~ Genome sequencing simulation complete! ~**~\n");

    return 0;
}