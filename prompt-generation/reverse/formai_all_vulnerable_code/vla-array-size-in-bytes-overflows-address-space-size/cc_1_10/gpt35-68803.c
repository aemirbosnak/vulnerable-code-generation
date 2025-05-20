//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int votes;
} Candidate;

// Function prototypes
void initialize_candidates(Candidate[]);
void display_candidates(Candidate[]);
void cast_vote(Candidate[], int);
void display_results(Candidate[]);

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];
    initialize_candidates(candidates);
    display_candidates(candidates);

    // Voting begins
    printf("\n\nEnter the number of voters: ");
    scanf("%d", &num_voters);
    for (int i = 0; i < num_voters; i++) {
        printf("\n\nVoter %d:\n", i+1);
        cast_vote(candidates, num_candidates);
    }

    // Display results
    printf("\n\nResults:\n");
    display_results(candidates);

    return 0;
}

void initialize_candidates(Candidate candidates[]) {
    for (int i = 0; i < sizeof(candidates)/sizeof(candidates[0]); i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void display_candidates(Candidate candidates[]) {
    printf("\nCandidates:\n");
    for (int i = 0; i < sizeof(candidates)/sizeof(candidates[0]); i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void cast_vote(Candidate candidates[], int num_candidates) {
    int choice;
    printf("Select your candidate (1-%d): ", num_candidates);
    scanf("%d", &choice);
    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice. Please try again.\n");
        cast_vote(candidates, num_candidates);
    }
    else {
        candidates[choice-1].votes++;
        printf("Your vote has been recorded. Thank you!\n");
    }
}

void display_results(Candidate candidates[]) {
    int max_votes = candidates[0].votes;
    int winner_index = 0;
    for (int i = 1; i < sizeof(candidates)/sizeof(candidates[0]); i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("%s is the winner with %d votes!\n", candidates[winner_index].name, max_votes);
    printf("\nVotes for all candidates:\n");
    for (int i = 0; i < sizeof(candidates)/sizeof(candidates[0]); i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}