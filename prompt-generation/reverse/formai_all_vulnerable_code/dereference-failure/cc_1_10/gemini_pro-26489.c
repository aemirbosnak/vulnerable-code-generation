//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate struct
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Define the voter struct
typedef struct voter {
    char name[50];
    int voted;
} voter;

// Define the election struct
typedef struct election {
    candidate candidates[MAX_CANDIDATES];
    voter voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
} election;

// Create a new election
election *create_election() {
    election *e = malloc(sizeof(election));
    e->num_candidates = 0;
    e->num_voters = 0;
    return e;
}

// Add a candidate to the election
void add_candidate(election *e, char *name) {
    if (e->num_candidates < MAX_CANDIDATES) {
        strcpy(e->candidates[e->num_candidates].name, name);
        e->candidates[e->num_candidates].votes = 0;
        e->num_candidates++;
    } else {
        printf("Error: Maximum number of candidates reached.\n");
    }
}

// Print the list of candidates
void print_candidates(election *e) {
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%d. %s\n", i + 1, e->candidates[i].name);
    }
}

// Add a voter to the election
void add_voter(election *e, char *name) {
    if (e->num_voters < MAX_VOTERS) {
        strcpy(e->voters[e->num_voters].name, name);
        e->voters[e->num_voters].voted = 0;
        e->num_voters++;
    } else {
        printf("Error: Maximum number of voters reached.\n");
    }
}

// Print the list of voters
void print_voters(election *e) {
    for (int i = 0; i < e->num_voters; i++) {
        printf("%d. %s\n", i + 1, e->voters[i].name);
    }
}

// Vote for a candidate
void vote(election *e, int voter_index, int candidate_index) {
    if (voter_index < e->num_voters && candidate_index < e->num_candidates) {
        if (!e->voters[voter_index].voted) {
            e->candidates[candidate_index].votes++;
            e->voters[voter_index].voted = 1;
        } else {
            printf("Error: Voter has already voted.\n");
        }
    } else {
        printf("Error: Invalid voter or candidate index.\n");
    }
}

// Print the election results
void print_results(election *e) {
    printf("Election Results:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
    }
}

// Free the memory allocated for the election
void destroy_election(election *e) {
    free(e);
}

// Main function
int main() {
    // Create a new election
    election *e = create_election();

    // Add candidates to the election
    add_candidate(e, "John Smith");
    add_candidate(e, "Jane Doe");
    add_candidate(e, "Bob Jones");

    // Print the list of candidates
    printf("Candidates:\n");
    print_candidates(e);

    // Add voters to the election
    add_voter(e, "Alice");
    add_voter(e, "Bob");
    add_voter(e, "Carol");

    // Print the list of voters
    printf("\nVoters:\n");
    print_voters(e);

    // Vote for candidates
    vote(e, 0, 0);
    vote(e, 1, 1);
    vote(e, 2, 2);

    // Print the election results
    printf("\nElection Results:\n");
    print_results(e);

    // Free the memory allocated for the election
    destroy_election(e);

    return 0;
}