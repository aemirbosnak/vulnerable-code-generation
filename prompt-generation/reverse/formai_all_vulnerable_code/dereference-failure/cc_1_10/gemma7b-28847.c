//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote_id;
    char vote_choice[MAX_CANDIDATES];
} Voter;

void vote(Voter **voters, int voter_id, int candidate_id) {
    for (int i = 0; i < voter_id; i++) {
        if (voters[i]->vote_id == voter_id) {
            voters[i]->vote_choice[candidate_id] = 1;
            return;
        }
    }

    // Voter not found, create new voter
    Voter *new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, "Voter");
    new_voter->vote_id = voter_id;
    strcpy(new_voter->vote_choice, "");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        new_voter->vote_choice[i] = 0;
    }
    new_voter->vote_choice[candidate_id] = 1;
    voters = realloc(voters, (voter_id + 1) * sizeof(Voter));
    voters[voter_id] = new_voter;
}

int main() {
    Voter **voters = NULL;
    int voter_id = 0;
    int candidate_id = 0;

    // Seed random number generator
    srand(time(NULL));

    // Simulate voter registration and voting
    for (int i = 0; i < MAX_VOTES; i++) {
        voter_id++;
        vote(voters, voter_id, rand() % MAX_CANDIDATES);
    }

    // Print vote results
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        int votes = 0;
        for (int j = 0; j < voter_id; j++) {
            if (voters[j]->vote_choice[i] == 1) {
                votes++;
            }
        }
        printf("Candidate %d: %d votes\n", i, votes);
    }

    return 0;
}