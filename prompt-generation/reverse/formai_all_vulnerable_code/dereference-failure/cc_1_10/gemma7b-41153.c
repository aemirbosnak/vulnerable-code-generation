//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Ballot
{
    char candidate[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];
    struct Ballot* next;
} Ballot;

Ballot* createBallot()
{
    Ballot* ballot = (Ballot*)malloc(sizeof(Ballot));
    ballot->next = NULL;

    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        ballot->candidate[i][0] = '\0';
        ballot->votes[i] = 0;
    }

    return ballot;
}

void addVoter(Voter* voter, Ballot* ballot)
{
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    strcpy(newVoter->name, voter->name);
    newVoter->vote = voter->vote;
    newVoter->next = NULL;

    if (ballot->next == NULL)
    {
        ballot->next = newVoter;
    }
    else
    {
        ballot->next->next = newVoter;
    }
}

void vote(char* candidate, Ballot* ballot)
{
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(candidate, ballot->candidate[i]) == 0)
        {
            ballot->votes[i]++;
            break;
        }
    }
}

int main()
{
    Ballot* ballot = createBallot();

    Voter* voter1 = (Voter*)malloc(sizeof(Voter));
    strcpy(voter1->name, "John Doe");
    voter1->vote = 1;
    addVoter(voter1, ballot);

    Voter* voter2 = (Voter*)malloc(sizeof(Voter));
    strcpy(voter2->name, "Jane Doe");
    voter2->vote = 2;
    addVoter(voter2, ballot);

    vote("Candidate B", ballot);
    vote("Candidate A", ballot);

    int totalVotes = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        totalVotes += ballot->votes[i];
    }

    printf("Total votes: %d\n", totalVotes);

    return 0;
}