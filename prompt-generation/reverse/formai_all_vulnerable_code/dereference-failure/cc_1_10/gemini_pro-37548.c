//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
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
} Candidate;

// Define the data structure for a voter
typedef struct {
    int id;
    int voted_for;
} Voter;

// Define the data structure for the election results
typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} Election;

// Function to create a new election
Election *new_election() {
    Election *election = malloc(sizeof(Election));
    election->num_candidates = 0;
    election->num_voters = 0;
    return election;
}

// Function to add a candidate to the election
void add_candidate(Election *election, Candidate candidate) {
    election->candidates[election->num_candidates] = candidate;
    election->num_candidates++;
}

// Function to add a voter to the election
void add_voter(Election *election, Voter voter) {
    election->voters[election->num_voters] = voter;
    election->num_voters++;
}

// Function to conduct the election
void conduct_election(Election *election) {
    for (int i = 0; i < election->num_voters; i++) {
        Candidate candidate = election->candidates[election->voters[i].voted_for];
        candidate.votes++;
    }
}

// Function to print the election results
void print_results(Election *election) {
    for (int i = 0; i < election->num_candidates; i++) {
        Candidate candidate = election->candidates[i];
        printf("%s: %d votes\n", candidate.name, candidate.votes);
    }
}

// Main function
int main() {
    // Create a new election
    Election *election = new_election();

    // Add candidates to the election
    Candidate candidate1 = {"John Doe", 0};
    Candidate candidate2 = {"Jane Doe", 0};
    Candidate candidate3 = {"Bob Smith", 0};
    add_candidate(election, candidate1);
    add_candidate(election, candidate2);
    add_candidate(election, candidate3);

    // Add voters to the election
    Voter voter1 = {1, 0};
    Voter voter2 = {2, 1};
    Voter voter3 = {3, 2};
    add_voter(election, voter1);
    add_voter(election, voter2);
    add_voter(election, voter3);

    // Conduct the election
    conduct_election(election);

    // Print the election results
    print_results(election);

    return 0;
}