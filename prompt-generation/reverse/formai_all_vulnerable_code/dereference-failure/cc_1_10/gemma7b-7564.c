//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

typedef struct Voter
{
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

Candidate* createCandidate(char* name)
{
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

Voter* createVoter(char* name)
{
    Voter* voter = (Voter*)malloc(sizeof(Voter));
    strcpy(voter->name, name);
    voter->vote = 0;
    voter->next = NULL;
    return voter;
}

void vote(Candidate* candidate, Voter* voter)
{
    candidate->votes++;
    voter->vote = candidate->votes;
}

void printResults(Candidate* candidates)
{
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    // Create a list of candidates
    Candidate* candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bill Smith");
    candidates = createCandidate("Mary Johnson");
    candidates = createCandidate("Tom Anderson");

    // Create a list of voters
    Voter* voters = createVoter("Alice White");
    voters = createVoter("Bob Green");
    voters = createVoter("Charlie Brown");
    voters = createVoter("Diana Jones");

    // Vote
    vote(candidates, voters);

    // Print the results
    printResults(candidates);

    return 0;
}