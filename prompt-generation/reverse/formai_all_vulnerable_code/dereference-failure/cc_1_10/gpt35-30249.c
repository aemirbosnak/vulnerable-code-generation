//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store vote information
typedef struct vote {
    char candidate[50];
    int partyNumber;
    int voteCount;
} Vote;

// Prototypes
void displayMenu();
void castVote(Vote*, int);
void displayResults(Vote*, int);

int main() {
    int numCandidates, choice, i;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Dynamic memory allocation for vote information
    Vote* votes = (Vote*)malloc(numCandidates * sizeof(Vote));
    for (i = 0; i < numCandidates; i++) {
        printf("Enter Candidate %d's name: ", i+1);
        scanf("%s", votes[i].candidate);
        printf("Enter Candidate %d's party number: ", i+1);
        scanf("%d", &votes[i].partyNumber);
        votes[i].voteCount = 0;
    }

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                castVote(votes, numCandidates);
                break;
            case 2:
                displayResults(votes, numCandidates);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    free(votes); // Free dynamically allocated memory
    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\nPlease choose one of the following options:\n");
    printf("1. Cast a Vote\n");
    printf("2. Display Results\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to cast vote
void castVote(Vote* votes, int numCandidates) {
    int candidateNum, i;
    printf("Enter the party number of the candidate you want to vote for: ");
    scanf("%d", &candidateNum);

    for (i = 0; i < numCandidates; i++) {
        if (candidateNum == votes[i].partyNumber) {
            votes[i].voteCount++;
            printf("You have successfully cast your vote for %s.\n", votes[i].candidate);
            return;
        }
    }
    printf("Invalid candidate party number. Please try again.\n");
}

// Function to display results
void displayResults(Vote* votes, int numCandidates) {
    int i;
    printf("\n\n*******************************\n");
    printf("Party Number\tName\tVote Count\n");
    printf("*******************************\n");

    for (i = 0; i < numCandidates; i++) {
        printf("%d\t\t%s\t%d\n", votes[i].partyNumber, votes[i].candidate, votes[i].voteCount);
    }
}