//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct candidate {
    char name[32];
    int votes;
} candidate_t;

// Define the structure of a voter
typedef struct voter {
    char name[32];
    int has_voted;
} voter_t;

// Define the structure of the voting system
typedef struct voting_system {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} voting_system_t;

// Create a new voting system
voting_system_t* create_voting_system(void) {
    voting_system_t* voting_system = malloc(sizeof(voting_system_t));
    if (voting_system == NULL) {
        return NULL;
    }

    voting_system->num_candidates = 0;
    voting_system->num_voters = 0;

    return voting_system;
}

// Destroy a voting system
void destroy_voting_system(voting_system_t* voting_system) {
    free(voting_system);
}

// Add a candidate to the voting system
bool add_candidate(voting_system_t* voting_system, const char* name) {
    if (voting_system->num_candidates >= MAX_CANDIDATES) {
        return false;
    }

    strcpy(voting_system->candidates[voting_system->num_candidates].name, name);
    voting_system->candidates[voting_system->num_candidates].votes = 0;
    voting_system->num_candidates++;

    return true;
}

// Add a voter to the voting system
bool add_voter(voting_system_t* voting_system, const char* name) {
    if (voting_system->num_voters >= MAX_VOTERS) {
        return false;
    }

    strcpy(voting_system->voters[voting_system->num_voters].name, name);
    voting_system->voters[voting_system->num_voters].has_voted = false;
    voting_system->num_voters++;

    return true;
}

// Vote for a candidate
bool vote(voting_system_t* voting_system, const char* voter_name, const char* candidate_name) {
    int voter_index = -1;
    int candidate_index = -1;

    // Find the voter
    for (int i = 0; i < voting_system->num_voters; i++) {
        if (strcmp(voting_system->voters[i].name, voter_name) == 0) {
            voter_index = i;
            break;
        }
    }

    // Find the candidate
    for (int i = 0; i < voting_system->num_candidates; i++) {
        if (strcmp(voting_system->candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // Check if the voter has already voted
    if (voter_index == -1 || voting_system->voters[voter_index].has_voted) {
        return false;
    }

    // Check if the candidate is valid
    if (candidate_index == -1) {
        return false;
    }

    // Increment the candidate's vote count
    voting_system->candidates[candidate_index].votes++;

    // Mark the voter as having voted
    voting_system->voters[voter_index].has_voted = true;

    return true;
}

// Get the winner of the election
const char* get_winner(voting_system_t* voting_system) {
    int max_votes = 0;
    int winner_index = -1;

    // Find the candidate with the most votes
    for (int i = 0; i < voting_system->num_candidates; i++) {
        if (voting_system->candidates[i].votes > max_votes) {
            max_votes = voting_system->candidates[i].votes;
            winner_index = i;
        }
    }

    // Return the name of the winner
    return voting_system->candidates[winner_index].name;
}

// Print the results of the election
void print_results(voting_system_t* voting_system) {
    printf("Election Results:\n");
    for (int i = 0; i < voting_system->num_candidates; i++) {
        printf("%s: %d votes\n", voting_system->candidates[i].name, voting_system->candidates[i].votes);
    }

    printf("Winner: %s\n", get_winner(voting_system));
}

// Main function
int main(void) {
    // Create a new voting system
    voting_system_t* voting_system = create_voting_system();

    // Add some candidates to the voting system
    add_candidate(voting_system, "Alice");
    add_candidate(voting_system, "Bob");
    add_candidate(voting_system, "Carol");

    // Add some voters to the voting system
    add_voter(voting_system, "John");
    add_voter(voting_system, "Mary");
    add_voter(voting_system, "Tom");

    // Let the voters vote
    vote(voting_system, "John", "Alice");
    vote(voting_system, "Mary", "Bob");
    vote(voting_system, "Tom", "Carol");

    // Print the results of the election
    print_results(voting_system);

    // Destroy the voting system
    destroy_voting_system(voting_system);

    return 0;
}