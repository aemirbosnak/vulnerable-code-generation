//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // initialize variables
    int genome_length = 1000;
    char nucleotides[4] = {'A', 'T', 'C', 'G'};
    int num_mutations = 100;
    int mutation_range = 500;

    // allocate memory for genome sequence
    char* genome_sequence = (char*) malloc(genome_length * sizeof(char));

    // generate random genome sequence
    for(int i = 0; i < genome_length; i++)
    {
        int rand_index = rand() % 4;
        genome_sequence[i] = nucleotides[rand_index];
    }

    // simulate mutations in genome sequence
    for(int i = 0; i < num_mutations; i++)
    {
        // generate random mutation location
        int mutation_location = rand() % genome_length;

        // generate random mutation range
        int mutation_start = mutation_location - mutation_range/2;
        if(mutation_start < 0) mutation_start = 0;

        int mutation_end = mutation_location + mutation_range/2;
        if(mutation_end > genome_length-1) mutation_end = genome_length-1;

        // apply mutation to genome sequence
        int rand_index = rand() % 4;
        for(int j = mutation_start; j <= mutation_end; j++)
        {
            genome_sequence[j] = nucleotides[rand_index];
        }
    }

    // print final genome sequence
    printf("Final genome sequence:\n");
    for(int i = 0; i < genome_length; i++)
    {
        printf("%c", genome_sequence[i]);
    }

    return 0;
}