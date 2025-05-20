//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5

typedef struct Voter
{
    char name[20];
    int id;
    char vote[MAX_CANDIDATES];
} Voter;

typedef struct Ballot
{
    char candidate[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];
    time_t timestamp;
} Ballot;

void initializeBallot(Ballot *ballot)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        ballot->candidate[i][0] = '\0';
        ballot->votes[i] = 0;
    }
    ballot->timestamp = time(NULL);
}

void castVote(Ballot *ballot, Voter *voter)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(voter->vote[i], ballot->candidate[i]) == 0)
        {
            ballot->votes[i]++;
            break;
        }
    }
}

void printResults(Ballot *ballot)
{
    int i;
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", ballot->candidate[i], ballot->votes[i]);
    }
}

int main()
{
    Ballot ballot;
    Voter voter;

    initializeBallot(&ballot);

    // Register voter
    strcpy(voter.name, "John Doe");
    voter.id = 123;
    strcpy(voter.vote, "Candidate A");
    castVote(&ballot, &voter);

    // Register voter
    strcpy(voter.name, "Jane Doe");
    voter.id = 456;
    strcpy(voter.vote, "Candidate B");
    castVote(&ballot, &voter);

    // Print results
    printResults(&ballot);

    return 0;
}