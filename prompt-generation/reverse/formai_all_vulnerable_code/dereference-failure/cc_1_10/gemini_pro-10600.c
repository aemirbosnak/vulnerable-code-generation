//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the data structure for a candidate
typedef struct {
    char name[50];
    int votes;
} candidate_t;

// Define the data structure for a voter
typedef struct {
    int id;
    int voted;
} voter_t;

// Define the data structure for the election
typedef struct {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} election_t;

// Function to create a new election
election_t* create_election() {
    election_t* election = malloc(sizeof(election_t));
    election->num_candidates = 0;
    election->num_voters = 0;
    return election;
}

// Function to add a new candidate to the election
void add_candidate(election_t* election, char* name) {
    if (election->num_candidates == MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }

    strcpy(election->candidates[election->num_candidates].name, name);
    election->candidates[election->num_candidates].votes = 0;
    election->num_candidates++;
}

// Function to add a new voter to the election
void add_voter(election_t* election, int id) {
    if (election->num_voters == MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
        return;
    }

    election->voters[election->num_voters].id = id;
    election->voters[election->num_voters].voted = 0;
    election->num_voters++;
}

// Function to vote for a candidate
void vote(election_t* election, int voter_id, int candidate_id) {
    if (voter_id < 0 || voter_id >= election->num_voters) {
        printf("Error: Invalid voter ID.\n");
        return;
    }

    if (candidate_id < 0 || candidate_id >= election->num_candidates) {
        printf("Error: Invalid candidate ID.\n");
        return;
    }

    if (election->voters[voter_id].voted) {
        printf("Error: Voter has already voted.\n");
        return;
    }

    election->candidates[candidate_id].votes++;
    election->voters[voter_id].voted = 1;
}

// Function to print the results of the election
void print_results(election_t* election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

// Main function
int main() {
    // Create a new election
    election_t* election = create_election();

    // Add some candidates to the election
    add_candidate(election, "Candidate A");
    add_candidate(election, "Candidate B");
    add_candidate(election, "Candidate C");

    // Add some voters to the election
    add_voter(election, 1);
    add_voter(election, 2);
    add_voter(election, 3);

    // Vote for some candidates
    vote(election, 1, 0);
    vote(election, 2, 1);
    vote(election, 3, 2);

    // Print the results of the election
    print_results(election);

    // Free the memory allocated for the election
    free(election);

    return 0;
}