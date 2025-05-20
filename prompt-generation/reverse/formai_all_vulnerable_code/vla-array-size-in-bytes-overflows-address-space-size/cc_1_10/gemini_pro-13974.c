//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[256];
    int votes;
} Candidate;

int main() {
    int numCandidates, numVoters;

    // Read the number of candidates and voters
    scanf("%d %d", &numCandidates, &numVoters);

    // Create an array of candidates
    Candidate candidates[numCandidates];

    // Read the names of the candidates
    for (int i = 0; i < numCandidates; i++) {
        scanf("%s", candidates[i].name);
    }

    // Create a matrix to store the votes
    int votes[numCandidates][numVoters];

    // Read the votes
    for (int i = 0; i < numVoters; i++) {
        for (int j = 0; j < numCandidates; j++) {
            scanf("%d", &votes[j][i]);
        }
    }

    // Calculate the total number of votes for each candidate
    int totalVotes[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        totalVotes[i] = 0;
        for (int j = 0; j < numVoters; j++) {
            totalVotes[i] += votes[i][j];
        }
    }

    // Find the winner
    int winnerIndex = -1;
    int maxVotes = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (totalVotes[i] > maxVotes) {
            winnerIndex = i;
            maxVotes = totalVotes[i];
        }
    }

    // Print the winner
    printf("%s\n", candidates[winnerIndex].name);

    return 0;
}