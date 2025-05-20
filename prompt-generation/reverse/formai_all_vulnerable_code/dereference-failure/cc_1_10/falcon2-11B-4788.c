//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int votes[3];
    int candidates[3];
    int i, j;

    // Initialize the candidates and votes
    strcpy(candidates[0], "Candidate A");
    strcpy(candidates[1], "Candidate B");
    strcpy(candidates[2], "Candidate C");
    votes[0] = 0;
    votes[1] = 0;
    votes[2] = 0;

    // Print the candidates
    printf("Candidate A\n");
    printf("%s\n\n", candidates[0]);
    printf("Candidate B\n");
    printf("%s\n\n", candidates[1]);
    printf("Candidate C\n");
    printf("%s\n\n", candidates[2]);

    // Get the votes
    printf("Please enter your vote:\n");
    scanf("%d", &votes[0]);
    printf("Vote for %s entered.\n", candidates[0]);
    scanf("%d", &votes[1]);
    printf("Vote for %s entered.\n", candidates[1]);
    scanf("%d", &votes[2]);
    printf("Vote for %s entered.\n", candidates[2]);

    // Count the votes
    for (i = 0; i < 3; i++) {
        printf("Candidate %d received %d votes.\n", i+1, votes[i]);
    }

    // Print the winner
    int max_votes = 0;
    int winner = 0;
    for (i = 0; i < 3; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = i+1;
        }
    }
    printf("The winner is %s with %d votes.\n", candidates[winner], max_votes);

    return 0;
}