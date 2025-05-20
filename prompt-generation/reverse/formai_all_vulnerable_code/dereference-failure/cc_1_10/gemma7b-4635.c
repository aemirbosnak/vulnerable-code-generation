//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10

typedef struct Voter
{
    char name[50];
    int vote_id;
    struct Voter* next;
} Voter;

typedef struct Ballot
{
    char candidate_name[50];
    int votes;
    struct Ballot* next;
} Ballot;

void vote(Voter*, Ballot*);

int main()
{
    Voter* head = NULL;
    Ballot* ballot_head = NULL;

    // Register voters
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, "John Doe");
    new_voter->vote_id = 1;
    new_voter->next = NULL;
    head = new_voter;

    // Create ballots
    Ballot* new_ballot = malloc(sizeof(Ballot));
    strcpy(new_ballot->candidate_name, "Alice Smith");
    new_ballot->votes = 0;
    new_ballot->next = NULL;
    ballot_head = new_ballot;

    // Vote
    vote(head, ballot_head);

    // Print results
    Ballot* current_ballot = ballot_head;
    while (current_ballot)
    {
        printf("%s has received %d votes\n", current_ballot->candidate_name, current_ballot->votes);
        current_ballot = current_ballot->next;
    }

    return 0;
}

void vote(Voter* voter, Ballot* ballot_head)
{
    // Prompt voter to choose a candidate
    char candidate_name[50];
    printf("Please choose a candidate: ");
    scanf("%s", candidate_name);

    // Search for the candidate
    Ballot* current_ballot = ballot_head;
    while (current_ballot)
    {
        if (strcmp(current_ballot->candidate_name, candidate_name) == 0)
        {
            // Add a vote to the candidate
            current_ballot->votes++;
            break;
        }
        current_ballot = current_ballot->next;
    }

    // If the candidate was not found, print an error
    if (current_ballot == NULL)
    {
        printf("Error: candidate not found\n");
    }
}