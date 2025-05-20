//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define VOTE_LENGTH 10

typedef struct {
    char name[VOTE_LENGTH];
    int vote[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[VOTE_LENGTH];
    int votes;
} Candidate;

void read_candidates(Candidate candidates[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_votes(Voter voters[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            printf("Enter vote for candidate %d: ", j+1);
            scanf("%d", &voters[i].vote[j]);
        }
    }
}

void count_votes(Candidate candidates[], Voter voters[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            if (voters[i].vote[j] == 1) {
                candidates[j].votes++;
            }
        }
    }
}

void print_results(Candidate candidates[], int n) {
    printf("Election Results:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int n;
    printf("Enter number of candidates: ");
    scanf("%d", &n);
    Candidate candidates[n];
    read_candidates(candidates, n);

    int m;
    printf("Enter number of voters: ");
    scanf("%d", &m);
    Voter voters[m];
    read_votes(voters, m);

    count_votes(candidates, voters, m);

    print_results(candidates, n);

    return 0;
}