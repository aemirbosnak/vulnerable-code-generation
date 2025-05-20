//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
    char name[50];
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
    int candidateVotes[MAX_CANDIDATES];
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        candidateVotes[i] = 0;
    }

    for (Voter* v = voters; v; v = v->next)
    {
        candidateVotes[v->vote]++;
    }

    printf("Election Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate %d: %d votes\n", i + 1, candidateVotes[i]);
    }

    printf("Winner: Candidate %d\n", candidateVotes[0] + 1);
}

int main()
{
    time_t t = time(NULL);
    srand(t);

    Voter* voters = NULL;
    for (int i = 0; i < MAX_VOTES; i++)
    {
        voters = malloc(sizeof(Voter));
        strcpy(voters->name, "Voter " + i);
        voters->vote = -1;
        voters->next = voters;
    }

    vote(voters, rand() % MAX_CANDIDATES + 1);
    vote(voters, rand() % MAX_CANDIDATES + 1);
    vote(voters, rand() % MAX_CANDIDATES + 1);

    printResults(voters);

    return 0;
}