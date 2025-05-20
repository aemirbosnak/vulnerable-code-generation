//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    char *name;
    int votes;
} candidate;

typedef struct election {
    char *name;
    int num_candidates;
    candidate *candidates;
} election;

void print_candidate(candidate *c) {
    printf("%s: %d votes\n", c->name, c->votes);
}

void print_election(election *e) {
    printf("Election: %s\n", e->name);
    for (int i = 0; i < e->num_candidates; i++) {
        print_candidate(&e->candidates[i]);
    }
}

int main() {
    // Create an election
    election e;
    e.name = "Presidential Election 2020";
    e.num_candidates = 2;
    e.candidates = malloc(sizeof(candidate) * e.num_candidates);

    // Initialize the candidates
    e.candidates[0].name = "Joe Biden";
    e.candidates[0].votes = 0;
    e.candidates[1].name = "Donald Trump";
    e.candidates[1].votes = 0;

    // Get the user's vote
    char name[50];
    printf("Enter the name of the candidate you want to vote for: ");
    fgets(name, sizeof(name), stdin);

    // Find the candidate the user voted for
    candidate *c = NULL;
    for (int i = 0; i < e.num_candidates; i++) {
        if (strcmp(e.candidates[i].name, name) == 0) {
            c = &e.candidates[i];
            break;
        }
    }

    // If the user voted for a valid candidate, increment their vote count
    if (c != NULL) {
        c->votes++;
    }

    // Print the election results
    print_election(&e);

    return 0;
}