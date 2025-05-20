//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Voter
{
    char name[20];
    int vote;
} Voter;

void vote(Voter **v, int candidate)
{
    (*v)->vote = candidate;
}

int main()
{
    Voter **v = malloc(10 * sizeof(Voter));
    for (int i = 0; i < 10; i++)
    {
        v[i] = malloc(sizeof(Voter));
        strcpy(v[i]->name, "Voter");
        v[i]->vote = -1;
    }

    int candidates[] = {1, 2, 3, 4, 5};
    int numCandidates = sizeof(candidates) / sizeof(int);

    for (int i = 0; i < 10; i++)
    {
        printf("Voter %s, please vote for a candidate:", v[i]->name);
        for (int j = 0; j < numCandidates; j++)
        {
            printf(" %d", candidates[j]);
        }
        printf("\n");

        int candidateVote;
        scanf("%d", &candidateVote);

        vote(v, candidateVote);
    }

    int winner = -1;
    for (int i = 0; i < 10; i++)
    {
        if (v[i]->vote != -1)
        {
            winner = v[i]->vote;
        }
    }

    printf("The winner is candidate %d!", winner);

    return 0;
}