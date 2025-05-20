//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_LENGTH 1000   // Length of genome
#define BASES_COUNT 4   // Number of different DNA bases

// Function to create random genome
char* create_genome()
{
    char *genome = (char*)malloc(sizeof(char) * GENOME_LENGTH);

    // Generate random genome sequence
    for(int i=0; i<GENOME_LENGTH; i++)
    {
        int base = rand() % BASES_COUNT;
        switch(base)
        {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
            default:
                break;
        }
    }
    return genome;
}

// Function to simulate genome sequencing
char* simulate_sequencing(char* genome, float error_rate)
{
    char *sequenced_genome = (char*)malloc(sizeof(char) * GENOME_LENGTH);

    // Generate random sequence with some errors
    for(int i=0; i<GENOME_LENGTH; i++)
    {
        float error_probability = (rand() % 1001) / 1000.0;
        if(error_probability <= error_rate)
        {
            // Generate random base different from original base
            int base = rand() % (BASES_COUNT-1);
            switch(genome[i])
            {
                case 'A':
                    sequenced_genome[i] = (base == 0) ? 'T' : ((base == 1) ? 'C' : 'G');
                    break;
                case 'T':
                    sequenced_genome[i] = (base == 0) ? 'A' : ((base == 1) ? 'C' : 'G');
                    break;
                case 'C':
                    sequenced_genome[i] = (base == 0) ? 'A' : ((base == 1) ? 'T' : 'G');
                    break;
                case 'G':
                    sequenced_genome[i] = (base == 0) ? 'A' : ((base == 1) ? 'T' : 'C');
                    break;
                default:
                    break;
            }
        }
        else
        {
            sequenced_genome[i] = genome[i];
        }
    }
    return sequenced_genome;
}

int main()
{
    srand(time(NULL));  // Initialize random number generator

    char *genome = create_genome();
    float error_rate;
    printf("Enter sequencing error rate (in percentage): ");
    scanf("%f", &error_rate);

    char *sequenced_genome = simulate_sequencing(genome, error_rate/100.0);

    printf("\nOriginal Genome: %s\n", genome);
    printf("Sequenced Genome: %s\n", sequenced_genome);

    free(genome);
    free(sequenced_genome);
    
    return 0;
}