//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 5

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name)
{
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
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

    // Create a list of candidates
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bob Smith");
    candidates = createCandidate("Mary Johnson");
    candidates = createCandidate("Peter Parker");

    // Simulate some votes
    addVote(candidates->next);
    addVote(candidates->next->next);
    addVote(candidates->next->next->next);

    // Print the results
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s has %d votes.\n", candidate->name, candidate->votes);
    }

    return 0;
}