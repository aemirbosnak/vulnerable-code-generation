//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>

struct candidate {
    int candidate_id;
    char name[50];
    int vote_count;
};

int main() {
    int num_candidates;
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    struct candidate candidates[num_candidates];
    
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter ID for candidate %d: ", i+1);
        scanf("%d", &candidates[i].candidate_id);
        
        printf("Enter name for candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        
        candidates[i].vote_count = 0;
    }
    
    printf("Voting is now open!\n");
    
    int voter_id;
    int candidate_id;
    
    while (1) {
        printf("Enter your voter ID (or enter -1 to exit): ");
        scanf("%d", &voter_id);
        if (voter_id == -1) break;
        
        printf("Here are the candidates:\n");
        for (int i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", candidates[i].candidate_id, candidates[i].name);
        }
        
        printf("Enter the candidate ID you want to vote for: ");
        scanf("%d", &candidate_id);
        
        for (int i = 0; i < num_candidates; i++) {
            if (candidates[i].candidate_id == candidate_id) {
                candidates[i].vote_count++;
                printf("Thank you for voting for %s!\n", candidates[i].name);
                break;
            }
        }
    }
    
    printf("Voting is now closed.\n");
    
    printf("Here are the final results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    
    return 0;
}