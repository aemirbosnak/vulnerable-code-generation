//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[30];
    int vote_count;
};

int main() {
    int num_candidates, num_voters, vote;
    char voter_id[10];
    
    //Get number of candidates and create array of candidate structures
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    struct candidate candidates[num_candidates];
    
    //Get candidate names and initialize vote count to 0
    for(int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }
    
    //Get number of voters and initialize array to track votes
    printf("\nEnter number of voters: ");
    scanf("%d", &num_voters);
    int votes[num_voters];
    
    //Loop through each voter and record their vote
    for(int i = 0; i < num_voters; i++) {
        printf("\nEnter voter ID: ");
        scanf("%s", voter_id);
        printf("Enter vote (1-%d): ", num_candidates);
        scanf("%d", &vote);
        
        //Check if vote is valid and record it
        if(vote >= 1 && vote <= num_candidates) {
            votes[i] = vote;
            printf("Vote recorded successfully!\n");
        } else {
            printf("Invalid vote, please try again.\n");
            i--; //decrement i to repeat current iteration
        }
    }
    
    //Count the votes
    for(int i = 0; i < num_voters; i++) {
        candidates[votes[i]-1].vote_count++;
    }
    
    //Display the results
    printf("\nElection Results:\n");
    printf("==================\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].vote_count);
    }
    
    //Find the winner(s)
    int max_votes = 0;
    for(int i = 0; i < num_candidates; i++) {
        if(candidates[i].vote_count > max_votes) {
            max_votes = candidates[i].vote_count;
        }
    }
    printf("\nWinner(s):\n");
    for(int i = 0; i < num_candidates; i++) {
        if(candidates[i].vote_count == max_votes) {
            printf("- %s\n", candidates[i].name);
        }
    }
    
    return 0;
}