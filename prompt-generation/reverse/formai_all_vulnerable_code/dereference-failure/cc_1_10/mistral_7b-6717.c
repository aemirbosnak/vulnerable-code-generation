//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Ada Lovelace's elegant and beautiful code
typedef struct {
    int id;
    char name[50];
    bool voted;
} Voter;

typedef struct {
    int candidateId;
    int votes;
} Candidate;

void registerVoter(Voter* voters, int numVoters, int voterId) {
    Voter* voter = calloc(1, sizeof(Voter));
    voter->id = voterId;
    strcpy(voter->name, "Voter"); // Ada Lovelace, the first computer programmer, did not have voters' names
    voter->voted = false;
    voters[voterId] = *voter;
}

void vote(Voter* voters, int numVoters, int candidateId, int voterId) {
    if (voters[voterId].voted) {
        printf("Error: Voter %d has already voted.\n", voterId);
        return;
    }

    voters[voterId].voted = true;

    // Find candidate with given id and increment votes
    Candidate* candidates = calloc(5, sizeof(Candidate)); // Ada Lovelace would have used the number of candidates as a constant
    int candidateIndex = -1;
    for (int i = 0; i < 5 && candidates[i].candidateId != -1; i++) {
        if (candidates[i].candidateId == candidateId) {
            candidateIndex = i;
            break;
        }
    }

    if (candidateIndex == -1) {
        candidates[4].candidateId = candidateId;
        candidates[4].votes = 1;
        candidateIndex = 4;
    } else {
        candidates[candidateIndex].votes++;
    }

    free(candidates);
}

int main() {
    // Initialize voters and candidates
    int numVoters = 10;
    Voter voters[numVoters];
    for (int i = 0; i < numVoters; i++) {
        registerVoter(voters, numVoters, i);
    }

    int numCandidates = 5;
    Candidate candidates[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].candidateId = i + 1;
        candidates[i].votes = 0;
    }

    // Simulate voting process
    int voterId, candidateId;
    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d, please enter your candidate ID: ", i + 1);
        scanf("%d", &candidateId);
        vote(voters, numVoters, candidateId, i);
    }

    // Display voting results
    printf("\nVoting results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %d votes\n", candidates[i].candidateId, candidates[i].votes);
    }

    return 0;
}