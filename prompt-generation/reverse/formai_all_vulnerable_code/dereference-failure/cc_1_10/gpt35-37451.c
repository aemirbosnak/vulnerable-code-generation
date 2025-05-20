//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters, vote;
    Candidate *candidates;
    char confirm_vote;

    printf("Welcome to the Voting System!\n");

    // Get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Allocate memory for candidates array
    candidates = (Candidate*) malloc(num_candidates * sizeof(Candidate));

    // Get candidates' information
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allow each voter to vote
    for (int i = 0; i < num_voters; i++) {
        printf("You are voter number %d\n\n", i+1);

        // Display list of candidates
        printf("List of Candidates\n");
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }

        // Ask for confirmation before voting
        printf("Are you sure you want to vote? (Y/N): ");
        scanf(" %c", &confirm_vote);

        if (confirm_vote == 'Y' || confirm_vote == 'y') {
            printf("Enter the number of your candidate: ");
            scanf("%d", &vote);

            // Increment candidate's votes
            if (vote >= 1 && vote <= num_candidates) {
                candidates[vote-1].votes++;
                printf("Vote recorded successfully!\n\n");
            } else {
                printf("Invalid vote. Please try again.\n\n");
            }
        } else {
            printf("Aborting vote.\n\n");
        }
    }

    // Display final results
    printf("\nFinal Results\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Free allocated memory
    free(candidates);

    return 0;
}