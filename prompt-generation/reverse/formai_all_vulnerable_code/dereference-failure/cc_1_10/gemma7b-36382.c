//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
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

void insertVoter(Voter** head)
{
    Voter* newVoter = malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
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

void vote(Voter* head, int candidate)
{
    while (head)
    {
        if (strcmp(head->name, "John Doe") == 0)
        {
            head->vote = candidate;
            break;
        }
        head = head->next;
    }
}

int main()
{
    Voter* head = NULL;
    insertVoter(&head);
    insertVoter(&head);
    insertVoter(&head);

    vote(head, 2);
    vote(head, 1);
    vote(head, 3);

    int results[MAX_CANDIDATES];
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        results[i] = 0;
    }

    for (Voter* voter = head; voter; voter)
    {
        results[voter->vote]++;
    }

    printf("Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Candidate %d: %d votes\n", i + 1, results[i]);
    }

    return 0;
}