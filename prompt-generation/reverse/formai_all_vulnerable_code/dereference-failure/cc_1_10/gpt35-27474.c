//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure to store each candidate information
struct Candidate{
    int id;
    char name[20];
    int votes;
};

// Function to display the list of candidates
void displayCandidateList(struct Candidate candidates[], int count){
    printf("Candidate List:\n");
    for(int i=0; i<count; i++){
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

// Function to vote for a candidate
void castVote(struct Candidate candidates[], int count, int candidateId){
    bool found = false;
    for(int i=0; i<count; i++){
        if(candidates[i].id == candidateId){
            candidates[i].votes++;
            found = true;
            break;
        }
    }
    if(found){
        printf("Vote casted for candidate %d.\n", candidateId);
    }
    else{
        printf("Invalid candidate ID.\n");
    }
}

// Function to display the results of the election
void displayElectionResults(struct Candidate candidates[], int count){
    printf("Election Results:\n");
    int maxVotes = 0;
    int winnerId = 0;
    for(int i=0; i<count; i++){
        if(candidates[i].votes > maxVotes){
            maxVotes = candidates[i].votes;
            winnerId = candidates[i].id;
        }
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    printf("Winner: Candidate %d\n", winnerId);
}

int main(){
    int numOfCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numOfCandidates);
    // Allocate memory dynamically for the candidates
    struct Candidate *candidates = (struct Candidate*) malloc(numOfCandidates * sizeof(struct Candidate));
    // Initialize each candidate with a unique ID and zero number of votes
    for(int i=0; i<numOfCandidates; i++){
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }
    // Collect the names of each candidate from the user
    for(int i=0; i<numOfCandidates; i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }
    // Display the list of candidates
    displayCandidateList(candidates, numOfCandidates);
    // Allow the user to cast votes until they choose to quit
    int vote;
    while(vote != 0){
        printf("Enter the candidate ID you want to vote for (0 to exit): ");
        scanf("%d", &vote);
        if(vote != 0){
            castVote(candidates, numOfCandidates, vote);
        }
    }
    // Display the results of the election
    displayElectionResults(candidates, numOfCandidates);
    // Free the allocated memory
    free(candidates);
    return 0;
}