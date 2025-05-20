//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void insertCandidate(Candidate** head)
{
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
    printf("Enter candidate name: ");
    scanf("%s", newCandidate->name);
    newCandidate->votes = 0;
    newCandidate->next = NULL;

    if (*head == NULL)
    {
        *head = newCandidate;
    }
    else
    {
        (*head)->next = newCandidate;
    }
}

void vote(Candidate** head)
{
    char voteFor[20];
    printf("Enter vote for: ");
    scanf("%s", voteFor);

    Candidate* currentCandidate = *head;
    while (currentCandidate)
    {
        if (strcmp(currentCandidate->name, voteFor) == 0)
        {
            currentCandidate->votes++;
            break;
        }
        currentCandidate = currentCandidate->next;
    }

    if (currentCandidate == NULL)
    {
        printf("Invalid vote.\n");
    }
}

int main()
{
    Candidate* head = NULL;
    insertCandidate(&head);
    insertCandidate(&head);
    insertCandidate(&head);

    vote(&head);
    vote(&head);
    vote(&head);

    printf("Results:");
    Candidate* currentCandidate = head;
    while (currentCandidate)
    {
        printf("\n%s: %d votes", currentCandidate->name, currentCandidate->votes);
        currentCandidate = currentCandidate->next;
    }

    return 0;
}