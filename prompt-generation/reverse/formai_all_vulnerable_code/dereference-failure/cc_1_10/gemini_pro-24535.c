//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct Candidate {
    char *name;
    int votes;
};

struct Election {
    struct Candidate **candidates;
    int num_candidates;
    int num_voters;
};

struct Voter {
    int id;
    int vote;
};

// Create a new election
struct Election *create_election(int num_candidates) {
    struct Election *election = malloc(sizeof(struct Election));
    election->candidates = malloc(sizeof(struct Candidate *) * num_candidates);
    election->num_candidates = num_candidates;
    election->num_voters = 0;
    return election;
}

// Add a candidate to the election
void add_candidate(struct Election *election, struct Candidate *candidate) {
    election->candidates[election->num_candidates] = candidate;
    election->num_candidates++;
}

// Add a voter to the election
void add_voter(struct Election *election, struct Voter *voter) {
    election->num_voters++;
}

// Cast a vote for a candidate
void cast_vote(struct Election *election, int voter_id, int candidate_id) {
    election->candidates[candidate_id]->votes++;
}

// Get the winner of the election
struct Candidate *get_winner(struct Election *election) {
    int max_votes = 0;
    struct Candidate *winner = NULL;
    for (int i = 0; i < election->num_candidates; i++) {
        if (election->candidates[i]->votes > max_votes) {
            max_votes = election->candidates[i]->votes;
            winner = election->candidates[i];
        }
    }
    return winner;
}

// Print the results of the election
void print_results(struct Election *election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i]->name, election->candidates[i]->votes);
    }
    printf("Winner: %s\n", get_winner(election)->name);
}

// Free the memory allocated for the election
void free_election(struct Election *election) {
    for (int i = 0; i < election->num_candidates; i++) {
        free(election->candidates[i]);
    }
    free(election->candidates);
    free(election);
}

int main() {
    // Create a new election
    struct Election *election = create_election(3);

    // Add candidates to the election
    struct Candidate *candidate1 = malloc(sizeof(struct Candidate));
    candidate1->name = "Candidate 1";
    candidate1->votes = 0;
    add_candidate(election, candidate1);

    struct Candidate *candidate2 = malloc(sizeof(struct Candidate));
    candidate2->name = "Candidate 2";
    candidate2->votes = 0;
    add_candidate(election, candidate2);

    struct Candidate *candidate3 = malloc(sizeof(struct Candidate));
    candidate3->name = "Candidate 3";
    candidate3->votes = 0;
    add_candidate(election, candidate3);

    // Add voters to the election
    struct Voter *voter1 = malloc(sizeof(struct Voter));
    voter1->id = 1;
    voter1->vote = 0;
    add_voter(election, voter1);

    struct Voter *voter2 = malloc(sizeof(struct Voter));
    voter2->id = 2;
    voter2->vote = 1;
    add_voter(election, voter2);

    struct Voter *voter3 = malloc(sizeof(struct Voter));
    voter3->id = 3;
    voter3->vote = 2;
    add_voter(election, voter3);

    // Cast votes
    cast_vote(election, 1, 0);
    cast_vote(election, 2, 1);
    cast_vote(election, 3, 2);

    // Print the results of the election
    print_results(election);

    // Free the memory allocated for the election
    free_election(election);

    return 0;
}