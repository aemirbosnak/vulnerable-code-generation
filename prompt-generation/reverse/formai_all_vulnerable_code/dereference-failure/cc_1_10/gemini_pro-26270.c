//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int votes;
} candidate_t;

typedef struct {
    char *name;
    candidate_t *candidates;
    int num_candidates;
} election_t;

election_t *create_election(char *name) {
    election_t *election = malloc(sizeof(election_t));
    election->name = strdup(name);
    election->candidates = NULL;
    election->num_candidates = 0;
    return election;
}

void destroy_election(election_t *election) {
    free(election->name);
    for (int i = 0; i < election->num_candidates; i++) {
        free(election->candidates[i].name);
    }
    free(election->candidates);
    free(election);
}

candidate_t *create_candidate(char *name) {
    candidate_t *candidate = malloc(sizeof(candidate_t));
    candidate->name = strdup(name);
    candidate->votes = 0;
    return candidate;
}

void destroy_candidate(candidate_t *candidate) {
    free(candidate->name);
    free(candidate);
}

void add_candidate(election_t *election, candidate_t *candidate) {
    election->candidates = realloc(election->candidates, (election->num_candidates + 1) * sizeof(candidate_t));
    election->candidates[election->num_candidates] = *candidate;
    election->num_candidates++;
}

void vote(election_t *election, char *candidate_name) {
    for (int i = 0; i < election->num_candidates; i++) {
        if (strcmp(election->candidates[i].name, candidate_name) == 0) {
            election->candidates[i].votes++;
            return;
        }
    }
    printf("Error: candidate %s not found\n", candidate_name);
}

void print_results(election_t *election) {
    printf("Election: %s\n", election->name);
    for (int i = 0; i < election->num_candidates; i++) {
        printf("Candidate: %s, Votes: %d\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

int main() {
    election_t *election = create_election("Presidential Election");

    candidate_t *candidate1 = create_candidate("Candidate 1");
    candidate_t *candidate2 = create_candidate("Candidate 2");
    candidate_t *candidate3 = create_candidate("Candidate 3");

    add_candidate(election, candidate1);
    add_candidate(election, candidate2);
    add_candidate(election, candidate3);

    vote(election, "Candidate 1");
    vote(election, "Candidate 2");
    vote(election, "Candidate 2");
    vote(election, "Candidate 3");

    print_results(election);

    destroy_candidate(candidate1);
    destroy_candidate(candidate2);
    destroy_candidate(candidate3);
    destroy_election(election);

    return 0;
}