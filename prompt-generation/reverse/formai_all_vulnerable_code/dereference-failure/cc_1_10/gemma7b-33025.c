//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the maximum number of votes for each voter
#define MAX_VOTES 5

// Define the structure of a voter
typedef struct Voter {
    char name[50];
    int votes[MAX_VOTES];
    int hasVoted;
} Voter;

// Function to add a voter to the system
void addVoter(Voter **voters, int *numVoters) {
    // Allocate memory for the new voter
    *voters = (Voter *)malloc((*numVoters) * sizeof(Voter));

    // Get the voter's name
    printf("Enter your name: ");
    scanf("%s", (*voters)->name);

    // Initialize the voter's votes
    for (int i = 0; i < MAX_VOTES; i++) {
        (*voters)->votes[i] = 0;
    }

    // Mark the voter as having voted
    (*voters)->hasVoted = 0;

    // Increment the number of voters
    (*numVoters)++;
}

// Function to vote for a candidate
void vote(Voter **voters, int numVoters) {
    // Check if the voter has already voted
    if ((*voters)->hasVoted) {
        printf("You have already voted.\n");
        return;
    }

    // Get the candidate's number
    int candidateNum;
    printf("Enter the candidate number: ");
    scanf("%d", &candidateNum);

    // Validate the candidate number
    if (candidateNum < 1 || candidateNum > MAX_VOTES) {
        printf("Invalid candidate number.\n");
        return;
    }

    // Mark the voter as having voted
    (*voters)->hasVoted = 1;

    // Increment the vote count for the candidate
    ((*voters)->votes[candidateNum - 1])++;
}

// Function to display the results of the election
void displayResults(Voter **voters, int numVoters) {
    // Calculate the total number of votes
    int totalVotes = 0;
    for (int i = 0; i < numVoters; i++) {
        totalVotes += voters[i]->votes[0];
    }

    // Print the results
    printf("Total number of votes: %d\n", totalVotes);
    printf("Winner: Candidate %d\n", voters[0]->votes[0] > voters[1]->votes[0] ? 1 : 2);
}

int main() {
    // Create an array of voters
    Voter *voters = NULL;
    int numVoters = 0;

    // Add voters to the system
    addVoter(&voters, &numVoters);
    addVoter(&voters, &numVoters);
    addVoter(&voters, &numVoters);

    // Vote for a candidate
    vote(&voters, numVoters);
    vote(&voters, numVoters);

    // Display the results of the election
    displayResults(&voters, numVoters);

    return 0;
}