//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct candidate {
    int id;
    char name[50];
    int votes;
};

int main() {
    int i, total_candidates, total_votes = 0, max_votes = 0, winner_id = 0;
    
    printf("Enter the total number of candidates: ");
    scanf("%d", &total_candidates);
    
    struct candidate* candidates = (struct candidate*) malloc(total_candidates * sizeof(struct candidate));
    
    for(i = 0; i < total_candidates; i++) {
        printf("Enter the details of candidate %d - \n", i+1);
        candidates[i].id = i+1;
        printf("Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    printf("Election started!\n");
    while(1) {
        int voter_choice = 0;
        printf("Enter the ID of your candidate: ");
        scanf("%d", &voter_choice);
        
        if(voter_choice == -1) {
            printf("Election ended!\n");
            break;
        }
        else if(voter_choice < 1 || voter_choice > total_candidates) {
            printf("Invalid candidate ID. Try again.\n");
            continue;
        }
        else {
            candidates[voter_choice-1].votes++;
            total_votes++;
            printf("Your vote has been recorded for %s.\n", candidates[voter_choice-1].name);
        }
    }
    
    printf("\nTotal votes: %d\n", total_votes);
    
    printf("\n================= RESULTS =================\n");
    for(i = 0; i < total_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_id = i+1;
        }
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    
    printf("============================================\n");
    printf("The winner of the election is %s with %d votes!\n", candidates[winner_id-1].name, max_votes);
    
    free(candidates);
    return 0;
}