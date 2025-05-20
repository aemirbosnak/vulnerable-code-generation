//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char name[100];
    int votes;
} candidate;

int main() {
    int num_candidates, i, voter_choice;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    candidate candidates[num_candidates];
    for(i=0; i<num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    printf("Thank you. %d candidates added to the system.\n", num_candidates);
    printf("Please enter the number of voters: ");
    int num_voters;
    scanf("%d", &num_voters);
    if(num_voters <= 0) {
        printf("Invalid number of voters. Program closing.\n");
        exit(0);
    }
    printf("Thank you. %d voters added.\n", num_voters);
    for(i=0; i<num_voters; i++) {
        printf("Voter %d, please choose your candidate:\n", i+1);
        for(int j=0; j<num_candidates; j++) {
            printf("%d: %s\n", j+1, candidates[j].name);
        }
        printf("Enter your choice: ");
        scanf("%d", &voter_choice);
        if(voter_choice < 1 || voter_choice > num_candidates) {
            printf("Invalid choice entered. Your vote will not be counted.\n");
        } else {
            candidates[voter_choice-1].votes++;
            printf("Thank you for voting.\n");
        }
    }
    printf("Voting is now closed. Here are the results:\n");
    for(i=0; i<num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
    int max_votes = candidates[0].votes;
    for(i=1; i<num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    int num_winners = 0;
    for(i=0; i<num_candidates; i++) {
        if(candidates[i].votes == max_votes) {
            num_winners++;
        }
    }
    if(num_winners == 1) {
        printf("%s is the winner with %d votes!\n", candidates[i].name, max_votes);
    } else {
        printf("There is a tie between the following candidates:\n");
        for(i=0; i<num_candidates; i++) {
            if(candidates[i].votes == max_votes) {
                printf("%s ", candidates[i].name);
            }
        }
        printf("\n");
    }
    return 0;
}