//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char* name;
    int votes;
} Candidate;

typedef struct Election {
    Candidate* candidates;
    int num_candidates;
} Election;

void printCandidates(Election* election) {
    printf("Candidates:\n");
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

void addCandidate(Election* election, char* name) {
    Candidate new_candidate = {name, 0};
    if (election->num_candidates < 10) {
        election->candidates = (Candidate*)realloc(election->candidates, (election->num_candidates + 1) * sizeof(Candidate));
        election->candidates[election->num_candidates] = new_candidate;
        election->num_candidates++;
    } else {
        printf("Cannot add more than 10 candidates.\n");
    }
}

void printElection(Election* election) {
    printf("Election:\n");
    printf("Candidates:\n");
    printCandidates(election);
    printf("Total votes: %d\n", election->num_candidates * 10);
}

int main() {
    Election election;
    election.num_candidates = 0;
    char* candidates[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    for (int i = 0; i < 10; i++) {
        addCandidate(&election, candidates[i]);
    }
    printElection(&election);
    printf("\n");
    int votes[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int total_votes = 0;
    for (int i = 0; i < 10; i++) {
        total_votes += votes[i];
        printf("Vote for %s: ", election.candidates[i].name);
        scanf("%d", &election.candidates[i].votes);
    }
    printf("\n");
    printElection(&election);
    printf("\n");
    return 0;
}