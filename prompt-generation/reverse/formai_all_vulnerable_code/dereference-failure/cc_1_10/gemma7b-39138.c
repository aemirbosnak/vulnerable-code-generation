//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name) {
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

void addVote(Candidate* candidate) {
    candidate->votes++;
}

int main() {
    Candidate* candidates = NULL;

    // Create candidates
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bill Smith");
    candidates = createCandidate("Mary Jones");
    candidates = createCandidate("Bob White");

    // Simulate voting
    addVote(candidates);
    addVote(candidates);
    addVote(candidates);
    addVote(candidates);
    addVote(candidates);
    addVote(candidates);
    addVote(candidates);

    // Print results
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next) {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}