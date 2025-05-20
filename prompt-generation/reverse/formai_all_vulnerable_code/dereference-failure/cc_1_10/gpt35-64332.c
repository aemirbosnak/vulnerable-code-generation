//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define GENOME_LENGTH 8192

// Function to generate random DNA string of given length
char* generateRandomDNAString(int length){

    // Initialize a string of length+1 to store the random DNA string, the "+1" is for the null character '\0'
    char* dnaString = malloc((length+1) * sizeof(char));
    
    // Set the random seed
    srand(time(NULL));

    // Generate random DNA string by appending random characters chosen from [A,C,T,G]
    for(int i=0; i<length; i++){
        switch(rand()%4){
            case 0: dnaString[i] = 'A'; break;
            case 1: dnaString[i] = 'C'; break;
            case 2: dnaString[i] = 'T'; break;
            case 3: dnaString[i] = 'G'; break;
        }
    }

    // Add the null character at the end
    dnaString[length] = '\0';

    // Return the random DNA string
    return dnaString;
}

// Function to simulate genome sequencing
void simulateGenomeSequencing(char* genome){

    int genomeLen = strlen(genome);

    // Divide the genome into random chunks of length 200-300 each
    int chunkSize, chunkStart, chunkEnd;
    int maxChunkSize = 300;
    int minChunkSize = 200;
    int chunkCount = 0;
    char* chunkString;

    while(genomeLen > 0){
        chunkSize = rand() % (maxChunkSize - minChunkSize + 1) + minChunkSize;
        chunkStart = chunkCount*chunkSize;
        chunkEnd = chunkStart + chunkSize - 1;
        if(chunkEnd >= genomeLen) chunkEnd = genomeLen-1;

        chunkString = malloc((chunkSize+1) * sizeof(char));
        strncpy(chunkString, genome+chunkStart, chunkSize);
        chunkString[chunkSize] = '\0';

        printf("Chunk %d: %s\n", chunkCount+1, chunkString);

        free(chunkString);

        genomeLen -= chunkSize;
        chunkCount++;
    }
}

int main(){

    // Generate a random genome
    char* genome = generateRandomDNAString(GENOME_LENGTH);

    // Simulate genome sequencing
    simulateGenomeSequencing(genome);

    // Free memory
    free(genome);

    return 0;
}