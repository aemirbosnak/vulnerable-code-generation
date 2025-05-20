//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 1000

typedef struct Voter
{
    char name[50];
    int vote_count;
    struct Voter* next;
} Voter;

typedef struct Ballot
{
    char candidate_name[50];
    int vote_count;
    struct Ballot* next;
} Ballot;

Ballot* create_ballot(char* candidate_name, int vote_count)
{
    Ballot* new_ballot = (Ballot*)malloc(sizeof(Ballot));
    strcpy(new_ballot->candidate_name, candidate_name);
    new_ballot->vote_count = vote_count;
    new_ballot->next = NULL;
    return new_ballot;
}

Voter* create_voter(char* name, int vote_count)
{
    Voter* new_voter = (Voter*)malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
    new_voter->vote_count = vote_count;
    new_voter->next = NULL;
    return new_voter;
}

void vote(Voter* voter, Ballot* ballot)
{
    if (voter->vote_count > 0)
    {
        for (Ballot* current_ballot = ballot; current_ballot; current_ballot = current_ballot->next)
        {
            if (strcmp(current_ballot->candidate_name, voter->name) == 0)
            {
                current_ballot->vote_count++;
                voter->vote_count--;
                break;
            }
        }
    }
}

int main()
{
    time_t t = time(NULL);

    // Create a list of voters
    Voter* head_voter = create_voter("John Doe", 3);
    head_voter->next = create_voter("Jane Doe", 2);
    head_voter->next->next = create_voter("Bob Smith", 1);

    // Create a list of ballots
    Ballot* head_ballot = create_ballot("Alice White", 50);
    head_ballot->next = create_ballot("Bob Green", 40);
    head_ballot->next->next = create_ballot("Charlie Brown", 30);

    // Vote
    vote(head_voter, head_ballot);

    // Print the results
    for (Ballot* current_ballot = head_ballot; current_ballot; current_ballot = current_ballot->next)
    {
        printf("%s has received %d votes.\n", current_ballot->candidate_name, current_ballot->vote_count);
    }

    printf("Time taken: %ld seconds.", time(NULL) - t);

    return 0;
}