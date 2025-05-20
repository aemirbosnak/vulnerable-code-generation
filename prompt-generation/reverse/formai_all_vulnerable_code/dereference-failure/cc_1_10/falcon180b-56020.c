//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[100];
    int votes;
} candidate;

int main() {
    system("clear");
    int num_candidates, num_voters, i, j, choice;
    char input[100];
    candidate *candidates = NULL;
    int *votes = NULL;

    printf("Welcome to the Electronic Voting System!\n\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidates = (candidate*)malloc(num_candidates * sizeof(candidate));

    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    votes = (int*)malloc(num_voters * sizeof(int));

    for (i = 0; i < num_voters; i++) {
        printf("Enter the ID of voter %d: ", i+1);
        scanf("%d", &choice);
        printf("Enter the choice of voter %d: ", i+1);
        scanf("%d", &votes[i]);
    }

    printf("\n\nVoting Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    system("clear");
    printf("Thank you for using the Electronic Voting System!\n");

    return 0;
}