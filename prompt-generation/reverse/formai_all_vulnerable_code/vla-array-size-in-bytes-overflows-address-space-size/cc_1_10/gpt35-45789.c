//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Candidate {
    int candidateId;
    char candidateName[30];
    int voteCount;
};

struct Voter {
    int voterId;
    bool hasVoted;
    int voteNum;
};

void displayMenu(int numberOfCandidates, struct Candidate candidates[]) {
    printf("\nWelcome to the Electronic Voting System!\n");
    printf("Number of candidates: %d\n", numberOfCandidates);
    printf("Candidate list:\n");

    for (int i = 0; i < numberOfCandidates; i++) {
        printf("%d. %s\n", candidates[i].candidateId, candidates[i].candidateName);
    }
    printf("Enter 1 to vote, 2 to view results: ");
}

void performVoting(int voterId, int numberOfCandidates, struct Candidate candidates[], struct Voter voters[]) {
    int candidateId;
    printf("\nEnter candidate ID: ");
    scanf("%d", &candidateId);

    if (candidateId < 1 || candidateId > numberOfCandidates) {
        printf("Invalid candidate ID entered!");
        return;
    }

    if (voters[voterId-1].hasVoted) {
        printf("Sorry! You have already voted.\n");
        return;
    }

    voters[voterId-1].hasVoted = true;
    voters[voterId-1].voteNum = candidateId;

    candidates[candidateId-1].voteCount++;

    printf("\nThanks for voting!\n");
}

void displayResults(int numberOfCandidates, struct Candidate candidates[]) {
    printf("\nElection Results:\n");

    for (int i = 0; i < numberOfCandidates; i++) {
        printf("%d. %s: %d votes\n", candidates[i].candidateId, candidates[i].candidateName, candidates[i].voteCount);
    }
}

int main() {
    int numberOfCandidates;
    printf("Enter number of candidates: ");
    scanf("%d", &numberOfCandidates);

    struct Candidate candidates[numberOfCandidates];

    for (int i = 0; i < numberOfCandidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].candidateName);
        candidates[i].candidateId = i+1;
        candidates[i].voteCount = 0;
    }

    int numberOfVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numberOfVoters);

    struct Voter voters[numberOfVoters];

    for (int i = 0; i < numberOfVoters; i++) {
        voters[i].voterId = i+1;
        voters[i].hasVoted = false;
        voters[i].voteNum = -1;
    }

    int choice = 0;
    int voterId;

    while (choice != 3) {
        displayMenu(numberOfCandidates, candidates);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter voter ID: ");
                scanf("%d", &voterId);
                if (voterId < 1 || voterId > numberOfVoters) {
                    printf("Invalid voter ID entered!");
                    break;
                }
                performVoting(voterId, numberOfCandidates, candidates, voters);
                break;
            case 2:
                displayResults(numberOfCandidates, candidates);
                break;
            case 3:
                printf("\nThank you for using Electronic Voting System!\n");
                break;
            default:
                printf("\nInvalid choice entered!\n");
        }
    }

    return 0;
}