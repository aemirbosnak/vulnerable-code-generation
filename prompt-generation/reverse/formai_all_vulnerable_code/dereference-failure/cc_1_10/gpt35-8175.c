//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

/* Voter struct to hold voter information */
typedef struct {
    char name[50];
    int age;
    char address[100];
    int voted;
} Voter;

/* Function to get voter information from user */
void getVoterInfo(Voter *voter) {
    printf("Enter name: ");
    scanf("%s", voter->name);
    printf("Enter age: ");
    scanf("%d", &voter->age);
    printf("Enter address: ");
    scanf("%s", voter->address);
    voter->voted = 0;
}

/* Function to display voter information */
void displayVoterInfo(Voter voter) {
    printf("----------------------\n");
    printf("Name: %s\n", voter.name);
    printf("Age: %d\n", voter.age);
    printf("Address: %s\n", voter.address);
    printf("----------------------\n");
}

/* Function to vote for candidate */
void vote(int *votes) {
    int candidate;
    printf("Enter candidate number: ");
    scanf("%d", &candidate);
    votes[candidate]++;
    printf("Vote cast successfully!\n");
}

/* Main function */
int main() {
    int numCandidates;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    int *votes = calloc(numCandidates, sizeof(int));
    if (votes == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    int numVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);
    Voter *voters = malloc(numVoters * sizeof(Voter));
    if (voters == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    for (int i = 0; i < numVoters; i++) {
        printf("Enter voter information for voter %d:\n", i+1);
        getVoterInfo(&voters[i]);
        displayVoterInfo(voters[i]);
    }
    int numVotes = 0;
    while (numVotes < numVoters) {
        int voterIndex;
        printf("Enter voter index: ");
        scanf("%d", &voterIndex);
        if (voters[voterIndex].voted == 0) {
            vote(votes);
            voters[voterIndex].voted = 1;
            numVotes++;
        } else {
            printf("Voter has already casted a vote!\n");
        }
    }
    printf("Voting has ended. Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %d votes\n", i+1, votes[i]);
    }
    free(votes);
    free(voters);
    return 0;
}