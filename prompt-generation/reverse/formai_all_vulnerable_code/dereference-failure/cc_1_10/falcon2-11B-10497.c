//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_VOTES_PER_CANDIDATE 10
#define MAX_CANDIDATES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    int num_candidates;
    Candidate candidates[MAX_CANDIDATES];
} VotingSystem;

VotingSystem* createVotingSystem() {
    VotingSystem* system = (VotingSystem*)malloc(sizeof(VotingSystem));
    system->num_candidates = 0;
    return system;
}

void addCandidate(VotingSystem* system, const char* name) {
    if (system->num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strncpy(system->candidates[system->num_candidates].name, name, MAX_NAME_LENGTH);
    system->num_candidates++;
}

void vote(VotingSystem* system, int candidate_index) {
    if (candidate_index < 0 || candidate_index >= system->num_candidates) {
        printf("Error: Invalid candidate index.\n");
        return;
    }
    system->candidates[candidate_index].votes++;
}

int main() {
    VotingSystem* system = createVotingSystem();
    addCandidate(system, "Candidate 1");
    addCandidate(system, "Candidate 2");
    addCandidate(system, "Candidate 3");
    vote(system, 0);
    vote(system, 0);
    vote(system, 1);
    vote(system, 0);
    vote(system, 2);
    vote(system, 1);
    vote(system, 2);
    vote(system, 2);
    vote(system, 2);
    printf("Votes:\n");
    for (int i = 0; i < system->num_candidates; i++) {
        printf("%s: %d\n", system->candidates[i].name, system->candidates[i].votes);
    }
    free(system);
    return 0;
}