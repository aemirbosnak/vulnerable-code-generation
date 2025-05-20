//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: brave
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

typedef struct Poll
{
    char candidate[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

void vote(Poll* poll, Voter* voter)
{
    int candidate_choice;

    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &candidate_choice);

    if (candidate_choice > MAX_CANDIDATES || candidate_choice <= 0)
    {
        printf("Invalid choice.\n");
        return;
    }

    voter->vote = candidate_choice;
    poll->votes[candidate_choice]++;
}

void display_results(Poll* poll)
{
    int i;

    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", poll->candidate[i], poll->votes[i]);
    }

    printf("Winner: %s\n", poll->candidate[poll->votes[0]-1]);
}

int main()
{
    Voter* head = NULL;
    Poll* head_poll = NULL;

    // Create a few voters
    Voter* voter1 = malloc(sizeof(Voter));
    strcpy(voter1->name, "John Doe");
    voter1->vote = 0;

    Voter* voter2 = malloc(sizeof(Voter));
    strcpy(voter2->name, "Jane Doe");
    voter2->vote = 1;

    Voter* voter3 = malloc(sizeof(Voter));
    strcpy(voter3->name, "Peter Pan");
    voter3->vote = 2;

    // Create a few polls
    Poll* poll1 = malloc(sizeof(Poll));
    strcpy(poll1->candidate[0], "Mr. A");
    strcpy(poll1->candidate[1], "Mr. B");
    strcpy(poll1->candidate[2], "Mr. C");
    poll1->votes[0] = 50;
    poll1->votes[1] = 20;
    poll1->votes[2] = 30;

    Poll* poll2 = malloc(sizeof(Poll));
    strcpy(poll2->candidate[0], "Mr. A");
    strcpy(poll2->candidate[1], "Mr. B");
    strcpy(poll2->candidate[2], "Mr. C");
    poll2->votes[0] = 40;
    poll2->votes[1] = 10;
    poll2->votes[2] = 50;

    // Link the voters and polls together
    head = voter1;
    head->next = voter2;
    head->next->next = voter3;

    head_poll = poll1;
    head_poll->next = poll2;

    // Vote
    vote(head_poll, head);

    // Display the results
    display_results(head_poll);

    return 0;
}