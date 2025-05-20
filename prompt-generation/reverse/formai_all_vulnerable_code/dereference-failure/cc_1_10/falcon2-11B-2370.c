//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char* name;
    int votes;
} Candidate;

typedef struct {
    Candidate* candidates;
    int num_candidates;
} VotingSystem;

void add_candidate(VotingSystem* voting_system, char* name) {
    Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));
    new_candidate->name = strdup(name);
    new_candidate->votes = 0;

    voting_system->candidates = (Candidate*)realloc(voting_system->candidates, (voting_system->num_candidates + 1) * sizeof(Candidate));
    voting_system->candidates[voting_system->num_candidates] = *new_candidate;

    voting_system->num_candidates++;
}

void vote(VotingSystem* voting_system, char* candidate_name) {
    int i;

    for (i = 0; i < voting_system->num_candidates; i++) {
        if (strcmp(voting_system->candidates[i].name, candidate_name) == 0) {
            voting_system->candidates[i].votes++;
            break;
        }
    }
}

int main() {
    VotingSystem voting_system;
    char* candidate_names[3] = {"John Doe", "Jane Smith", "Bob Johnson"};
    char* candidates[3] = {"John Doe", "Jane Smith", "Bob Johnson"};
    int num_candidates = sizeof(candidates) / sizeof(candidates[0]);

    voting_system.num_candidates = num_candidates;
    voting_system.candidates = (Candidate*)malloc(num_candidates * sizeof(Candidate));

    for (int i = 0; i < num_candidates; i++) {
        add_candidate(&voting_system, candidates[i]);
    }

    printf("Please select a candidate to vote for:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, voting_system.candidates[i].name, voting_system.candidates[i].votes);
    }

    int choice;
    printf("Enter the number corresponding to the candidate you wish to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice.\n");
        return 1;
    }

    vote(&voting_system, voting_system.candidates[choice-1].name);

    printf("%s has been voted for!\n", voting_system.candidates[choice-1].name);

    return 0;
}