//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sequenceLength = 50; // length of the genome sequence
    char nucleotides[4] = {'A', 'T', 'G', 'C'}; // possible nucleotides
    
    srand(time(NULL)); // initialize random number generator
    
    // create empty genome sequence
    char *genome = NULL;
    genome = malloc(sequenceLength * sizeof(char));
    
    // generate random nucleotides and add them to genome sequence
    for(int i=0; i<sequenceLength; i++) {
        int randIndex = rand() % 4;
        genome[i] = nucleotides[randIndex];
    }
    
    // print out the genome sequence
    printf("The genome sequence is:\n");
    for(int i=0; i<sequenceLength; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // analyze the genome sequence
    int countA = 0;
    int countT = 0;
    int countG = 0;
    int countC = 0;
    
    for(int i=0; i<sequenceLength; i++) {
        if(genome[i] == 'A') {
            countA++;
        }
        else if(genome[i] == 'T') {
            countT++;
        }
        else if(genome[i] == 'G') {
            countG++;
        }
        else if(genome[i] == 'C') {
            countC++;
        }
    }
    
    // print out the analysis
    printf("The genome sequence has %d A nucleotides, %d T nucleotides, %d G nucleotides, and %d C nucleotides.\n", countA, countT, countG, countC);
    
    // free the memory allocated for the genome sequence
    free(genome);
    
    return 0;
}