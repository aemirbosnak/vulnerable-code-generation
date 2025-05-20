//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for holding each candidate's information
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function for displaying the list of candidates
void display_candidates(Candidate* candidates, int num_candidates) {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function for casting a vote
void cast_vote(Candidate* candidates, int num_candidates) {
    int vote;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &vote);

    if (vote < 1 || vote > num_candidates) {
        printf("Invalid candidate number.\n");
        return;
    }

    candidates[vote-1].votes++;
    printf("Your vote has been cast for %s.\n", candidates[vote-1].name);
}

// Function for displaying the current vote count
void display_results(Candidate* candidates, int num_candidates) {
    printf("Current Vote Count:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Allocate memory for the candidate array
    Candidate* candidates = (Candidate*)malloc(num_candidates * sizeof(Candidate));

    // Get the name of each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Loop until the user chooses to exit
    int choice;
    do {
        printf("\n1. Display list of candidates\n");
        printf("2. Cast a vote\n");
        printf("3. Display current vote count\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_candidates(candidates, num_candidates);
                break;
            case 2:
                cast_vote(candidates, num_candidates);
                break;
            case 3:
                display_results(candidates, num_candidates);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    // Free the memory allocated for the candidate array
    free(candidates);

    return 0;
}