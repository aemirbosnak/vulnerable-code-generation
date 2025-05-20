//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and the maximum length of a candidate's name
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 25

// Define the structure of a candidate
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// Define the structure of the voting system
typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int num_voters;
} VotingSystem;

// Create a new voting system
VotingSystem* create_voting_system() {
    VotingSystem* voting_system = malloc(sizeof(VotingSystem));
    voting_system->num_candidates = 0;
    voting_system->num_voters = 0;
    return voting_system;
}

// Add a candidate to the voting system
void add_candidate(VotingSystem* voting_system, char* name) {
    strcpy(voting_system->candidates[voting_system->num_candidates].name, name);
    voting_system->candidates[voting_system->num_candidates].votes = 0;
    voting_system->num_candidates++;
}

// Cast a vote for a candidate
void cast_vote(VotingSystem* voting_system, char* name) {
    for (int i = 0; i < voting_system->num_candidates; i++) {
        if (strcmp(voting_system->candidates[i].name, name) == 0) {
            voting_system->candidates[i].votes++;
            voting_system->num_voters++;
            return;
        }
    }
    printf("Invalid candidate name: %s\n", name);
}

// Get the winner of the election
Candidate* get_winner(VotingSystem* voting_system) {
    Candidate* winner = NULL;
    int max_votes = 0;
    for (int i = 0; i < voting_system->num_candidates; i++) {
        if (voting_system->candidates[i].votes > max_votes) {
            winner = &voting_system->candidates[i];
            max_votes = voting_system->candidates[i].votes;
        }
    }
    return winner;
}

// Print the results of the election
void print_results(VotingSystem* voting_system) {
    printf("Election results:\n");
    for (int i = 0; i < voting_system->num_candidates; i++) {
        printf("%s: %d votes\n", voting_system->candidates[i].name, voting_system->candidates[i].votes);
    }
    Candidate* winner = get_winner(voting_system);
    printf("Winner: %s\n", winner->name);
}

// Free the memory allocated for the voting system
void free_voting_system(VotingSystem* voting_system) {
    free(voting_system);
}

// Main function
int main() {
    // Create a new voting system
    VotingSystem* voting_system = create_voting_system();

    // Add candidates to the voting system
    add_candidate(voting_system, "Alice");
    add_candidate(voting_system, "Bob");
    add_candidate(voting_system, "Carol");

    // Cast votes for the candidates
    cast_vote(voting_system, "Alice");
    cast_vote(voting_system, "Bob");
    cast_vote(voting_system, "Carol");
    cast_vote(voting_system, "Alice");

    // Print the results of the election
    print_results(voting_system);

    // Free the memory allocated for the voting system
    free_voting_system(voting_system);

    return 0;
}