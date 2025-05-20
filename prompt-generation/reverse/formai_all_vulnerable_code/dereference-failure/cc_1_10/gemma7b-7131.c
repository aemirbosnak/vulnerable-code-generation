//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char candidate_names[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

void vote(Voter* voter, Poll* poll)
{
    int candidate_number;

    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &candidate_number);

    if (candidate_number < 0 || candidate_number >= MAX_CANDIDATES)
    {
        printf("Invalid candidate number.\n");
        return;
    }

    poll->votes[candidate_number]++;
    voter->vote = candidate_number;
}

int main()
{
    Voter* head = NULL;
    Poll* head_poll = NULL;

    // Create a few voters
    Voter* voter1 = malloc(sizeof(Voter));
    strcpy(voter1->name, "John Doe");
    voter1->vote = -1;
    voter1->next = NULL;

    Voter* voter2 = malloc(sizeof(Voter));
    strcpy(voter2->name, "Jane Doe");
    voter2->vote = -1;
    voter2->next = voter1;

    // Create a few polls
    Poll* poll1 = malloc(sizeof(Poll));
    strcpy(poll1->candidate_names[0], "Alice");
    strcpy(poll1->candidate_names[1], "Bob");
    strcpy(poll1->candidate_names[2], "Charlie");
    poll1->votes[0] = 20;
    poll1->votes[1] = 30;
    poll1->votes[2] = 10;
    poll1->next = NULL;

    Poll* poll2 = malloc(sizeof(Poll));
    strcpy(poll2->candidate_names[0], "Alice");
    strcpy(poll2->candidate_names[1], "Bob");
    strcpy(poll2->candidate_names[2], "Charlie");
    poll2->votes[0] = 10;
    poll2->votes[1] = 20;
    poll2->votes[2] = 20;
    poll2->next = poll1;

    // Add the voters and polls to the system
    head = voter1;
    head_poll = poll1;

    // Vote
    vote(voter1, head_poll);
    vote(voter2, head_poll);

    // Print the results
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", poll1->candidate_names[i], poll1->votes[i]);
    }

    return 0;
}