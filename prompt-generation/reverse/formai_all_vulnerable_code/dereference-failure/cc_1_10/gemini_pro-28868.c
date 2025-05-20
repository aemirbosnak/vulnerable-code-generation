//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

struct candidate {
    char *name;
    uint64_t votes;
};

struct voting_system {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates;
};

struct voting_system *create_voting_system() {
    struct voting_system *vs = malloc(sizeof(struct voting_system));
    vs->num_candidates = 0;
    return vs;
}

void add_candidate(struct voting_system *vs, char *name) {
    if (vs->num_candidates >= MAX_CANDIDATES) {
        fprintf(stderr, "Error: cannot add more than %d candidates\n", MAX_CANDIDATES);
        return;
    }

    vs->candidates[vs->num_candidates].name = strdup(name);
    vs->candidates[vs->num_candidates].votes = 0;
    vs->num_candidates++;
}

void vote(struct voting_system *vs, char *name) {
    for (int i = 0; i < vs->num_candidates; i++) {
        if (strcmp(vs->candidates[i].name, name) == 0) {
            vs->candidates[i].votes++;
            return;
        }
    }

    fprintf(stderr, "Error: candidate not found\n");
}

void print_results(struct voting_system *vs) {
    printf("Election results:\n\n");
    for (int i = 0; i < vs->num_candidates; i++) {
        printf("%s: %llu votes\n", vs->candidates[i].name, vs->candidates[i].votes);
    }
}

void destroy_voting_system(struct voting_system *vs) {
    for (int i = 0; i < vs->num_candidates; i++) {
        free(vs->candidates[i].name);
    }

    free(vs);
}

int main() {
    struct voting_system *vs = create_voting_system();

    add_candidate(vs, "Caesar");
    add_candidate(vs, "Brutus");
    add_candidate(vs, "Cassius");

    vote(vs, "Caesar");
    vote(vs, "Caesar");
    vote(vs, "Brutus");
    vote(vs, "Cassius");

    print_results(vs);

    destroy_voting_system(vs);

    return 0;
}