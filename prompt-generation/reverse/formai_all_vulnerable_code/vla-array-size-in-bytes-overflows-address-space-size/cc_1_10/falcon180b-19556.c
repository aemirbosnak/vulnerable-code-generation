//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voterID;
} Voter;

int main() {
    int numCandidates, numVoters;
    char input[100];

    // Get number of candidates
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);

    // Get candidate names
    Candidate candidates[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    // Get number of voters
    printf("Enter number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &numVoters);

    // Get voter names and IDs
    Voter voters[numVoters];
    for (int i = 0; i < numVoters; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter voter ID of voter %s: ", voters[i].name);
        scanf("%d", &voters[i].voterID);
    }

    // Print ballot
    printf("\nBallot:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }

    // Cast votes
    for (int i = 0; i < numVoters; i++) {
        int choice;
        printf("\n%s, please cast your vote:\n", voters[i].name);
        for (int j = 0; j < numCandidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        scanf("%d", &choice);
        candidates[choice-1].votes++;
    }

    // Print results
    printf("\nResults:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}