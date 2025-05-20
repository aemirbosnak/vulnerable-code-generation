//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100

typedef struct Voter
{
    char name[50];
    int vote_count;
    struct Voter* next;
} Voter;

void add_voter(Voter** head, char* name)
{
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
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

void vote(Voter* voter, int vote_choice)
{
    if (voter->vote_count < MAX_VOTERS)
    {
        voter->vote_count++;
        switch (vote_choice)
        {
            case 1:
                printf("You have voted for candidate 1.\n");
                break;
            case 2:
                printf("You have voted for candidate 2.\n");
                break;
            case 3:
                printf("You have voted for candidate 3.\n");
                break;
            default:
                printf("Invalid vote choice.\n");
                break;
        }
    }
    else
    {
        printf("You have already voted.\n");
    }
}

void display_results(Voter* head)
{
    printf("Election Results:\n");
    int total_votes = 0;
    for (Voter* voter = head; voter; voter = voter->next)
    {
        printf("%s: %d votes\n", voter->name, voter->vote_count);
        total_votes += voter->vote_count;
    }
    printf("Total Votes: %d\n", total_votes);
}

int main()
{
    Voter* head = NULL;

    // Add voters
    add_voter(&head, "John Doe");
    add_voter(&head, "Jane Doe");
    add_voter(&head, "Bill Smith");

    // Vote
    vote(head, 2);
    vote(head, 1);
    vote(head, 3);

    // Display results
    display_results(head);

    return 0;
}