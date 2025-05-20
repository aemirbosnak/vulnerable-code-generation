//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct Voter
{
    char name[50];
    char vote[MAX_CANDIDATES];
    int weight;
} Voter;

typedef struct Poll
{
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    int totalVotes;
} Poll;

void initializePoll(Poll *poll)
{
    int i;

    poll->totalVotes = 0;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        poll->candidate[i][0] = '\0';
        poll->votes[i] = 0;
    }
}

void addVoter(Voter *voter, Poll *poll)
{
    int i;

    printf("Enter voter name: ");
    scanf("%s", voter->name);

    printf("Enter voter weight: ");
    scanf("%d", &voter->weight);

    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Enter voter vote for candidate %d: ", i + 1);
        scanf("%s", voter->vote[i]);
    }

    poll->totalVotes++;
}

void vote(Voter *voter, Poll *poll)
{
    int i;

    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(voter->vote[i], voter->name) == 0)
        {
            poll->votes[i]++;
            break;
        }
    }
}

void displayResults(Poll *poll)
{
    int i;

    printf("Election Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate: %s, Votes: %d\n", poll->candidate[i], poll->votes[i]);
    }

    printf("Total Votes: %d\n", poll->totalVotes);
}

int main()
{
    Voter voter;
    Poll poll;

    initializePoll(&poll);

    addVoter(&voter, &poll);
    addVoter(&voter, &poll);
    addVoter(&voter, &poll);

    vote(&voter, &poll);
    vote(&voter, &poll);

    displayResults(&poll);

    return 0;
}