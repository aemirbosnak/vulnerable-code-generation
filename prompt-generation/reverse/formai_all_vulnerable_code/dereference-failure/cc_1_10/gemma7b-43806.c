//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void initialize_candidates(Candidate *candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }
}

void vote(Candidate *candidates, int num_candidates, char voter_choice) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, voter_choice) == 0) {
            candidates[i].votes++;
            break;
        }
    }
}

void print_results(Candidate *candidates, int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\nThe winner is: %s\n", candidates[0].name);
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    initialize_candidates(candidates, MAX_CANDIDATES);

    char voter_choice;
    printf("Enter your vote:");
    scanf(" %c", &voter_choice);

    vote(candidates, MAX_CANDIDATES, voter_choice);

    print_results(candidates, MAX_CANDIDATES);

    return 0;
}