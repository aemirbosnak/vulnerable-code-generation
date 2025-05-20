//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// Structure to represent the election
typedef struct Election {
    Candidate candidates[50];
    int num_candidates;
    int num_voters;
} Election;

// Function to create a new election
Election* create_election() {
    Election* election = (Election*)malloc(sizeof(Election));
    election->num_candidates = 0;
    election->num_voters = 0;
    return election;
}

// Function to add a candidate to the election
void add_candidate(Election* election, char* name) {
    strcpy(election->candidates[election->num_candidates].name, name);
    election->candidates[election->num_candidates].votes = 0;
    election->num_candidates++;
}

// Function to add a voter to the election
void add_voter(Election* election) {
    election->num_voters++;
}

// Function to vote for a candidate
void vote(Election* election, int candidate_index) {
    election->candidates[candidate_index].votes++;
}

// Function to get the winner of the election
Candidate* get_winner(Election* election) {
    int max_votes = 0;
    Candidate* winner = NULL;
    for (int i = 0; i < election->num_candidates; i++) {
        if (election->candidates[i].votes > max_votes) {
            max_votes = election->candidates[i].votes;
            winner = &election->candidates[i];
        }
    }
    return winner;
}

// Function to print the results of the election
void print_results(Election* election) {
    printf("Election Results:\n");
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
    printf("Winner: %s\n", get_winner(election)->name);
}

// Main function
int main() {
    // Create a new election
    Election* election = create_election();

    // Add candidates to the election
    add_candidate(election, "John Doe");
    add_candidate(election, "Jane Doe");
    add_candidate(election, "Bob Smith");

    // Add voters to the election
    add_voter(election);
    add_voter(election);
    add_voter(election);

    // Cast votes
    vote(election, 0);
    vote(election, 1);
    vote(election, 2);

    // Print the results of the election
    print_results(election);

    return 0;
}