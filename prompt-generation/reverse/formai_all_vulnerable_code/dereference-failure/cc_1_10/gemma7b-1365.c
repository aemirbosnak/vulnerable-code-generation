//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
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

Candidate* createCandidate(char* name)
{
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
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
    candidates = createCandidate("Peter Pan");
    candidates = createCandidate("Mary Poppins");
    candidates = createCandidate("Captain America");

    int votes = 0;
    for (int i = 0; i < MAX_VOTES; i++)
    {
        votes++;
        addVote(candidates);
    }

    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s has received %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}