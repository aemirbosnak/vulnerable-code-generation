//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

typedef struct Ballot {
    Candidate* candidates;
    int votes_cast;
    struct Ballot* next;
} Ballot;

Candidate* create_candidate(char* name) {
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

Ballot* create_ballot() {
    Ballot* ballot = malloc(sizeof(Ballot));
    ballot->candidates = NULL;
    ballot->votes_cast = 0;
    ballot->next = NULL;
    return ballot;
}

void add_candidate(Ballot* ballot, char* name) {
    Candidate* candidate = create_candidate(name);
    if (ballot->candidates == NULL) {
        ballot->candidates = candidate;
    } else {
        ballot->candidates->next = candidate;
    }
}

void vote(Ballot* ballot, char* candidate_name) {
    Candidate* candidate = ballot->candidates;
    while (candidate) {
        if (strcmp(candidate->name, candidate_name) == 0) {
            candidate->votes++;
            ballot->votes_cast++;
            break;
        }
        candidate = candidate->next;
    }
}

int main() {
    Ballot* ballot = create_ballot();
    add_candidate(ballot, "John Doe");
    add_candidate(ballot, "Jane Doe");
    add_candidate(ballot, "Bill Smith");
    add_candidate(ballot, "Mary Johnson");
    add_candidate(ballot, "Bob White");

    vote(ballot, "John Doe");
    vote(ballot, "Jane Doe");
    vote(ballot, "Bill Smith");
    vote(ballot, "Mary Johnson");

    printf("Results:");
    Candidate* candidate = ballot->candidates;
    while (candidate) {
        printf(" %s: %d votes", candidate->name, candidate->votes);
        printf("\n");
        candidate = candidate->next;
    }

    printf("Total votes cast: %d", ballot->votes_cast);

    return 0;
}