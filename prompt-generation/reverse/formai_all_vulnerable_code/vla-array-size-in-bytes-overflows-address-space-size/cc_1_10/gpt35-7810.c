//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

int main() {
    int num_candidates, num_voters, voter_id, i, j;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate candidates[num_candidates];

    for(i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    int voted[num_voters];

    for(i = 0; i < num_voters; i++) {
        voted[i] = 0;
    }

    for(i = 0; i < num_voters; i++) {
        printf("Enter the voter ID: ");
        scanf("%d", &voter_id);

        if(voted[voter_id-1] == 1) {
            printf("You have already voted!\n");
            i--;
            continue;
        }

        printf("Candidates:\n");
        for(j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        candidates[choice-1].votes++;
        voted[voter_id-1] = 1;
    }

    printf("\nResults:\n");
    for(i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}