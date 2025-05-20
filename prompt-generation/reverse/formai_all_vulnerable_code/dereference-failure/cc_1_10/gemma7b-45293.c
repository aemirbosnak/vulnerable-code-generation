//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
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

void insertVoter(Voter** head)
{
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
    newVoter->vote = -1;
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

void insertBallot(Ballot** head)
{
    Ballot* newBallot = (Ballot*)malloc(sizeof(Ballot));
    printf("Enter the name of candidate 1: ");
    scanf("%s", newBallot->candidate[0]);
    printf("Enter the number of votes for candidate 1: ");
    scanf("%d", &newBallot->votes[0]);

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

void vote(Voter* head, Ballot* headB)
{
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    Voter* currentVoter = head;
    Ballot* currentBallot = headB;

    while (currentVoter && strcmp(currentVoter->name, name) != 0)
    {
        currentVoter = currentVoter->next;
    }

    while (currentBallot && strcmp(currentBallot->candidate[0], name) != 0)
    {
        currentBallot = currentBallot->next;
    }

    if (currentVoter && currentBallot)
    {
        currentVoter->vote = currentBallot->votes[0];
    }
}

int main()
{
    Voter* headV = NULL;
    Ballot* headB = NULL;

    insertVoter(&headV);
    insertVoter(&headV);
    insertBallot(&headB);
    insertBallot(&headB);
    insertBallot(&headB);

    vote(headV, headB);

    printf("Results:");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate %d: %d votes", i, headB->votes[i]);
    }

    return 0;
}