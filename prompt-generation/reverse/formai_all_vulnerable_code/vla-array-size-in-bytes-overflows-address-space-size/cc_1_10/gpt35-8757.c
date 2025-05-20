//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Structure to hold the details of a candidate
typedef struct {
    char name[30];
    int votes;
} Candidate;

// Structure to hold the details of a voter
typedef struct {
    char name[30];
    int voted;  // 0 if not voted, 1 if voted
} Voter;

// Function to display the list of candidates
void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("List of candidates:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to display the list of voters
void displayVoters(Voter voters[], int numVoters) {
    printf("List of voters:\n");
    for(int i=0; i<numVoters; i++) {
        printf("%d. %s\n", i+1, voters[i].name);
    }
}

// Function to get the index of the candidate with the given name
int getCandidateIndex(Candidate candidates[], int numCandidates, char name[]) {
    for(int i=0; i<numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to get the index of the voter with the given name
int getVoterIndex(Voter voters[], int numVoters, char name[]) {
    for(int i=0; i<numVoters; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numCandidates, numVoters;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    Candidate candidates[numCandidates];
    for(int i=0; i<numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);
    Voter voters[numVoters];
    for(int i=0; i<numVoters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }

    // Display the list of candidates and voters
    displayCandidates(candidates, numCandidates);
    displayVoters(voters, numVoters);

    // Voting Process
    printf("\nVoting process begins...\n");
    char choice[30];
    int index;
    int numVotes = 0;
    while(numVotes < numVoters) {
        printf("\nEnter the name of the voter: ");
        scanf("%s", choice);
        index = getVoterIndex(voters, numVoters, choice);
        if(index == -1) {
            printf("Invalid voter name. Please try again.\n");
            continue;
        }
        if(voters[index].voted == 1) {
            printf("This voter has already voted. Please try again.\n");
            continue;
        }
        printf("\nEnter the name of the candidate you want to vote for: ");
        scanf("%s", choice);
        index = getCandidateIndex(candidates, numCandidates, choice);
        if(index == -1) {
            printf("Invalid candidate name. Please try again.\n");
            continue;
        }
        candidates[index].votes += 1;
        voters[index].voted = 1;
        printf("Thank you for voting!\n");
        numVotes++;
    }

    // Display the results
    printf("\nResults:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    return 0;
}