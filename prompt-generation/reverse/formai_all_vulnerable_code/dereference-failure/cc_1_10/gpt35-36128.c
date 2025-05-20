//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

//Structure for storing candidate information
struct candidate {
    char name[50];
    int id;
    int votes;
};

//Function for casting votes
void castVote(struct candidate candidates[], int totalCandidates) {
    int voterID, candidateID;
    printf("\nEnter your voter ID: ");
    scanf("%d", &voterID);
    
    //Checking if the voter has already casted the vote
    char fileName[20];
    sprintf(fileName, "%d.txt", voterID);
    FILE *file = fopen(fileName, "r");
    if(file) {
        printf("\nYou have already casted your vote.");
        fclose(file);
        return;
    } else {
        file = fopen(fileName, "w");
        fclose(file);
    }
    
    //Displaying list of candidates
    printf("\nList of candidates:");
    for(int i=0; i<totalCandidates; i++) {
        printf("\n%d. %s", candidates[i].id, candidates[i].name);
    }
    
    printf("\nEnter the ID of candidate you want to vote for: ");
    scanf("%d", &candidateID);
    for(int i=0; i<totalCandidates; i++) {
        if(candidates[i].id == candidateID) {
            candidates[i].votes++;
            printf("\nThank you for casting your vote.");
            return;
        }
    }
    printf("\nInvalid candidate ID.");
}

//Function for displaying voting result
void displayResult(struct candidate candidates[], int totalCandidates) {
    int maxVotes = -1, winnerIndex = -1;
    for(int i=0; i<totalCandidates; i++) {
        if(candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes; 
            winnerIndex = i;
        }
    }
    printf("\nTotal votes casted: %d", totalCandidates);
    
    if(winnerIndex == -1) {
        printf("\nNo votes were casted.");
    } else {
        printf("\nWinner: %s", candidates[winnerIndex].name);
        printf("\nNumber of votes received: %d", candidates[winnerIndex].votes);
    }
}

int main() {
    int totalCandidates;
    printf("\nEnter total number of candidates: ");
    scanf("%d", &totalCandidates);
    
    //Allocating memory for candidates
    struct candidate *candidates = (struct candidate*) malloc(totalCandidates * sizeof(struct candidate));
    
    //Taking information for each candidate
    for(int i=0; i<totalCandidates; i++) {
        printf("\nEnter name for candidate %d: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }
    
    //Displaying Menu
    int choice;
    do {
        printf("\n\nPress 1 to cast a vote.");
        printf("\nPress 2 to display voting result.");
        printf("\nPress 3 to exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: castVote(candidates, totalCandidates);
                    break;
            case 2: displayResult(candidates, totalCandidates);
                    break;
            case 3: printf("\nGoodbye!");
                    break;
            default: printf("\nInvalid choice.");
                    break;
        }
    } while(choice != 3);
    
    free(candidates);
    return 0;
}