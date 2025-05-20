//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
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
    *head = malloc(sizeof(Voter));
    (*head)->next = NULL;
    strcpy((*head)->name, "John Doe");
    (*head)->vote = 1;
}

void addPoll(Poll** head)
{
    *head = malloc(sizeof(Poll));
    (*head)->next = NULL;
    strcpy((*head)->candidate[0], "Romeo");
    strcpy((*head)->candidate[1], "Juliet");
    (*head)->votes[0] = 50;
    (*head)->votes[1] = 20;
}

void vote(Voter* head, Poll* head2)
{
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);

    for (Voter* current = head; current; current = current->next)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("Enter your vote: ");
            int vote;
            scanf("%d", &vote);

            for (Poll* current2 = head2; current2; current2 = current2->next)
            {
                for (int i = 0; i < MAX_CANDIDATES; i++)
                {
                    if (strcmp(current2->candidate[i], current->name) == 0)
                    {
                        current2->votes[i] += vote;
                    }
                }
            }

            break;
        }
    }

    printf("Thank you for voting!\n");
}

int main()
{
    Voter* head = NULL;
    addVoter(&head);

    Poll* head2 = NULL;
    addPoll(&head2);

    vote(head, head2);

    return 0;
}