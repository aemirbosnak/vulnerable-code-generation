//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int vote;
} voter;

// Define the function to add a voter
void addVoter(voter **v, int *n) {
    *v = malloc((*n) * sizeof(voter));
    (*v)->vote = 0;
    printf("Enter voter name: ");
    scanf("%s", (*v)->name);
    (*n)++;
}

// Define the function to vote
void vote(voter *v, int choice) {
    v->vote = choice;
}

// Define the function to tally votes
int tallyVotes(voter *v, int n) {
    int totalVotes = 0;
    for (int i = 0; i < n; i++) {
        totalVotes += v[i].vote;
    }
    return totalVotes;
}

int main() {
    int numVoters = 0;
    voter *v = NULL;

    // Add voters
    addVoter(&v, &numVoters);
    addVoter(&v, &numVoters);
    addVoter(&v, &numVoters);

    // Vote
    vote(v, 2);
    vote(v, 1);
    vote(v, 2);

    // Tally votes
    int totalVotes = tallyVotes(v, numVoters);

    // Print results
    printf("Total votes: %d", totalVotes);

    return 0;
}