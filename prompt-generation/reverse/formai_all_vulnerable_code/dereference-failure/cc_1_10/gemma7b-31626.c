//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate) == 0) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    int i;
    char vote_choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Get candidate vote
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", &vote_choice);

    // Validate vote
    if (strlen(vote_choice) > 20) {
        printf("Error: invalid candidate name.\n");
    } else {
        vote(vote_choice);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}