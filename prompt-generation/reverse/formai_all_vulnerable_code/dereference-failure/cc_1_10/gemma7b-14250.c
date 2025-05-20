//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

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

void printResults(Voter* voters)
{
    int candidateVotes[MAX_CANDIDATES] = {0};
    for (Voter* voter = voters; voter; voter = voter->next)
    {
        candidateVotes[voter->vote]++;
    }

    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (candidateVotes[i] > 0)
        {
            printf("Candidate %d: %d votes\n", i, candidateVotes[i]);
        }
    }
}

int main()
{
    Voter* voters = NULL;

    // Create a few voters
    Voter* voter1 = malloc(sizeof(Voter));
    strcpy(voter1->name, "Alice");
    voter1->vote = -1;
    voter1->next = voters;
    voters = voter1;

    Voter* voter2 = malloc(sizeof(Voter));
    strcpy(voter2->name, "Bob");
    voter2->vote = -1;
    voter2->next = voters;
    voters = voter2;

    // Vote
    vote(voter1, 3);
    vote(voter2, 2);

    // Print results
    printResults(voters);

    return 0;
}