//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

struct Candidate {
    char* name;
    int votes;
};

struct Voter {
    char* name;
    int candidate;
};

struct Election {
    struct Candidate candidates[NUM_CANDIDATES];
    int numCandidates;
};

struct Election* createElection(void) {
    struct Election* election = malloc(sizeof(struct Election));
    election->numCandidates = NUM_CANDIDATES;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        election->candidates[i].name = (char*)malloc(sizeof(char) * 20);
        election->candidates[i].votes = 0;
    }
    return election;
}

void printElection(struct Election* election) {
    for (int i = 0; i < election->numCandidates; i++) {
        printf("%s: %d\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

int main(void) {
    struct Election* election = createElection();
    for (int i = 0; i < NUM_VOTERS; i++) {
        struct Voter voter;
        voter.name = (char*)malloc(sizeof(char) * 20);
        voter.candidate = (int)rand() % NUM_CANDIDATES;
        strcpy(voter.name, "Voter ");
        sprintf(voter.name + 5, "%d", i + 1);
        election->candidates[voter.candidate].votes++;
    }
    printElection(election);
    return 0;
}