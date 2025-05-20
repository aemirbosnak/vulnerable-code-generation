//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
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

void initializeVoters(Voter **voters, int numVoters);
void castVote(Voter **voters, int candidate);
void displayResults(Voter **voters);

int main() {
    Voter **voters = NULL;
    int numVoters = 0;

    // Initialize the voters
    initializeVoters(&voters, numVoters);

    // Cast votes
    castVote(voters, 2);
    castVote(voters, 3);
    castVote(voters, 1);

    // Display results
    displayResults(voters);

    return 0;
}

void initializeVoters(Voter **voters, int numVoters) {
    *voters = (Voter *)malloc(numVoters * sizeof(Voter));
    for (int i = 0; i < numVoters; i++) {
        (*voters)[i].name[0] = '\0';
        (*voters)[i].vote = 0;
        (*voters)[i].timestamp = time(NULL);
    }
}

void castVote(Voter **voters, int candidate) {
    for (int i = 0; i < MAX_VOTES; i++) {
        if ((*voters)[i].name[0] == '\0') {
            strcpy((*voters)[i].name, "John Doe");
            (*voters)[i].vote = candidate;
            (*voters)[i].timestamp = time(NULL);
            return;
        }
    }

    printf("Error: Voting system full.\n");
}

void displayResults(Voter **voters) {
    int totalVotes = 0;
    for (int i = 0; i < MAX_VOTES; i++) {
        if ((*voters)[i].name[0] != '\0') {
            totalVotes++;
        }
    }

    printf("Total votes: %d\n", totalVotes);
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        int votes = 0;
        for (int j = 0; j < MAX_VOTES; j++) {
            if ((*voters)[j].name[0] != '\0' && (*voters)[j].vote == i + 1) {
                votes++;
            }
        }

        printf("Candidate %d: %d votes\n", i + 1, votes);
    }
}