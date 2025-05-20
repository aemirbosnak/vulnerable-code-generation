//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structure to hold candidate information
struct candidate{
    int id;
    char name[50];
    int voteCount;
};

//Function to randomly generate candidate information
void generateCandidates(struct candidate* candidates, int numCandidates){
    srand(time(0)); //seed the randomizer with current time

    for(int i=0; i<numCandidates; i++){
        candidates[i].id = i+1; //assign a unique id to candidate
        sprintf(candidates[i].name, "Candidate %d", i+1); //set candidate name
        candidates[i].voteCount = rand() % 100; //set random vote count
    }
}

//Function to display candidate information
void displayCandidates(struct candidate* candidates, int numCandidates){
    printf("\nAvailable Candidates:");
    for(int i=0; i<numCandidates; i++){
        printf("\n%d. %s (%d votes)", candidates[i].id, candidates[i].name, candidates[i].voteCount);
    }
}

int main(){
    int numCandidates;
    int voterCount;
    int* votes;
    struct candidate* candidates;

    printf("Welcome to the Electronic Voting System!");

    //Get number of candidates from user
    printf("\nEnter the number of candidates: ");
    scanf("%d", &numCandidates);

    //Allocate memory for candidates and votes
    candidates = malloc(numCandidates * sizeof(struct candidate));
    votes = calloc(numCandidates, sizeof(int));

    //Generate candidate information and display on screen
    generateCandidates(candidates, numCandidates);
    displayCandidates(candidates, numCandidates);

    //Get number of voters from user
    printf("\nEnter the number of voters: ");
    scanf("%d", &voterCount);

    //Loop through each voter and take their vote
    for(int i=0; i<voterCount; i++){
        int vote;
        printf("\nVoter %d, please enter your vote (candidate id): ", i+1);
        scanf("%d", &vote);

        //Increment vote count for selected candidate
        votes[vote-1]++;
    }

    //Display final results
    printf("\nFinal Results:");
    for(int i=0; i<numCandidates; i++){
        printf("\n%s: %d votes", candidates[i].name, votes[i]);
    }

    //Free memory
    free(candidates);
    free(votes);

    printf("\nThank you for using the Electronic Voting System!");

    return 0;
}