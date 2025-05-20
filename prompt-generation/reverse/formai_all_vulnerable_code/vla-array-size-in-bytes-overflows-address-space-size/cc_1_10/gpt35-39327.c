//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
/*Ephemeral Electronic Voting System*/
#include<stdio.h>
#include<stdlib.h>

//Function to initialize and display the candidates
void initialize_candidates(char *candidates[], int *votes, int num_cand){
    for(int i=0;i<num_cand;i++){
        printf("Enter the name of candidate #%d:\n", i+1);
        scanf("%s", candidates[i]);
        votes[i] = 0;
    }
    printf("Candidates initialized:\n");
    for(int i=0;i<num_cand;i++){
        printf("%d. %s\n", i+1, candidates[i]);
    }
}

void cast_vote(char *candidates[], int *votes, int num_cand){
    printf("Enter the number of the candidate you want to vote for:\n");
    int vote;
    scanf("%d", &vote);
    if(vote<num_cand+1 && vote>0){
        votes[vote-1]++;
        printf("You have successfully cast your vote for %s.\n", candidates[vote-1]);
    }
    else{
        printf("Invalid input! Please enter a valid candidate number.\n");
    }
}

int main(){
    //Initialize variables and arrays
    int num_cand, num_voters;
    printf("Enter the number of candidates:\n");
    scanf("%d", &num_cand);
    printf("Enter the number of voters:\n");
    scanf("%d", &num_voters);
    char *candidates[num_cand];
    int votes[num_cand];

    //Allocate memory for candidates array
    for(int i=0;i<num_cand;i++){
        candidates[i] = malloc(20*sizeof(char));
    }

    //Initialize and display the candidates
    initialize_candidates(candidates, votes, num_cand);

    //Voting process
    for(int i=0;i<num_voters;i++){
        printf("\nVoter #%d\n", i+1);
        cast_vote(candidates, votes, num_cand);
    }

    //Display results
    printf("\nElection Results\n");
    for(int i=0;i<num_cand;i++){
        printf("%s - %d votes\n", candidates[i], votes[i]);
    }

    //Free memory
    for(int i=0;i<num_cand;i++){
        free(candidates[i]);
    }

    return 0;
}