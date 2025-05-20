//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store candidate information
typedef struct Candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

// Function to display menu options
void display_menu() {
    printf("\n\nWelcome to the Electronic Voting System!\n");
    printf("1. Register as a candidate\n");
    printf("2. Cast your vote\n");
    printf("3. View results\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main() {
    int num_candidates = 0;
    Candidate *candidates = NULL;

    int num_voters = 0;
    int *voter_ids = NULL;
    int *votes = NULL;

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Register as a candidate
                printf("\nEnter candidate name: ");
                char name[50];
                scanf("%s", name);
                num_candidates++; // Increment number of candidates
                candidates = realloc(candidates, sizeof(Candidate) * num_candidates);
                candidates[num_candidates-1].id = num_candidates; // Unique ID for each candidate
                strcpy(candidates[num_candidates-1].name, name); // Copy name to candidate structure
                candidates[num_candidates-1].votes = 0; // Set initial votes to zero
                printf("\nCandidate registered successfully with ID: %d\n", num_candidates);
                break;
            case 2: // Cast your vote
                printf("\nEnter your voter ID: ");
                int voter_id;
                scanf("%d", &voter_id);

                // Check if voter has already voted
                int already_voted = 0;
                for (int i = 0; i < num_voters; i++) {
                    if (voter_ids[i] == voter_id) {
                        already_voted = 1;
                        break;
                    }
                }

                if (already_voted) {
                    printf("\nYou have already voted!\n");
                } else {
                    num_voters++; // Increment number of voters
                    voter_ids = realloc(voter_ids, sizeof(int) * num_voters);
                    votes = realloc(votes, sizeof(int) * num_voters);

                    // Record voter ID and candidate ID chosen by the voter
                    voter_ids[num_voters-1] = voter_id;
                    printf("\nChoose a candidate to vote:\n");
                    for (int i = 0; i < num_candidates; i++) {
                        printf("%d. %s\n", candidates[i].id, candidates[i].name);
                    }
                    printf("Enter candidate ID: ");
                    int candidate_id;
                    scanf("%d", &candidate_id);

                    // Find the candidate and increase their votes by one
                    for (int i = 0; i < num_candidates; i++) {
                        if (candidates[i].id == candidate_id) {
                            candidates[i].votes++;
                            votes[num_voters-1] = candidate_id;
                            printf("\nVote cast successfully!\n");
                            break;
                        }
                    }
                }
                break;
            case 3: // View results
                printf("\nCandidate\tVotes\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
                }
                break;
            case 4: // Exit
                printf("\nThank you for using the Electronic Voting System!\n");
                break;
            default: // Invalid choice
                printf("\nInvalid choice\n");
                break;
        }
    } while (choice != 4);

    // Free allocated memory
    free(candidates);
    free(voter_ids);
    free(votes);

    return 0;
}