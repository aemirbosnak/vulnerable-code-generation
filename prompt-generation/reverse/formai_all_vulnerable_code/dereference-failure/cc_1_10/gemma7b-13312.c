//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void addVoter(Voter** head)
{
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    scanf("Enter your name: ", newVoter->name);
    newVoter->vote = 0;
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

void addPoll(Poll** head)
{
    Poll* newPoll = (Poll*)malloc(sizeof(Poll));
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        scanf("Enter candidate name: ", newPoll->candidate[i]);
    }

    newPoll->votes[0] = 0;
    newPoll->next = NULL;

    if (*head == NULL)
    {
        *head = newPoll;
    }
    else
    {
        (*head)->next = newPoll;
    }
}

int main()
{
    Voter* head = NULL;
    Poll* pollHead = NULL;

    addVoter(&head);
    addVoter(&head);
    addVoter(&head);

    addPoll(&pollHead);
    addPoll(&pollHead);

    for (Voter* voter = head; voter; voter = voter->next)
    {
        printf("Voter name: %s, Vote: %d\n", voter->name, voter->vote);
    }

    for (Poll* poll = pollHead; poll; poll = poll->next)
    {
        for (int i = 0; i < MAX_CANDIDATES; i++)
        {
            printf("Candidate name: %s, Votes: %d\n", poll->candidate[i], poll->votes[i]);
        }
    }

    return 0;
}