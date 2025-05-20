//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complex
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

void addVoter(Voter** head)
{
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    printf("Enter your name: ");
    scanf("%s", newVoter->name);
    printf("Enter your vote: ");
    scanf("%d", &newVoter->vote);
    *head = newVoter;
}

void addPoll(Poll** head)
{
    Poll* newPoll = (Poll*)malloc(sizeof(Poll));
    printf("Enter the candidate's name: ");
    scanf("%s", newPoll->candidate[0]);
    printf("Enter the candidate's votes: ");
    scanf("%d", &newPoll->votes[0]);
    *head = newPoll;
}

void vote(Voter* head, Poll* head2)
{
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);
    Voter* currentVoter = head;
    while (currentVoter)
    {
        if (strcmp(currentVoter->name, name) == 0)
        {
            printf("Your vote has been cast for: ");
            int voteCast = currentVoter->vote;
            for (int i = 0; i < voteCast; i++)
            {
                printf("%s ", head2->candidate[i]);
            }
            break;
        }
        currentVoter = currentVoter->next;
    }
    if (currentVoter == NULL)
    {
        printf("No voter found with that name.\n");
    }
}

int main()
{
    Voter* head = NULL;
    addVoter(&head);
    addVoter(&head);
    addVoter(&head);

    Poll* head2 = NULL;
    addPoll(&head2);
    addPoll(&head2);
    addPoll(&head2);

    vote(head, head2);
    return 0;
}