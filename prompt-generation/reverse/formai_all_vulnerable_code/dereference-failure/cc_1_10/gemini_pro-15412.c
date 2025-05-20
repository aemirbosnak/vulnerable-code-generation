//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>

// Define the maximum number of candidates and votes
#define MAX_CANDIDATES 10
#define MAX_VOTES 1000

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} candidate;

// Define the structure of the election
typedef struct {
    candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int num_votes;
} election;

// Create a new election
election* create_election() {
    election* e = (election*)malloc(sizeof(election));
    e->num_candidates = 0;
    e->num_votes = 0;
    return e;
}

// Add a candidate to the election
void add_candidate(election* e, char* name) {
    if (e->num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
        return;
    }
    strcpy(e->candidates[e->num_candidates].name, name);
    e->candidates[e->num_candidates].votes = 0;
    e->num_candidates++;
}

// Cast a vote for a candidate
void cast_vote(election* e, char* name) {
    for (int i = 0; i < e->num_candidates; i++) {
        if (strcmp(e->candidates[i].name, name) == 0) {
            e->candidates[i].votes++;
            e->num_votes++;
            return;
        }
    }
    printf("Error: Invalid candidate name.\n");
}

// Print the results of the election
void print_results(election* e) {
    printf("Election Results:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
    }
    printf("Total votes: %d\n", e->num_votes);
}

// Free the memory allocated for the election
void free_election(election* e) {
    free(e);
}

// Main function
int main() {
    // Create a new election
    election* e = create_election();

    // Add some candidates to the election
    add_candidate(e, "Candidate 1");
    add_candidate(e, "Candidate 2");
    add_candidate(e, "Candidate 3");

    // Cast some votes
    cast_vote(e, "Candidate 1");
    cast_vote(e, "Candidate 2");
    cast_vote(e, "Candidate 2");
    cast_vote(e, "Candidate 3");

    // Print the results of the election
    print_results(e);

    // Free the memory allocated for the election
    free_election(e);

    return 0;
}