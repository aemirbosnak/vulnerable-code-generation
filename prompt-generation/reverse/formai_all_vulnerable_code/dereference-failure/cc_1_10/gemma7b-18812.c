//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name) {
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

void addVote(Candidate* candidate) {
    candidate->votes++;
}

int main() {
    Candidate** candidates = (Candidate**)malloc(MAX_CANDIDATES * sizeof(Candidate*));
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i] = NULL;
    }

    // Register candidates
    candidates[0] = createCandidate("John Doe");
    candidates[1] = createCandidate("Jane Doe");
    candidates[2] = createCandidate("Bill Smith");
    candidates[3] = createCandidate("Mary Johnson");
    candidates[4] = createCandidate("Tom Brown");

    // Vote for candidates
    addVote(candidates[0]);
    addVote(candidates[1]);
    addVote(candidates[2]);
    addVote(candidates[3]);
    addVote(candidates[4]);

    // Print results
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i]->name, candidates[i]->votes);
    }

    return 0;
}