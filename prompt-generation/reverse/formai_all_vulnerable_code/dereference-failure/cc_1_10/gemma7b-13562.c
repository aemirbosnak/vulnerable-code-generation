//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    time_t timestamp;
} Voter;

void initializeVoters(Voter **voters, int n) {
    for (int i = 0; i < n; i++) {
        voters[i] = malloc(sizeof(Voter));
        voters[i]->vote = 0;
        strcpy(voters[i]->name, "");
        voters[i]->timestamp = time(NULL);
    }
}

void castVote(Voter **voters, int candidate, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(voters[i]->name, "John Doe") == 0) {
            voters[i]->vote = candidate;
            voters[i]->timestamp = time(NULL);
            break;
        }
    }
}

void displayResults(Voter **voters, int n) {
    int totalVotes = 0;
    for (int i = 0; i < n; i++) {
        totalVotes += voters[i]->vote;
    }

    printf("Total Votes: %d\n", totalVotes);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        int votes = 0;
        for (int j = 0; j < n; j++) {
            if (voters[j]->vote == i) {
                votes++;
            }
        }

        printf("Candidate %d: %d votes\n", i, votes);
    }
}

int main() {
    Voter **voters = NULL;
    int nVoters = 100;

    initializeVoters(&voters, nVoters);

    castVote(voters, 2, nVoters);
    castVote(voters, 1, nVoters);
    castVote(voters, 3, nVoters);

    displayResults(voters, nVoters);

    return 0;
}