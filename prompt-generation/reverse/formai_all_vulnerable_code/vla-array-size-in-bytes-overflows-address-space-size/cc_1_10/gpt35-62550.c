//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>

// function to validate voter ID
int validate_voter_id(int voter_id) {
    // some validation logic goes here
    // return 1 if valid voter ID, 0 otherwise
    return 1;
}

// function to cast vote for a candidate
void cast_vote(int candidate_id, int *candidate_votes) {
    // increment vote count for the candidate
    candidate_votes[candidate_id - 1]++;
}

int main() {
    int num_candidates, voter_id, candidate_id;
    printf("Welcome to the Electronic Voting System!\n");

    // get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // create an array to store vote count for each candidate
    int candidate_votes[num_candidates];
    for (int i = 0; i < num_candidates; i++) {
        candidate_votes[i] = 0;
    }

    // get voter ID and cast vote
    while (1) {
        printf("Enter your voter ID (or -1 to exit): ");
        scanf("%d", &voter_id);

        if (voter_id == -1) {
            break;
        }

        if (!validate_voter_id(voter_id)) {
            printf("Invalid voter ID! Please try again.\n");
            continue;
        }

        printf("Enter candidate ID (1-%d): ", num_candidates);
        scanf("%d", &candidate_id);

        if (candidate_id < 1 || candidate_id > num_candidates) {
            printf("Invalid candidate ID! Please try again.\n");
            continue;
        }

        cast_vote(candidate_id, candidate_votes);
        printf("Thank you for voting!\n");
    }

    // display vote count for each candidate
    printf("Vote count for each candidate:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: %d\n", i+1, candidate_votes[i]);
    }

    printf("Exiting Electronic Voting System...\n");

    return 0;
}