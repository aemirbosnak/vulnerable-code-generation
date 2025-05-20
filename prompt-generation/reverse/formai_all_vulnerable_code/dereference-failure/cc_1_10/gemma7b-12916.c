//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insertVoter(Voter** head, char* name, int vote)
{
    Voter* newVoter = malloc(sizeof(Voter));
    strcpy(newVoter->name, name);
    newVoter->vote = vote;
    newVoter->next = NULL;

    if (*head == NULL)
    {
        *head = newVoter;
    }
    else
    {
        (*head)->next = newVoter;
    }
}

void insertBallot(Ballot** head, char* candidate, int votes)
{
    Ballot* newBallot = malloc(sizeof(Ballot));
    strcpy(newBallot->candidate[0], candidate);
    newBallot->votes[0] = votes;
    newBallot->next = NULL;

    if (*head == NULL)
    {
        *head = newBallot;
    }
    else
    {
        (*head)->next = newBallot;
    }
}

int main()
{
    Voter* head = NULL;
    Ballot* ballotHead = NULL;

    insertVoter(&head, "John Doe", 10);
    insertVoter(&head, "Jane Doe", 12);
    insertVoter(&head, "Peter Pan", 8);

    insertBallot(&ballotHead, "Mr. A", 50);
    insertBallot(&ballotHead, "Ms. B", 30);
    insertBallot(&ballotHead, "Mr. C", 20);

    int totalVotes = 0;
    for (Ballot* ballot = ballotHead; ballot; ballot = ballot->next)
    {
        totalVotes += ballot->votes[0];
    }

    printf("Total votes: %d\n", totalVotes);

    return 0;
}