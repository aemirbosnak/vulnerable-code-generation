//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[50];
    int votes;
    struct Candidate* next;
} Candidate;

typedef struct Ballot {
    Candidate* candidate_list;
    int vote_count;
    struct Ballot* next;
} Ballot;

Ballot* createBallot() {
    Ballot* ballot = (Ballot*)malloc(sizeof(Ballot));
    ballot->candidate_list = NULL;
    ballot->vote_count = 0;
    ballot->next = NULL;
    return ballot;
}

void addCandidate(Ballot* ballot, Candidate* candidate) {
    candidate->next = ballot->candidate_list;
    ballot->candidate_list = candidate;
}

void vote(Ballot* ballot, Candidate* candidate) {
    candidate->votes++;
    ballot->vote_count++;
}

void printResults(Ballot* ballot) {
    Candidate* candidate = ballot->candidate_list;
    printf("Results:\n");
    while (candidate) {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }
    printf("Total Votes: %d\n", ballot->vote_count);
}

int main() {
    Ballot* ballot = createBallot();
    Candidate* candidate1 = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate1->name, "John Doe");
    addCandidate(ballot, candidate1);
    Candidate* candidate2 = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate2->name, "Jane Doe");
    addCandidate(ballot, candidate2);
    Candidate* candidate3 = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate3->name, "Bill Smith");
    addCandidate(ballot, candidate3);

    vote(ballot, candidate1);
    vote(ballot, candidate2);
    vote(ballot, candidate1);
    vote(ballot, candidate3);

    printResults(ballot);

    return 0;
}