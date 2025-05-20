//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate
{
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

typedef struct Vote
{
    char voter_name[50];
    char candidate_name[50];
    struct Vote* next;
} Vote;

Candidate* createCandidate(char* name)
{
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

Vote* createVote(char* voter_name, char* candidate_name)
{
    Vote* vote = (Vote*)malloc(sizeof(Vote));
    strcpy(vote->voter_name, voter_name);
    strcpy(vote->candidate_name, candidate_name);
    vote->next = NULL;
    return vote;
}

void addVote(Candidate* candidate, Vote* vote)
{
    candidate->votes++;
    candidate->next = vote;
}

void printResults(Candidate* candidates)
{
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next)
    {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }
}

int main()
{
    // Create a list of candidates
    Candidate* candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bob Smith");

    // Create a list of votes
    Vote* votes = createVote("Alice White", "John Doe");
    votes = createVote("Bob Green", "Jane Doe");
    votes = createVote("Charlie Brown", "Bob Smith");

    // Add the votes to the candidates
    addVote(candidates, votes);

    // Print the results
    printResults(candidates);

    return 0;
}