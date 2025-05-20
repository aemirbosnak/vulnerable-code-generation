//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char* name;
    int votes;
} Candidate;

int main() {
    Candidate candidates[5];

    // Initialize candidates
    candidates[0].name = "Candidate 1";
    candidates[0].votes = 0;

    candidates[1].name = "Candidate 2";
    candidates[1].votes = 0;

    candidates[2].name = "Candidate 3";
    candidates[2].votes = 0;

    candidates[3].name = "Candidate 4";
    candidates[3].votes = 0;

    candidates[4].name = "Candidate 5";
    candidates[4].votes = 0;

    // Voting process
    printf("Election Time!\n");
    printf("Enter your candidate name (or leave blank to finish): ");
    fgets(candidates[5].name, sizeof(candidates[5].name), stdin);

    // Count votes
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(candidates[i].name, "") == 0) {
            break;
        }

        printf("Enter number of votes for %s: ", candidates[i].name);
        scanf("%d", &candidates[i].votes);
    }

    printf("\nElection results:\n");
    printf("--------------------\n");
    printf("%s: %d votes\n", candidates[0].name, candidates[0].votes);
    printf("%s: %d votes\n", candidates[1].name, candidates[1].votes);
    printf("%s: %d votes\n", candidates[2].name, candidates[2].votes);
    printf("%s: %d votes\n", candidates[3].name, candidates[3].votes);
    printf("%s: %d votes\n", candidates[4].name, candidates[4].votes);

    return 0;
}