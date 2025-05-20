//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the maximum number of votes per candidate
#define MAX_VOTES_PER_CANDIDATE 100

// Define the structure of a candidate
struct Candidate {
    char name[50];
    int votes;
};

// Define the structure of the voting system
struct VotingSystem {
    struct Candidate candidates[NUM_CANDIDATES];
    int num_votes_cast;
};

// Create a new voting system
struct VotingSystem* create_voting_system() {
    struct VotingSystem* voting_system = malloc(sizeof(struct VotingSystem));
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        strcpy(voting_system->candidates[i].name, "");
        voting_system->candidates[i].votes = 0;
    }
    voting_system->num_votes_cast = 0;
    return voting_system;
}

// Add a candidate to the voting system
void add_candidate(struct VotingSystem* voting_system, char* name) {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (strcmp(voting_system->candidates[i].name, "") == 0) {
            strcpy(voting_system->candidates[i].name, name);
            break;
        }
    }
}

// Cast a vote for a candidate
void cast_vote(struct VotingSystem* voting_system, char* name) {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (strcmp(voting_system->candidates[i].name, name) == 0) {
            voting_system->candidates[i].votes++;
            voting_system->num_votes_cast++;
            break;
        }
    }
}

// Get the winner of the election
struct Candidate* get_winner(struct VotingSystem* voting_system) {
    struct Candidate* winner = NULL;
    int max_votes = 0;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (voting_system->candidates[i].votes > max_votes) {
            winner = &voting_system->candidates[i];
            max_votes = voting_system->candidates[i].votes;
        }
    }
    return winner;
}

// Print the results of the election
void print_results(struct VotingSystem* voting_system) {
    printf("Election Results:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", voting_system->candidates[i].name, voting_system->candidates[i].votes);
    }
    struct Candidate* winner = get_winner(voting_system);
    printf("Winner: %s\n", winner->name);
}

// Main function
int main() {
    // Create a new voting system
    struct VotingSystem* voting_system = create_voting_system();

    // Add candidates to the voting system
    add_candidate(voting_system, "Alice");
    add_candidate(voting_system, "Bob");
    add_candidate(voting_system, "Charlie");
    add_candidate(voting_system, "Dave");
    add_candidate(voting_system, "Eve");

    // Cast votes for candidates
    cast_vote(voting_system, "Alice");
    cast_vote(voting_system, "Bob");
    cast_vote(voting_system, "Charlie");
    cast_vote(voting_system, "Dave");
    cast_vote(voting_system, "Eve");

    // Print the results of the election
    print_results(voting_system);

    return 0;
}