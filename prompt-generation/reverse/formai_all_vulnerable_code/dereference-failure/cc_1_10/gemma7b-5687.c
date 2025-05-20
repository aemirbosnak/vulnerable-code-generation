//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: authentic
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

typedef struct Ballot
{
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    struct Ballot* next;
} Ballot;

Voter* createVoter(char* name, int vote)
{
    Voter* voter = (Voter*)malloc(sizeof(Voter));
    strcpy(voter->name, name);
    voter->vote = vote;
    voter->next = NULL;
    return voter;
}

Ballot* createBallot()
{
    Ballot* ballot = (Ballot*)malloc(sizeof(Ballot));
    ballot->next = NULL;
    return ballot;
}

void addVoter(Ballot* ballot, Voter* voter)
{
    ballot->votes[voter->vote]++;
    ballot->candidate[voter->vote][0] = voter->name[0];
    ballot->candidate[voter->vote][1] = voter->name[1];
    ballot->candidate[voter->vote][2] = '\0';
    voter->next = ballot->next;
    ballot->next = voter;
}

int main()
{
    Ballot* ballot = createBallot();
    Voter* voter = createVoter("John Doe", 1);
    addVoter(ballot, voter);
    voter = createVoter("Jane Doe", 2);
    addVoter(ballot, voter);
    voter = createVoter("Peter Pan", 3);
    addVoter(ballot, voter);
    voter = createVoter("Mary Poppins", 4);
    addVoter(ballot, voter);
    voter = createVoter("Jack Sparrow", 5);
    addVoter(ballot, voter);

    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate: %s, Votes: %d\n", ballot->candidate[i][0] - 'a' + ballot->candidate[i][1] - 'a', ballot->votes[i]);
    }

    return 0;
}