//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[20];
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

void vote(Candidate* candidate) {
    candidate->votes++;
}

void printResults(Candidate* candidates) {
    printf("Results:\n");
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next) {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }
}

int main() {
    // Create a list of candidates
    Candidate* candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bill Smith");
    candidates = createCandidate("Mary Johnson");
    candidates = createCandidate("Bob White");

    // Simulate voting
    vote(candidates);
    vote(candidates);
    vote(candidates);
    vote(candidates);
    vote(candidates);

    // Print the results
    printResults(candidates);

    return 0;
}