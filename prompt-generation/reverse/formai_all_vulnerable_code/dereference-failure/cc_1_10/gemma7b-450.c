//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Voter
{
    char name[50];
    int vote_count;
    struct Voter* next;
} Voter;

typedef struct Poll
{
    char poll_name[50];
    Voter* head;
    struct Poll* next;
} Poll;

void vote(Poll* poll, char* candidate)
{
    Voter* voter = poll->head;
    while (voter)
    {
        if (strcmp(voter->name, candidate) == 0)
        {
            voter->vote_count++;
            return;
        }
        voter = voter->next;
    }

    // Candidate not found, add new voter
    voter = (Voter*)malloc(sizeof(Voter));
    strcpy(voter->name, candidate);
    voter->vote_count = 1;
    voter->next = NULL;

    poll->head = voter;
}

int main()
{
    Poll* polls = NULL;

    // Create a new poll
    polls = (Poll*)malloc(sizeof(Poll));
    strcpy(polls->poll_name, "The Last Election");
    polls->head = NULL;

    // Vote
    vote(polls, "John Doe");
    vote(polls, "Jane Doe");
    vote(polls, "John Doe");

    // Print results
    Voter* voter = polls->head;
    while (voter)
    {
        printf("%s has %d votes\n", voter->name, voter->vote_count);
        voter = voter->next;
    }

    return 0;
}