//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

typedef struct Poll {
    char candidate[MAX_CANDIDATES][50];
    int votes[MAX_CANDIDATES];
    struct Poll* next;
} Poll;

void vote(Poll* poll, Voter* voter) {
    int candidate_index = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(voter->name, poll->candidate[i]) == 0) {
            candidate_index = i;
            break;
        }
    }

    if (poll->votes[candidate_index] < MAX_VOTES) {
        poll->votes[candidate_index]++;
        voter->vote = candidate_index;
    } else {
        printf("Error: Vote limit exceeded.\n");
    }
}

int main() {
    Poll* poll = NULL;
    Voter* voter = NULL;

    // Create a new poll
    poll = malloc(sizeof(Poll));
    poll->next = NULL;

    // Create a new voter
    voter = malloc(sizeof(Voter));
    voter->next = NULL;

    // Add the voter to the poll
    poll->votes[0] = 1;
    poll->candidate[0][0] = 'A';
    poll->candidate[0][1] = 'B';
    poll->candidate[0][2] = 'C';
    poll->candidate[0][3] = 'D';
    poll->candidate[0][4] = 'E';

    // Vote
    vote(poll, voter);

    // Print the results
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", poll->candidate[i], poll->votes[i]);
    }

    return 0;
}