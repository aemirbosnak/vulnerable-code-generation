//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the candidate structure
typedef struct candidate {
    char name[20];
    int votes;
} candidate;

// Function to add a candidate
void addCandidate(candidate **candidates, int *numCandidates) {
    *candidates = malloc((*numCandidates) * sizeof(candidate));
    (*numCandidates)++;
}

// Function to vote for a candidate
void voteForCandidate(candidate *candidates, int numCandidates, char *voterName) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, voterName) == 0) {
            candidates[i].votes++;
            break;
        }
    }
}

// Function to display the results
void displayResults(candidate *candidates, int numCandidates) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("%s has received %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Create an array of candidates
    candidate *candidates = NULL;
    int numCandidates = 0;

    // Add some candidates
    addCandidate(&candidates, &numCandidates);
    strcpy(candidates[0].name, "John Doe");
    candidates[0].votes = 100;

    addCandidate(&candidates, &numCandidates);
    strcpy(candidates[1].name, "Jane Doe");
    candidates[1].votes = 50;

    addCandidate(&candidates, &numCandidates);
    strcpy(candidates[2].name, "Bill Smith");
    candidates[2].votes = 25;

    // Vote for a candidate
    voteForCandidate(candidates, numCandidates, "John Doe");

    // Vote for a candidate
    voteForCandidate(candidates, numCandidates, "Jane Doe");

    // Display the results
    displayResults(candidates, numCandidates);

    return 0;
}