//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char *name;
    int votes;
} candidate_t;

typedef struct election {
    candidate_t *candidates;
    int num_candidates;
} election_t;

void print_candidate(candidate_t *candidate) {
    printf("%s: %d votes\n", candidate->name, candidate->votes);
}

void print_election(election_t *election) {
    for (int i = 0; i < election->num_candidates; i++) {
        print_candidate(&election->candidates[i]);
    }
}

void cast_vote(election_t *election, int candidate_index) {
    if (candidate_index < 0 || candidate_index >= election->num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    election->candidates[candidate_index].votes++;
}

int main() {
    // Initialize the election
    election_t election = {
        .candidates = NULL,
        .num_candidates = 0
    };

    // Add some candidates
    election.candidates = realloc(election.candidates, sizeof(candidate_t) * 3);
    election.candidates[0] = (candidate_t) { .name = "Max", .votes = 0 };
    election.candidates[1] = (candidate_t) { .name = "Furiosa", .votes = 0 };
    election.candidates[2] = (candidate_t) { .name = "Immortan Joe", .votes = 0 };
    election.num_candidates = 3;

    // Print the candidates
    printf("Candidates:\n");
    print_election(&election);

    // Cast some votes
    cast_vote(&election, 0); // Vote for Max
    cast_vote(&election, 1); // Vote for Furiosa
    cast_vote(&election, 2); // Vote for Immortan Joe

    // Print the results
    printf("\nResults:\n");
    print_election(&election);

    return 0;
}