//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sherlock's deductive reasoning engine
int deduce(int *clues, int numClues) {
    int i, j, suspect;
    int frequency[numClues];

    // Initialize frequency table
    for (i = 0; i < numClues; i++) {
        frequency[i] = 0;
    }

    // Count occurrences of each clue
    for (i = 0; i < numClues; i++) {
        frequency[clues[i]]++;
    }

    // Find the clue that appears most frequently
    suspect = 0;
    for (i = 1; i < numClues; i++) {
        if (frequency[i] > frequency[suspect]) {
            suspect = i;
        }
    }

    return suspect;
}

int main(void) {
    int numSuspects, numClues;
    int clues[100];
    int i, suspect;

    // Set random seed
    srand(time(NULL));

    // Get number of suspects and clues
    printf("Enter the number of suspects: ");
    scanf("%d", &numSuspects);
    printf("Enter the number of clues: ");
    scanf("%d", &numClues);

    // Generate random clues
    for (i = 0; i < numClues; i++) {
        clues[i] = rand() % numSuspects;
    }

    // Print clues
    printf("Clues:\n");
    for (i = 0; i < numClues; i++) {
        printf("%d ", clues[i]);
    }
    printf("\n");

    // Deduce the suspect
    suspect = deduce(clues, numClues);

    // Print the suspect
    printf("The suspect is: %d\n", suspect);

    return 0;
}