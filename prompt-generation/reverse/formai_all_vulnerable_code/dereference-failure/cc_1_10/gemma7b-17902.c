//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTES 100

struct Voter
{
    char name[20];
    int vote_count;
    struct Voter* next;
};

void add_voter(struct Voter** head)
{
    struct Voter* new_voter = malloc(sizeof(struct Voter));

    printf("Enter your name: ");
    scanf("%s", new_voter->name);

    new_voter->vote_count = 0;
    new_voter->next = NULL;

    if (*head == NULL)
    {
        *head = new_voter;
    }
    else
    {
        (*head)->next = new_voter;
    }
}

void vote(struct Voter* head)
{
    struct Voter* current_voter = head;

    printf("Enter your vote: ");
    int vote = atoi(stdin);

    while (current_voter)
    {
        if (strcmp(current_voter->name, stdin) == 0)
        {
            if (current_voter->vote_count < MAX_VOTES)
            {
                current_voter->vote_count++;
                printf("Your vote has been cast.\n");
            }
            else
            {
                printf("You have already voted.\n");
            }
            break;
        }
        current_voter = current_voter->next;
    }

    if (current_voter == NULL)
    {
        printf("Invalid voter.\n");
    }
}

int main()
{
    struct Voter* head = NULL;

    add_voter(&head);
    add_voter(&head);
    add_voter(&head);

    vote(head);
    vote(head);

    return 0;
}