//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
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

typedef struct Poll
{
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

void vote(Voter* voter, Poll* poll)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        if (strcmp(voter->name, poll->candidate[i]) == 0)
        {
            poll->votes[i]++;
            break;
        }
    }
}

void displayResults(Poll* poll)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s received %d votes.\n", poll->candidate[i], poll->votes[i]);
    }
}

int main()
{
    Voter* head = NULL;
    Poll* headPoll = NULL;

    // Add some voters
    Voter* voter1 = malloc(sizeof(Voter));
    strcpy(voter1->name, "John Doe");
    voter1->vote = 1;
    voter1->next = NULL;

    Voter* voter2 = malloc(sizeof(Voter));
    strcpy(voter2->name, "Jane Doe");
    voter2->vote = 2;
    voter2->next = NULL;

    Voter* voter3 = malloc(sizeof(Voter));
    strcpy(voter3->name, "Peter Pan");
    voter3->vote = 3;
    voter3->next = NULL;

    // Add some polls
    Poll* poll1 = malloc(sizeof(Poll));
    strcpy(poll1->candidate[0], "John Doe");
    strcpy(poll1->candidate[1], "Jane Doe");
    strcpy(poll1->candidate[2], "Peter Pan");
    poll1->votes[0] = 50;
    poll1->votes[1] = 25;
    poll1->votes[2] = 10;
    poll1->next = NULL;

    Poll* poll2 = malloc(sizeof(Poll));
    strcpy(poll2->candidate[0], "John Doe");
    strcpy(poll2->candidate[1], "Jane Doe");
    strcpy(poll2->candidate[2], "Peter Pan");
    poll2->votes[0] = 20;
    poll2->votes[1] = 15;
    poll2->votes[2] = 5;
    poll2->next = NULL;

    // Link voters and polls
    head = voter1;
    headPoll = poll1;

    // Vote
    vote(voter2, headPoll);

    // Display results
    displayResults(headPoll);

    return 0;
}