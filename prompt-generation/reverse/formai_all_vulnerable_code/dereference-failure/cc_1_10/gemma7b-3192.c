//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5
#define NUM_VOTES 100

typedef struct Voter
{
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

void vote(Voter* voter, int candidate)
{
    if (voter->vote == -1)
    {
        voter->vote = candidate;
    }
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    Voter* head = NULL;
    for (int i = 0; i < NUM_VOTES; i++)
    {
        Voter* newVoter = malloc(sizeof(Voter));
        newVoter->name[0] = 'A' + i;
        newVoter->vote = -1;
        newVoter->next = head;
        head = newVoter;
    }

    int candidates[NUM_CANDIDATES] = {0, 0, 0, 0, 0};
    for (int i = 0; i < NUM_VOTES; i++)
    {
        vote(head, rand() % NUM_CANDIDATES);
        candidates[rand() % NUM_CANDIDATES]++;
    }

    printf("Results:");
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf(" Candidate %d: %d votes\n", i + 1, candidates[i]);
    }

    return 0;
}