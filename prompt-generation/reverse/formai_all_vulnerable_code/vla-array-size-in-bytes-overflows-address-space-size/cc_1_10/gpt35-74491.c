//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <string.h>

struct candidate {
    char* name;
    int votes;
};

int main() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate candidates[num_candidates];
    for(int i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        char name[20];
        scanf("%s", name);
        candidates[i].name = strdup(name);
        candidates[i].votes = 0;
    }

    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    int votes[num_voters];
    for(int i=0; i<num_voters; i++) {
        printf("Select a candidate from 1 to %d: ", num_candidates);
        int choice;
        scanf("%d", &choice);
        if(choice < 1 || choice > num_candidates) {
            printf("Invalid choice. Please select a candidate from 1 to %d.\n", num_candidates);
            i--;
        } else {
            votes[i] = choice-1;
            candidates[choice-1].votes++;
            printf("Your vote has been recorded for %s.\n", candidates[choice-1].name);
        }
    }

    printf("----- RESULTS -----\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int winner = 0;
    for(int i=1; i<num_candidates; i++) {
        if(candidates[i].votes > candidates[winner].votes) {
            winner = i;
        } else if (candidates[i].votes == candidates[winner].votes) {
            printf("There is a tie between %s and %s!\n", candidates[i].name, candidates[winner].name);
            return 0;
        }
    }

    printf("The winner is %s with %d votes!\n", candidates[winner].name, candidates[winner].votes);

    return 0;
}