//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[25];
    int votes;
} Candidate;

int main() {
    int num_candidates;
    int num_voters;

    printf("Welcome to the Electronic Voting System.\n\n");

    // Get number of candidates
    printf("How many candidates are there? ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];

    // Get candidate names
    for (int i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get number of voters
    printf("\nHow many voters are there? ");
    scanf("%d", &num_voters);

    // Vote for candidates
    int vote;
    for (int i=0; i<num_voters; i++) {
        printf("\nVoter %d, please enter your vote:\n", i+1);
        for (int j=0; j<num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        printf("Enter your vote: ");
        scanf("%d", &vote);

        // Check for valid vote
        if (vote >= 1 && vote <= num_candidates) {
            candidates[vote-1].votes++;
            printf("Thank you for voting!\n");
        } else {
            printf("Invalid vote. Please try again.\n");
        }
    }

    // Display results
    printf("\n\nRESULTS:\n");
    printf("Candidate\tVotes Received\tPercentage\n");
    for (int i=0; i<num_candidates; i++) {
        float percentage = (candidates[i].votes * 100.0) / num_voters;
        printf("%s\t\t%d\t\t%.2f%%\n", candidates[i].name, candidates[i].votes, percentage);
    }

    // Find the winner
    int max = candidates[0].votes;
    int winner_index = 0;
    for (int i=1; i<num_candidates; i++) {
        if (candidates[i].votes > max) {
            max = candidates[i].votes;
            winner_index = i;
        }
    }

    // Display winner
    printf("\nThe winner is %s\n", candidates[winner_index].name);

    return 0;
}