//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

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

void addVote(Candidate* candidate)
{
    candidate->votes++;
}

int main()
{
    Candidate* candidates = NULL;
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bob Smith");
    candidates = createCandidate("Alice White");
    candidates = createCandidate("Tom Green");

    // Voting
    addVote(candidates->next);
    addVote(candidates);
    addVote(candidates->next->next);

    // Results
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s has %d votes.\n", candidate->name, candidate->votes);
    }

    return 0;
}