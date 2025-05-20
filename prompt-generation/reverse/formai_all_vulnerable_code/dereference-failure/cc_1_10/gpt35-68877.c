//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define structure for candidate details
typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

// Function to display all the candidates
void listCandidates(Candidate* candidates, int numCandidates) {
    printf("List of Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d %s\n", candidates[i].id, candidates[i].name);
    }
}

// Function to vote for a candidate
void vote(Candidate* candidates, int numCandidates, int id) {
    int found = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].id == id) {
            candidates[i].votes++;
            printf("You have voted for %s\n", candidates[i].name);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid candidate ID\n");
    }
}

// Function to display the winner
void displayWinner(Candidate* candidates, int numCandidates) {
    int maxVotes = 0;
    int winner = -1;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winner = i;
        }
    }
    printf("Winner: %s\n", candidates[winner].name);
}

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    Candidate* candidates = (Candidate*) malloc(numCandidates * sizeof(Candidate));

    // Prompt user to enter candidate details
    for (int i = 0; i < numCandidates; i++) {
        Candidate candidate;
        candidate.id = i+1;

        printf("Enter candidate name: ");
        scanf("%s", candidate.name);

        candidate.votes = 0;

        candidates[i] = candidate;
    }

    // Display the list of candidates
    listCandidates(candidates, numCandidates);

    // Prompt user to vote
    int voteId;
    printf("Enter candidate ID to vote for (or 0 to quit): ");
    scanf("%d", &voteId);

    while (voteId != 0) {
        vote(candidates, numCandidates, voteId);

        printf("Enter candidate ID to vote for (or 0 to quit): ");
        scanf("%d", &voteId);
    }

    // Display winner
    displayWinner(candidates, numCandidates);

    free(candidates);

    return 0;
}