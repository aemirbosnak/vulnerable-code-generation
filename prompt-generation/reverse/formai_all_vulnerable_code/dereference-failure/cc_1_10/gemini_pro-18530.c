//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the data structure for a candidate
typedef struct {
    char name[50];
    int votes;
} candidate_t;

// Define the data structure for a voter
typedef struct {
    char name[50];
    int has_voted;
} voter_t;

// Define the data structure for the election
typedef struct {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} election_t;

// Create a new election
election_t *create_election() {
    election_t *election = malloc(sizeof(election_t));
    election->num_candidates = 0;
    election->num_voters = 0;
    return election;
}

// Add a candidate to the election
void add_candidate(election_t *election, char *name) {
    if (election->num_candidates < MAX_CANDIDATES) {
        strcpy(election->candidates[election->num_candidates].name, name);
        election->candidates[election->num_candidates].votes = 0;
        election->num_candidates++;
    }
}

// Add a voter to the election
void add_voter(election_t *election, char *name) {
    if (election->num_voters < MAX_VOTERS) {
        strcpy(election->voters[election->num_voters].name, name);
        election->voters[election->num_voters].has_voted = 0;
        election->num_voters++;
    }
}

// Print the candidates in the election
void print_candidates(election_t *election) {
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%d. %s\n", i + 1, election->candidates[i].name);
    }
}

// Print the voters in the election
void print_voters(election_t *election) {
    for (int i = 0; i < election->num_voters; i++) {
        printf("%d. %s\n", i + 1, election->voters[i].name);
    }
}

// Vote for a candidate in the election
void vote(election_t *election, int candidate_index, int voter_index) {
    if (election->voters[voter_index].has_voted == 0) {
        election->candidates[candidate_index].votes++;
        election->voters[voter_index].has_voted = 1;
    }
}

// Get the winner of the election
candidate_t *get_winner(election_t *election) {
    int max_votes = 0;
    candidate_t *winner = NULL;
    for (int i = 0; i < election->num_candidates; i++) {
        if (election->candidates[i].votes > max_votes) {
            max_votes = election->candidates[i].votes;
            winner = &election->candidates[i];
        }
    }
    return winner;
}

// Print the results of the election
void print_results(election_t *election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
    candidate_t *winner = get_winner(election);
    printf("Winner: %s\n", winner->name);
}

// Free the memory allocated for the election
void free_election(election_t *election) {
    free(election);
}

int main() {
    // Create a new election
    election_t *election = create_election();

    // Add candidates to the election
    add_candidate(election, "Alice");
    add_candidate(election, "Bob");
    add_candidate(election, "Carol");

    // Add voters to the election
    add_voter(election, "John");
    add_voter(election, "Mary");
    add_voter(election, "Peter");

    // Print the candidates in the election
    printf("Candidates:\n");
    print_candidates(election);

    // Print the voters in the election
    printf("\nVoters:\n");
    print_voters(election);

    // Vote for a candidate in the election
    vote(election, 0, 0);
    vote(election, 1, 1);
    vote(election, 2, 2);

    // Print the results of the election
    printf("\nResults:\n");
    print_results(election);

    // Free the memory allocated for the election
    free_election(election);

    return 0;
}