//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTE_LENGTH 100

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote;
} Voter;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} Candidate;

int main() {
    srand(time(NULL));
    char *candidates[MAX_CANDIDATES] = {"Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Helen", "Ivan", "Jack"};
    int num_candidates = sizeof(candidates)/sizeof(candidates[0]);
    Candidate *candidate_list = malloc(num_candidates * sizeof(Candidate));
    for (int i = 0; i < num_candidates; i++) {
        strcpy(candidate_list[i].name, candidates[i]);
        candidate_list[i].votes = 0;
    }
    int num_voters = rand() % MAX_VOTERS + 1;
    Voter *voter_list = malloc(num_voters * sizeof(Voter));
    for (int i = 0; i < num_voters; i++) {
        strcpy(voter_list[i].name, "Voter ");
        int rand_index = rand() % num_candidates;
        strcat(voter_list[i].name, candidates[rand_index]);
        voter_list[i].vote = rand() % num_candidates + 1;
    }
    int *votes = malloc(num_candidates * sizeof(int));
    for (int i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }
    for (int i = 0; i < num_voters; i++) {
        int index = rand() % num_candidates;
        votes[index]++;
    }
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidate_list[i].name, votes[i]);
    }
    printf("Total votes: %d\n", num_voters);
    return 0;
}