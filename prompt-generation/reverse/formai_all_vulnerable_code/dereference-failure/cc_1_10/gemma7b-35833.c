//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

typedef struct Voter
{
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

Candidate* createCandidate(char* name)
{
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

Voter* createVoter(char* name, int vote)
{
    Voter* voter = malloc(sizeof(Voter));
    strcpy(voter->name, name);
    voter->vote = vote;
    voter->next = NULL;
    return voter;
}

void vote(Candidate* candidate, Voter* voter)
{
    candidate->votes++;
    voter->vote = candidate->votes;
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    Candidate* candidates = NULL;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidates = createCandidate("Candidate " + i);
        candidates->next = candidates;
    }

    Voter* voters = NULL;
    for (int i = 0; i < MAX_VOTES; i++)
    {
        voters = createVoter("Voter " + i, rand() % MAX_CANDIDATES);
        voters->next = voters;
    }

    for (Voter* voter = voters; voter; voter = voter->next)
    {
        vote(candidates, voter);
    }

    Candidate* winner = candidates;
    while (winner->votes < MAX_VOTES)
    {
        winner = winner->next;
    }

    printf("Winner: %s", winner->name);

    return 0;
}