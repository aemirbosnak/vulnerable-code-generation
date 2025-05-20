//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store vote
struct vote {
    char name[20];
    int count;
};

// Function declarations
void castVote(struct vote *candidates, int numCandidates, char *voterID);
void printResults(struct vote *candidates, int numCandidates);
void clearVotes(struct vote *candidates, int numCandidates);

int main() {
    int numCandidates, numVoters;
    struct vote *candidates;

    printf("Welcome to the Paranoid Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Allocate memory for candidates array
    candidates = (struct vote*) malloc(numCandidates * sizeof(struct vote));

    // Initialize candidate names and vote counts
    for(int i=0; i<numCandidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].count = 0;
    }

    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);

    char voterID[20];
    for(int i=0; i<numVoters; i++) {
        printf("Enter voter ID: ");
        scanf("%s", voterID);

        castVote(candidates, numCandidates, voterID);
    }

    printf("Printing voting results...\n");
    printResults(candidates, numCandidates);

    clearVotes(candidates, numCandidates);

    free(candidates);
    return 0;
}

// Function to cast a vote
void castVote(struct vote *candidates, int numCandidates, char *voterID) {
    printf("Please cast your vote...\n");

    int voteNum;
    printf("Enter the number of your chosen candidate: ");
    scanf("%d", &voteNum);

    // Ensure entered candidate number is valid
    while(voteNum < 1 || voteNum > numCandidates) {
        printf("Invalid candidate number. Please enter a number between 1 and %d: ", numCandidates);
        scanf("%d", &voteNum);
    }

    // Increment candidate vote count
    candidates[voteNum-1].count++;

    printf("Thank you for casting your vote!\n");
    printf("Please remember to keep your voter ID safe and secure.\n");
}

// Function to print voting results
void printResults(struct vote *candidates, int numCandidates) {
    int maxVotes = -1;
    int maxIndex = -1;

    printf("Results:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].count);

        // Check for tie
        if(candidates[i].count == maxVotes) {
            printf("There is a tie between candidates %s and %s!\n", candidates[maxIndex].name, candidates[i].name);
        }

        // Check for new winner
        if(candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            maxIndex = i;
        }
    }

    printf("%s is the winner!\n", candidates[maxIndex].name);
}

// Function to clear all votes
void clearVotes(struct vote *candidates, int numCandidates) {
    for(int i=0; i<numCandidates; i++) {
        candidates[i].count = 0;
    }
}