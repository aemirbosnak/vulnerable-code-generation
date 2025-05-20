//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a struct for each candidate
typedef struct {
    char name[30];
    int votes;
} Candidate;

// Function prototypes
void displayCandidates(Candidate [], int);
void castVote(Candidate [], int);
void displayResults(Candidate [], int);

int main() {
    int numOfCandidates, numOfVoters;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numOfCandidates);

    // Create an array of candidates
    Candidate candidates[numOfCandidates];

    // Populate the array of candidates with name and initial number of votes
    for (int i = 0; i < numOfCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Display the candidate list
    displayCandidates(candidates, numOfCandidates);

    printf("\nPlease enter the number of voters: ");
    scanf("%d", &numOfVoters);

    // Loop through each voter and allow them to cast their vote
    for (int i = 0; i < numOfVoters; i++) {
        castVote(candidates, numOfCandidates);
    }

    printf("\nThank you for voting! Here are the results:\n");

    // Display the final results
    displayResults(candidates, numOfCandidates);

    return 0;
}

// Function to display the list of candidates
void displayCandidates(Candidate candidates[], int size) {
    printf("\nList of Candidates:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to allow a voter to cast their vote
void castVote(Candidate candidates[], int size) {
    int vote;
    printf("\n");
    displayCandidates(candidates, size);
    printf("\nEnter the number of the candidate you wish to vote for: ");
    scanf("%d", &vote);

    // Increment the vote count for the selected candidate
    candidates[vote - 1].votes++;
    printf("Thank you for voting for %s!\n", candidates[vote - 1].name);
}

// Function to display the final results
void displayResults(Candidate candidates[], int size) {
    int maxVotes = 0;
    int winnerIndex = 0;
    for (int i = 0; i < size; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("\nThe winner is %s with %d votes!\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
}