//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "sequence.txt"

int main(void) {
    int length, i, choice;
    char nucleotide;
    char *sequence = NULL;

    //get sequence length
    printf("Enter length of sequence: ");
    scanf("%d", &length);

    //allocate memory for sequence
    sequence = (char*) malloc(length * sizeof(char));

    //seed random number generator
    srand(time(NULL));

    //generate sequence
    for(i = 0; i < length; i++) {
        //randomly select nucleotide
        choice = rand() % 4;
        switch(choice) {
            case 0:
                nucleotide = 'A';
                break;
            case 1:
                nucleotide = 'C';
                break;
            case 2:
                nucleotide = 'G';
                break;
            case 3:
                nucleotide = 'T';
                break;
            default:
                nucleotide = 'X';
                break;
        }
        //add nucleotide to sequence
        sequence[i] = nucleotide;
    }

    //write sequence to file
    FILE *fp = fopen(FILENAME, "w");
    if(fp != NULL) {
        fputs(sequence, fp);
        fclose(fp);
        printf("Sequence saved to file %s\n", FILENAME);
    } else {
        printf("Error opening file for writing\n");
    }

    //free memory
    free(sequence);

    return 0;
}