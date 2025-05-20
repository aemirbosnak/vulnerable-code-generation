//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name)
{
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

void vote(Candidate* candidate)
{
    candidate->votes++;
}

int main()
{
    Candidate* candidates = NULL;
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Peter Pan");
    candidates = createCandidate("Mary Poppins");
    candidates = createCandidate("Captain Hook");

    // Voting process
    vote(candidates->next);
    vote(candidates);
    vote(candidates->next->next);

    // Printing results
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}