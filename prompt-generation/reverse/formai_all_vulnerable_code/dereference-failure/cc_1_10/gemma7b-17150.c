//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10

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

void vote(Candidate* candidate)
{
    candidate->votes++;
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    Candidate* candidates = NULL;
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bob Smith");
    candidates = createCandidate("Alice White");

    int numVotes = rand() % 100;
    for (int i = 0; i < numVotes; i++)
    {
        vote(candidates);
    }

    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s has received %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}