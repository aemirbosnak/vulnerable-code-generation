//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name)
{
    Candidate* newCandidate = malloc(sizeof(Candidate));
    strcpy(newCandidate->name, name);
    newCandidate->votes = 0;
    newCandidate->next = NULL;
    return newCandidate;
}

void addVote(Candidate* candidate)
{
    candidate->votes++;
}

int main()
{
    Candidate* candidates = NULL;

    // Create candidates
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bill Smith");
    candidates = createCandidate("Mary Johnson");
    candidates = createCandidate("Tom Anderson");

    // Vote for candidates
    addVote(candidates->next);
    addVote(candidates->next->next);
    addVote(candidates);

    // Print results
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}