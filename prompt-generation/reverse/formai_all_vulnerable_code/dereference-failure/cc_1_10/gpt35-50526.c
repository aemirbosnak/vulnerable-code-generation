//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct definition
struct candidate{
    char name[50];
    int votes;
};

//Function prototypes
void castVote();
void showResults();
void addCandidate();

int MAX_CANDIDATES = 10; //Maximum number of candidates allowed
int numCandidates = 0; //Number of candidates already added
struct candidate *candidateList; //Array of candidates

int main(){
    int choice;
    printf("Welcome to the Electronic Voting System!\n");

    //Allocating memory for the candidateList
    candidateList = (struct candidate *)malloc(sizeof(struct candidate)*MAX_CANDIDATES);

    do{
        printf("\n\nPlease select an option from the following:\n");
        printf("1. Cast your vote\n");
        printf("2. Show results\n");
        printf("3. Add a candidate\n");
        printf("4. Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                castVote();
                break;
            case 2:
                showResults();
                break;
            case 3:
                addCandidate();
                break;
            case 4:
                printf("Thank you for using our Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }while(choice!=4);

    free(candidateList); //Freeing dynamically allocated memory

    return 0;
}

//Function to cast vote
void castVote(){
    int i, vote;
    printf("\nList of candidates:\n");
    for(i=0; i<numCandidates; i++){
        printf("%d. %s\n", i+1, candidateList[i].name);
    }
    printf("Enter your vote: ");
    scanf("%d",&vote);

    //Validating user input
    if(vote<1 || vote>numCandidates){
        printf("Invalid vote, please try again.\n");
    }
    else{
        candidateList[vote-1].votes++;
        printf("Vote casted successfully!\n");
    }
}

//Function to show results
void showResults(){
    int i, j;
    struct candidate temp;

    //Bubble sort to sort candidateList in descending order of votes
    for(i=0; i<numCandidates-1; i++){
        for(j=0; j<numCandidates-i-1; j++){
            if(candidateList[j].votes<candidateList[j+1].votes){
                temp = candidateList[j];
                candidateList[j] = candidateList[j+1];
                candidateList[j+1] = temp;
            }
        }
    }

    printf("\nResults:\n");
    printf("Candidate\t\tVotes\n");
    for(i=0; i<numCandidates; i++){
        printf("%s\t\t%d\n",candidateList[i].name,candidateList[i].votes);
    }
}

//Function to add a candidate
void addCandidate(){
    if(numCandidates==MAX_CANDIDATES){
        printf("Maximum number of candidates reached!\n");
    }
    else{
        printf("Enter candidate name: ");
        scanf("%s",candidateList[numCandidates].name);
        candidateList[numCandidates].votes = 0;
        numCandidates++;
        printf("Candidate added successfully!\n");
    }
}