//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define MAX_VOTES 1000

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate* candidate)
{
    candidate->votes++;
}

Candidate* createCandidate(char* name)
{
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

int main()
{
    time_t t;
    srand(time(&t));

    Candidate* candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Peter Pan");
    candidates = createCandidate("Captain Hook");
    candidates = createCandidate("The Evil Witch");

    int votes = rand() % MAX_VOTES;
    for (int i = 0; i < votes; i++)
    {
        vote(candidates);
    }

    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s has received %d votes.\n", candidate->name, candidate->votes);
    }

    return 0;
}