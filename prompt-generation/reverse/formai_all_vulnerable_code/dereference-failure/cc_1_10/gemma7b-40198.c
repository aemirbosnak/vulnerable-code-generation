//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char poll_name[20];
    Voter* head;
    struct Poll* next;
} Poll;

void vote(Poll* poll, char* candidate) {
    Voter* voter = poll->head;
    while (voter) {
        if (strcmp(voter->name, candidate) == 0) {
            voter->vote++;
            return;
        }
        voter = voter->next;
    }

    // Candidate not found, add new voter
    voter = malloc(sizeof(Voter));
    strcpy(voter->name, candidate);
    voter->vote = 1;
    voter->next = NULL;

    poll->head = voter;
}

int main() {
    Poll* polls = NULL;

    // Create a new poll
    polls = malloc(sizeof(Poll));
    strcpy(polls->poll_name, "Example Poll");
    polls->head = NULL;

    // Vote for candidate A
    vote(polls, "Candidate A");

    // Vote for candidate B
    vote(polls, "Candidate B");

    // Print the results
    Voter* voter = polls->head;
    while (voter) {
        printf("%s: %d votes\n", voter->name, voter->vote);
    }

    return 0;
}