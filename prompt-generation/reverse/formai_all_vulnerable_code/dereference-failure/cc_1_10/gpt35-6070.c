//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int hasVoted;
};

struct candidate* createCandidate(char name[]) {
    struct candidate* newCandidate = (struct candidate*) malloc(sizeof(struct candidate));
    strcpy(newCandidate->name, name);
    newCandidate->votes = 0;
    return newCandidate;
}

struct voter* createVoter(char name[]) {
    struct voter* newVoter = (struct voter*) malloc(sizeof(struct voter));
    strcpy(newVoter->name, name);
    newVoter->hasVoted = 0;
    return newVoter;
}

int main() {
    int numCandidates, numVoters;
    
    printf("Welcome to the Electronic Voting System. I am Sherlock Holmes and will be your guide.\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);
    
    struct candidate** candidates = (struct candidate**) malloc(sizeof(struct candidate*) * numCandidates);
    
    for(int i = 0; i < numCandidates; i++) {
        char name[50];
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", name);
        candidates[i] = createCandidate(name);
    }
    
    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);
    
    struct voter** voters = (struct voter**) malloc(sizeof(struct voter*) * numVoters);
    
    for(int i = 0; i < numVoters; i++) {
        char name[50];
        printf("Enter voter %d's name: ", i+1);
        scanf("%s", name);
        voters[i] = createVoter(name);
    }
    
    int done = 0;
    while(!done) {
        printf("What would you like to do?\n");
        printf("1. Allow a voter to cast a vote\n");
        printf("2. View current vote count\n");
        printf("3. Declare the winner\n");
        printf("4. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("Enter the name of the voter: ");
                char name[50];
                scanf("%s", name);
                
                int voterIndex = -1;
                for(int i = 0; i < numVoters; i++) {
                    if(strcmp(name, voters[i]->name) == 0) {
                        voterIndex = i;
                        break;
                    }
                }
                
                if(voterIndex == -1) { 
                    printf("Sorry, I cannot find a voter with that name.\n");
                    break;
                }
                
                if(voters[voterIndex]->hasVoted) { 
                    printf("Sorry, that voter has already cast a vote.\n");
                    break;
                }
                
                printf("Enter the name of the candidate you wish to vote for: ");
                char candidateName[50];
                scanf("%s", candidateName);
                
                int candidateIndex = -1;
                for(int i = 0; i < numCandidates; i++) {
                    if(strcmp(candidateName, candidates[i]->name) == 0) {
                        candidateIndex = i;
                        break;
                    }
                }
                
                if(candidateIndex == -1) {
                    printf("Sorry, I cannot find a candidate with that name.\n");
                    break;
                }
                
                candidates[candidateIndex]->votes++;
                printf("Thanks for casting your vote, %s.\n", voters[voterIndex]->name);
                voters[voterIndex]->hasVoted = 1;
                
                break;
                
            case 2:
                printf("Current Vote Count:\n");
                for(int i = 0; i < numCandidates; i++) {
                    printf("%s: %d\n", candidates[i]->name, candidates[i]->votes);
                }
                break;
                
            case 3:
                printf("The winner is: ");
                int maxVotes = -1;
                int winnerIndex;
                for(int i = 0; i < numCandidates; i++) {
                    if(candidates[i]->votes > maxVotes) {
                        maxVotes = candidates[i]->votes;
                        winnerIndex = i;
                    }
                }
                printf("%s with %d votes!\n", candidates[winnerIndex]->name, candidates[winnerIndex]->votes);
                break;
                
            case 4:
                printf("Thank you for using Electronic Voting System. Goodbye!\n");
                done = 1;
                break;
                
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
    
    for(int i = 0; i < numCandidates; i++) {
        free(candidates[i]);
    }
    free(candidates);
    
    for(int i = 0; i < numVoters; i++) {
        free(voters[i]);
    }
    free(voters);
    
    return 0;
}