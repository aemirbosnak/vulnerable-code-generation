//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

void clearInputBuffer();

int main()
{
    char genomeSequence[MAX_LENGTH];
    int sequenceLength;

    printf("Welcome to the Genome Sequencing Simulator!\n\n");

    do {
        printf("Please enter the length of the genome sequence (between 10 and 100): ");
        scanf("%d", &sequenceLength);
        clearInputBuffer();

        if (sequenceLength < 10 || sequenceLength > 100) {
            printf("Invalid sequence length! Please try again.\n");
        }
    } while (sequenceLength < 10 || sequenceLength > 100);

    printf("\nGreat! Now please enter the genome sequence itself (only A, C, G, or T allowed):\n");

    fgets(genomeSequence, MAX_LENGTH, stdin);
    genomeSequence[strcspn(genomeSequence, "\n")] = '\0'; // remove newline from input

    printf("\nYour genome sequence is: %s\n", genomeSequence);

    printf("\nSimulating genome sequencing...\n");

    char* sequenceCopy = (char*)malloc(strlen(genomeSequence) * sizeof(char));
    strcpy(sequenceCopy, genomeSequence);

    int numErrors = sequenceLength * 0.05; // 5% chance of error
    srand(time(0)); // seed random number generator

    for (int i = 0; i < numErrors; i++) {
        int errorIndex = rand() % sequenceLength;
        char errorChar = "ACGT"[rand() % 4];

        sequenceCopy[errorIndex] = errorChar;
    }

    printf("\nSequencing complete! Here is your processed genome sequence:\n");

    printf("%s\n", sequenceCopy);

    free(sequenceCopy);

    printf("\nThank you for using the Genome Sequencing Simulator!\n");

    return 0;
}

void clearInputBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}