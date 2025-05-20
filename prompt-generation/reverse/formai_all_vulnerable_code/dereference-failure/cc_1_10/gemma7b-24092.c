//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define NUM_READS 1000

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the reads
    char **reads = (char **)malloc(NUM_READS * sizeof(char *));
    for (int i = 0; i < NUM_READS; i++)
    {
        reads[i] = (char *)malloc(MAX_READ_LENGTH * sizeof(char));
    }

    // Generate reads
    for (int i = 0; i < NUM_READS; i++)
    {
        // Randomly select the read length
        int read_length = rand() % MAX_READ_LENGTH + 1;

        // Create the read
        for (int j = 0; j < read_length; j++)
        {
            reads[i][j] = (rand() % 4) + 1;
        }

        // Add a random insert
        int insert_position = rand() % read_length;
        int insert_length = rand() % 10 + 1;
        for (int j = insert_position; j < insert_position + insert_length; j++)
        {
            reads[i][j] = (rand() % 4) + 1;
        }
    }

    // Print the reads
    for (int i = 0; i < NUM_READS; i++)
    {
        printf("Read %d:\n", i + 1);
        printf("%s\n", reads[i]);
    }

    // Free the memory
    for (int i = 0; i < NUM_READS; i++)
    {
        free(reads[i]);
    }
    free(reads);

    return 0;
}