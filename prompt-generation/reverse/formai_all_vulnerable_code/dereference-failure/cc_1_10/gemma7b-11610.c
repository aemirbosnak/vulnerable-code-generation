//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter *next;
} Voter;

typedef struct Poll {
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    struct Poll *next;
} Poll;

int main() {
    time_t t;
    srand(time(&t));

    Poll *poll = NULL;
    Voter *voter = NULL;

    // Create a new poll
    poll = malloc(sizeof(Poll));
    poll->next = NULL;

    // Create a new voter
    voter = malloc(sizeof(Voter));
    voter->next = NULL;

    // Add the voter to the poll
    poll->votes[0] = rand() % MAX_VOTES;
    voter->vote = poll->votes[0];
    voter->next = NULL;

    // Repeat the above steps for a number of voters
    for (int i = 1; i < MAX_VOTES; i++) {
        voter = malloc(sizeof(Voter));
        voter->next = NULL;

        poll->votes[i] = rand() % MAX_VOTES;
        voter->vote = poll->votes[i];
        voter->next = voter;

        poll->next = malloc(sizeof(Poll));
        poll->next->next = NULL;
        poll = poll->next;
    }

    // Print the results of the poll
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", poll->candidate[i], poll->votes[i]);
    }

    return 0;
}