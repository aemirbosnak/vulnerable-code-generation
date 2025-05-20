//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*This program simulates an electronic voting system*/

int main(){
    int i, n, candidates, choice, max_votes=0, winner;
    srand(time(NULL)); //initialize random seed

    printf("Welcome to the Electronic Voting System\n\n");

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    char names[candidates][20];
    int votes[candidates];

    //get names of candidates
    for(i=0; i<candidates; i++){
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", names[i]);
        votes[i] = 0; //initialize votes to zero
    }

    printf("\nEnter number of voters: ");
    scanf("%d", &n);

    printf("\nVoting starts in 3 seconds.....\n\n");

    //simulate voting process
    for(i=1; i<=n; i++){
        printf("Voter %d please make your choice:\n", i);
        for(int j=0; j<candidates; j++){
            printf("%d - %s\n", j+1, names[j]);
        }
        printf("\nChoice: ");
        choice = rand() % candidates + 1; //generate random choice
        printf("%d\n\n", choice);

        votes[choice-1]++; //increment vote of chosen candidate
    }

    //get winner
    for(i=0; i<candidates; i++){
        if(votes[i] > max_votes){
            max_votes = votes[i];
            winner = i;
        }
    }

    printf("Voting has ended and the winner is %s with %d votes\n", names[winner], max_votes);

    //print vote results
    printf("\nVote Results:\n");
    for(i=0; i<candidates; i++){
        printf("%s - %d votes\n", names[i], votes[i]);
    }

    return 0;
}