//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates and votes
#define MAX_CANDIDATES 10
#define MAX_VOTES 100

// Define the candidate struct
typedef struct candidate {
    char *name;
    int votes;
} candidate_t;

// Define the voting system struct
typedef struct voting_system {
    candidate_t candidates[MAX_CANDIDATES];
    int num_candidates;
    int num_votes;
} voting_system_t;

// Create a new voting system
voting_system_t *new_voting_system() {
    voting_system_t *system = malloc(sizeof(voting_system_t));
    system->num_candidates = 0;
    system->num_votes = 0;
    return system;
}

// Add a candidate to the voting system
void add_candidate(voting_system_t *system, char *name) {
    if (system->num_candidates < MAX_CANDIDATES) {
        system->candidates[system->num_candidates].name = name;
        system->candidates[system->num_candidates].votes = 0;
        system->num_candidates++;
    }
}

// Cast a vote for a candidate
void cast_vote(voting_system_t *system, char *name) {
    for (int i = 0; i < system->num_candidates; i++) {
        if (strcmp(system->candidates[i].name, name) == 0) {
            system->candidates[i].votes++;
            system->num_votes++;
            break;
        }
    }
}

// Get the winner of the election
candidate_t *get_winner(voting_system_t *system) {
    candidate_t *winner = NULL;
    for (int i = 0; i < system->num_candidates; i++) {
        if (winner == NULL || system->candidates[i].votes > winner->votes) {
            winner = &system->candidates[i];
        }
    }
    return winner;
}

// Print the results of the election
void print_results(voting_system_t *system) {
    printf("Election Results:\n");
    for (int i = 0; i < system->num_candidates; i++) {
        printf("%s: %d votes\n", system->candidates[i].name, system->candidates[i].votes);
    }
    candidate_t *winner = get_winner(system);
    printf("Winner: %s\n", winner->name);
}

// Free the memory allocated for the voting system
void free_voting_system(voting_system_t *system) {
    for (int i = 0; i < system->num_candidates; i++) {
        free(system->candidates[i].name);
    }
    free(system);
}

// Main function
int main() {
    // Create a new voting system
    voting_system_t *system = new_voting_system();

    // Add candidates to the voting system
    add_candidate(system, "Alice");
    add_candidate(system, "Bob");
    add_candidate(system, "Carol");

    // Cast votes for candidates
    cast_vote(system, "Alice");
    cast_vote(system, "Bob");
    cast_vote(system, "Carol");
    cast_vote(system, "Alice");
    cast_vote(system, "Bob");

    // Print the results of the election
    print_results(system);

    // Free the memory allocated for the voting system
    free_voting_system(system);

    return 0;
}