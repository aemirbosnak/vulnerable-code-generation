//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

//structure to store candidate information
typedef struct candidate {
    char name[30];
    int votes;
} Candidate;

void print_vote_count(Candidate* candidates, int num_candidates) {
    printf("Vote count:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void cast_vote(Candidate* candidates, int num_candidates, int* voter_count) {
    printf("Enter candidate name: ");
    char candidate_name[30];
    scanf("%s", &candidate_name);
    int candidate_index = -1;
    for(int i=0; i<num_candidates; i++) {
        if(strcmp(candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }
    if(candidate_index == -1) {
        printf("Invalid candidate name\n");
        return;
    }
    candidates[candidate_index].votes++;
    (*voter_count)++;
    printf("Vote casted successfully!\n");
}

void print_candidate_list(Candidate* candidates, int num_candidates) {
    printf("Candidate List:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    Candidate* candidates = (Candidate*) malloc(num_candidates * sizeof(Candidate));
    for(int i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int voter_count = 0;
    while(1) {
        printf("\n");
        printf("=======================\n");
        printf("Electronic Voting System\n");
        printf("=======================\n");
        printf("1. Cast a vote\n");
        printf("2. View vote count\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                cast_vote(candidates, num_candidates, &voter_count);
                break;
            case 2:
                print_vote_count(candidates, num_candidates);
                break;
            case 3:
                printf("Thank you for using Electronic Voting System!\n");
                printf("Total number of votes casted: %d\n", voter_count);
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    free(candidates);
    return 0;
}