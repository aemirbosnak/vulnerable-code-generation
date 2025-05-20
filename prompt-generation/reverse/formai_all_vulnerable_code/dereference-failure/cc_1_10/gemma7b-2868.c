//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
} Voter;

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void initializeVoters(Voter **voters, int numVoters) {
    *voters = malloc(numVoters * sizeof(Voter));
    for (int i = 0; i < numVoters; i++) {
        (*voters)[i].name[0] = '\0';
        (*voters)[i].vote = 0;
    }
}

void initializeCandidates(Candidate **candidates, int numCandidates) {
    *candidates = malloc(numCandidates * sizeof(Candidate));
    for (int i = 0; i < numCandidates; i++) {
        (*candidates)[i].name[0] = '\0';
        (*candidates)[i].votes = 0;
    }
}

void vote(Voter **voters, int numVoters, Candidate **candidates, int numCandidates) {
    for (int i = 0; i < numVoters; i++) {
        printf("Enter your name: ");
        scanf("%s", (*voters)[i].name);

        printf("Enter your vote for: ");
        scanf("%d", &((*voters)[i].vote));

        for (int j = 0; j < numCandidates; j++) {
            if ((*voters)[i].vote == (*candidates)[j].votes) {
                (*candidates)[j].votes++;
            }
        }
    }
}

void printResults(Candidate **candidates, int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("%s has received %d votes.\n", (*candidates)[i].name, (*candidates)[i].votes);
    }
}

int main() {
    Voter **voters = NULL;
    Candidate **candidates = NULL;

    int numVoters = 10;
    int numCandidates = 3;

    initializeVoters(&voters, numVoters);
    initializeCandidates(&candidates, numCandidates);

    vote(voters, numVoters, candidates, numCandidates);

    printResults(candidates, numCandidates);

    return 0;
}