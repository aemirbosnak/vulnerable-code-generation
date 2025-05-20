//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* party;
} Candidate;

typedef struct {
    char* name;
    int age;
} Voter;

int main() {
    Candidate* candidates = NULL;
    Voter* voters = NULL;
    int num_candidates = 0;
    int num_voters = 0;

    candidates = (Candidate*)malloc(sizeof(Candidate));
    candidates[num_candidates].name = "John Doe";
    candidates[num_candidates].party = "Democrat";
    num_candidates++;

    candidates = (Candidate*)malloc(sizeof(Candidate));
    candidates[num_candidates].name = "Jane Smith";
    candidates[num_candidates].party = "Republican";
    num_candidates++;

    candidates = (Candidate*)malloc(sizeof(Candidate));
    candidates[num_candidates].name = "Bob Johnson";
    candidates[num_candidates].party = "Independent";
    num_candidates++;

    voters = (Voter*)malloc(sizeof(Voter));
    voters[num_voters].name = "Alice";
    voters[num_voters].age = 25;
    num_voters++;

    voters = (Voter*)malloc(sizeof(Voter));
    voters[num_voters].name = "Bob";
    voters[num_voters].age = 30;
    num_voters++;

    voters = (Voter*)malloc(sizeof(Voter));
    voters[num_voters].name = "Charlie";
    voters[num_voters].age = 35;
    num_voters++;

    printf("Candidates: ");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %s\n", candidates[i].name, candidates[i].party);
    }

    printf("Voters: ");
    for (int i = 0; i < num_voters; i++) {
        printf("%s - %d\n", voters[i].name, voters[i].age);
    }

    free(candidates);
    free(voters);

    return 0;
}