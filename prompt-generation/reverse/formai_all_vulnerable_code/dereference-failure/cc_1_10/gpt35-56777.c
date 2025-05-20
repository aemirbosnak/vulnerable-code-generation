//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate{
    char name[50];
    int id;
    int votes;
};

int main(){
    int num_candidates;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate *candidates = malloc(num_candidates * sizeof(struct candidate));

    // Input candidate details
    for(int i=0; i<num_candidates; i++){
        printf("Enter Candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }

    // Voting starts
    while(1){
        int voter_id;
        printf("Enter Voter ID (enter 0 to stop voting): ");
        scanf("%d", &voter_id);
        if(voter_id == 0){
            break;
        }

        if(voter_id <= 100 && voter_id >= 1){
            printf("Select a candidate:\n");
            for(int i=0; i<num_candidates; i++){
                printf("%d. %s\n", i+1, candidates[i].name);
            }
            int candidate_id;
            printf("Enter Candidate ID: ");
            scanf("%d", &candidate_id);
            if(candidate_id <= num_candidates && candidate_id >= 1){
                candidates[candidate_id-1].votes++;
                printf("Vote casted successfully!\n");
            } else{
                printf("Invalid candidate ID.\n");
            }
        } else{
            printf("Invalid voter ID.\n");
        }
    }

    // Display results
    printf("Election results:\n");
    for(int i=0; i<num_candidates; i++){
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }

    free(candidates); // free allocated memory

    return 0;
}