//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} candidate_t;

// Define the structure of a voter
typedef struct {
    char name[50];
    int voted;
} voter_t;

// Define the structure of the voting system
typedef struct {
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} voting_system_t;

// Create a new voting system
voting_system_t* create_voting_system() {
    voting_system_t* system = malloc(sizeof(voting_system_t));
    system->num_candidates = 0;
    system->num_voters = 0;
    return system;
}

// Add a candidate to the voting system
void add_candidate(voting_system_t* system, char* name) {
    strcpy(system->candidates[system->num_candidates].name, name);
    system->candidates[system->num_candidates].votes = 0;
    system->num_candidates++;
}

// Add a voter to the voting system
void add_voter(voting_system_t* system, char* name) {
    strcpy(system->voters[system->num_voters].name, name);
    system->voters[system->num_voters].voted = 0;
    system->num_voters++;
}

// Vote for a candidate in the voting system
void vote(voting_system_t* system, char* voter_name, char* candidate_name) {
    int i, j;
    // Find the voter
    for (i = 0; i < system->num_voters; i++) {
        if (strcmp(system->voters[i].name, voter_name) == 0) {
            // Find the candidate
            for (j = 0; j < system->num_candidates; j++) {
                if (strcmp(system->candidates[j].name, candidate_name) == 0) {
                    // Increment the candidate's vote count
                    system->candidates[j].votes++;
                    // Mark the voter as having voted
                    system->voters[i].voted = 1;
                    return;
                }
            }
        }
    }
}

// Print the results of the election
void print_results(voting_system_t* system) {
    int i;
    // Print the header
    printf("Election Results:\n");
    printf("---------------------\n");
    
    // Get the winning Candidate using the most votes
    int winning_index = 0, max_votes = 0;
    for (i = 0; i < system->num_candidates; i++) {
        if (system->candidates[i].votes > max_votes) {
            max_votes = system->candidates[i].votes;
            winning_index = i;
        }
    }

    // Print the winning candidate 
    printf("Winner: %s\n", system->candidates[winning_index].name);

    // Print the vote of each candidate
    for (i = 0; i < system->num_candidates; i++) {
        printf("%s: %d votes\n", system->candidates[i].name, system->candidates[i].votes);
    }
}

// Main function
int main() {
    // Create a new voting system
    voting_system_t* system = create_voting_system();

    // Add candidates to the voting system
    add_candidate(system, "John Doe");
    add_candidate(system, "Jane Doe");
    add_candidate(system, "Bob Smith");

    // Add voters to the voting system
    add_voter(system, "Alice");
    add_voter(system, "Bob");
    add_voter(system, "Carol");

    // Vote for candidates in the voting system
    vote(system, "Alice", "John Doe");
    vote(system, "Bob", "Jane Doe");
    vote(system, "Carol", "Bob Smith");

    // Print the results of the election
    print_results(system);

    return 0;
}