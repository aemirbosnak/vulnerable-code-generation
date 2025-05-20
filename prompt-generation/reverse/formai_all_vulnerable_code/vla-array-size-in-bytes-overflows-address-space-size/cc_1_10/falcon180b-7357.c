//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES 10

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

void read_candidates(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters(Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            voters[i].votes[j] = 0;
        }
    }
}

void cast_vote(Voter voter, Candidate candidates[], int num_candidates) {
    printf("Enter votes for candidates (0-9): ");
    for (int i = 0; i < MAX_VOTES; i++) {
        int vote;
        scanf("%d", &vote);
        if (vote >= 0 && vote < num_candidates) {
            voter.votes[vote]++;
            candidates[vote].votes++;
        }
    }
}

void print_results(Candidate candidates[], int num_candidates) {
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    Candidate candidates[num_candidates];
    read_candidates(candidates, num_candidates);

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    Voter voters[num_voters];
    read_voters(voters, num_voters);

    for (int i = 0; i < num_voters; i++) {
        cast_vote(voters[i], candidates, num_candidates);
    }

    print_results(candidates, num_candidates);

    return 0;
}