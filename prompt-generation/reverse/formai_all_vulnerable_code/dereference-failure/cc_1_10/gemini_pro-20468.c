//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int votes;
} candidate;

candidate *candidates;
int num_candidates;
int num_voters;
int *votes;

int main() {
    // Initialize the candidates
    candidates = malloc(sizeof(candidate) * 3);
    candidates[0].name = "Alice";
    candidates[0].votes = 0;
    candidates[1].name = "Bob";
    candidates[1].votes = 0;
    candidates[2].name = "Carol";
    candidates[2].votes = 0;
    num_candidates = 3;

    // Initialize the voters
    num_voters = 100;
    votes = malloc(sizeof(int) * num_voters);
    for (int i = 0; i < num_voters; i++) {
        votes[i] = rand() % num_candidates;
    }

    // Count the votes
    for (int i = 0; i < num_voters; i++) {
        candidates[votes[i]].votes++;
    }

    // Find the winner
    candidate *winner = NULL;
    for (int i = 0; i < num_candidates; i++) {
        if (winner == NULL || candidates[i].votes > winner->votes) {
            winner = &candidates[i];
        }
    }

    // Print the results
    printf("The winner is %s with %d votes\n", winner->name, winner->votes);

    // Free the memory
    free(candidates);
    free(votes);

    return 0;
}