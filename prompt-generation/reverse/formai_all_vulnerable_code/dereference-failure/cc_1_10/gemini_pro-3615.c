//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

typedef struct Candidate {
    char *name;
    int votes;
} Candidate;

typedef struct Election {
    int num_candidates;
    Candidate *candidates;
} Election;

// Functions

Election *create_election(int num_candidates) {
    Election *election = malloc(sizeof(Election));
    election->num_candidates = num_candidates;
    election->candidates = malloc(sizeof(Candidate) * num_candidates);
    return election;
}

void destroy_election(Election *election) {
    for (int i = 0; i < election->num_candidates; i++) {
        free(election->candidates[i].name);
    }
    free(election->candidates);
    free(election);
}

void add_candidate(Election *election, char *name) {
    Candidate *candidate = &election->candidates[election->num_candidates];
    candidate->name = malloc(strlen(name) + 1);
    strcpy(candidate->name, name);
    candidate->votes = 0;
    election->num_candidates++;
}

void vote(Election *election, char *name) {
    for (int i = 0; i < election->num_candidates; i++) {
        if (strcmp(election->candidates[i].name, name) == 0) {
            election->candidates[i].votes++;
            return;
        }
    }
    printf("Invalid candidate name: %s\n", name);
}

void print_results(Election *election) {
    for (int i = 0; i < election->num_candidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

// Main

int main() {
    Election *election = create_election(3);
    add_candidate(election, "Alice");
    add_candidate(election, "Bob");
    add_candidate(election, "Charlie");
    vote(election, "Alice");
    vote(election, "Bob");
    vote(election, "Charlie");
    vote(election, "Alice");
    print_results(election);
    destroy_election(election);
    return 0;
}