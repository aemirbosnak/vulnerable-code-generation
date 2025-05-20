//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Candidate structures
typedef struct candidate {
    char *name;
    int votes;
} candidate;

// Main function
int main() {
    // Initialize candidates
    candidate candidates[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0}
    };

    // Get number of voters
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get votes
    int votes[num_voters];
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the vote for voter %d (1, 2, or 3): ", i + 1);
        scanf("%d", &votes[i]);
    }

    // Count votes
    for (int i = 0; i < num_voters; i++) {
        candidates[votes[i] - 1].votes++;
    }

    // Print results
    printf("Election results:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < 3; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    // Print winner
    if (winner_index == -1) {
        printf("Tie between Alice, Bob, and Charlie\n");
    } else {
        printf("The winner is %s\n", candidates[winner_index].name);
    }

    return 0;
}