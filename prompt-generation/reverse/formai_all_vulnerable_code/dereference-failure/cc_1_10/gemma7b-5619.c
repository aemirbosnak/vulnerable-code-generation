//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter
{
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll
{
    char poll_name[20];
    Voter* head;
    int votes_cast;
    struct Poll* next;
} Poll;

void add_voter(Poll* poll, Voter* voter)
{
    if (poll->head == NULL)
    {
        poll->head = voter;
    }
    else
    {
        poll->head->next = voter;
        poll->head = voter;
    }
}

void cast_vote(Poll* poll, char candidate)
{
    Voter* voter = poll->head;
    while (voter)
    {
        if (strcmp(voter->name, "John Doe") == 0)
        {
            voter->vote = candidate;
            poll->votes_cast++;
            break;
        }
        voter = voter->next;
    }
}

int main()
{
    Poll* poll = malloc(sizeof(Poll));
    poll->head = NULL;
    poll->votes_cast = 0;

    Voter* voter = malloc(sizeof(Voter));
    strcpy(voter->name, "John Doe");
    voter->vote = 0;
    add_voter(poll, voter);

    voter = malloc(sizeof(Voter));
    strcpy(voter->name, "Jane Doe");
    voter->vote = 1;
    add_voter(poll, voter);

    cast_vote(poll, 'a');
    cast_vote(poll, 'b');
    cast_vote(poll, 'a');

    printf("Total votes cast: %d", poll->votes_cast);
    printf("\nCandidate votes:");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("\nCandidate %d: %d", i, poll->head->vote);
        poll->head = poll->head->next;
    }

    return 0;
}