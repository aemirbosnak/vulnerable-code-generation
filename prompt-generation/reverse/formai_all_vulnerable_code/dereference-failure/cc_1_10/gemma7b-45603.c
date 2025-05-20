//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int vote_count[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

Voter* create_voter(char* name, int vote)
{
    Voter* new_voter = (Voter*)malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;
    return new_voter;
}

Poll* create_poll(char** candidates, int num_candidates)
{
    Poll* new_poll = (Poll*)malloc(sizeof(Poll));
    for(int i = 0; i < num_candidates; i++)
    {
        strcpy(new_poll->candidate[i], candidates[i]);
        new_poll->vote_count[i] = 0;
    }
    new_poll->next = NULL;
    return new_poll;
}

void vote(Voter* voter, Poll* poll)
{
    int candidate_vote = voter->vote;
    poll->vote_count[candidate_vote]++;
}

int main()
{
    char** candidates = {"John Doe", "Jane Doe", "Peter Pan", "Mary Poppins", "Captain America"};
    int num_candidates = 5;

    Poll* poll = create_poll(candidates, num_candidates);

    Voter* voter1 = create_voter("John Doe", 1);
    vote(voter1, poll);

    Voter* voter2 = create_voter("Jane Doe", 2);
    vote(voter2, poll);

    Voter* voter3 = create_voter("Peter Pan", 3);
    vote(voter3, poll);

    Voter* voter4 = create_voter("Mary Poppins", 2);
    vote(voter4, poll);

    Voter* voter5 = create_voter("Captain America", 4);
    vote(voter5, poll);

    int winner = 0;
    for(int i = 0; i < num_candidates; i++)
    {
        if(poll->vote_count[i] > winner)
        {
            winner = i;
        }
    }

    printf("The winner is: %s", poll->candidate[winner]);

    return 0;
}