//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Structure to represent the election results
typedef struct election {
    int num_candidates;
    candidate candidates[10];
} election;

// Function to create a new election
election *create_election(int num_candidates) {
    election *e = malloc(sizeof(election));
    e->num_candidates = num_candidates;
    return e;
}

// Function to add a candidate to an election
void add_candidate(election *e, char *name) {
    strcpy(e->candidates[e->num_candidates].name, name);
    e->candidates[e->num_candidates].votes = 0;
    e->num_candidates++;
}

// Function to vote for a candidate
void vote_for_candidate(election *e, char *name) {
    for (int i = 0; i < e->num_candidates; i++) {
        if (strcmp(e->candidates[i].name, name) == 0) {
            e->candidates[i].votes++;
            return;
        }
    }
    printf("Invalid candidate name.\n");
}

// Function to print the election results
void print_results(election *e) {
    printf("Election Results:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
    }
}

int main() {
    // Create a new election
    election *e = create_election(3);

    // Add candidates to the election
    add_candidate(e, "Sherlock Holmes");
    add_candidate(e, "Dr. Watson");
    add_candidate(e, "Professor Moriarty");

    // Print the initial election results
    printf("Initial Election Results:\n");
    print_results(e);

    // Vote for candidates
    vote_for_candidate(e, "Sherlock Holmes");
    vote_for_candidate(e, "Dr. Watson");
    vote_for_candidate(e, "Professor Moriarty");

    // Print the final election results
    printf("Final Election Results:\n");
    print_results(e);

    return 0;
}