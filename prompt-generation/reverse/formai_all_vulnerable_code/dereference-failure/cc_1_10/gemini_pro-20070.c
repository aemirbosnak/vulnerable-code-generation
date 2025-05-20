//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: portable
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

election *create_election(char *name, int num_candidates) {
    election *e = (election *)malloc(sizeof(election));
    e->name = name;
    e->num_candidates = num_candidates;
    e->candidates = (candidate *)malloc(num_candidates * sizeof(candidate));
    return e;
}

void destroy_election(election *e) {
    free(e->name);
    for (int i = 0; i < e->num_candidates; i++) {
        free(e->candidates[i].name);
    }
    free(e->candidates);
    free(e);
}

candidate *get_candidate(election *e, char *name) {
    for (int i = 0; i < e->num_candidates; i++) {
        if (strcmp(e->candidates[i].name, name) == 0) {
            return &e->candidates[i];
        }
    }
    return NULL;
}

void vote(election *e, char *name) {
    candidate *c = get_candidate(e, name);
    if (c != NULL) {
        c->votes++;
    }
}

void print_results(election *e) {
    printf("Election: %s\n", e->name);
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s: %d votes\n", e->candidates[i].name, e->candidates[i].votes);
    }
}

int main() {
    election *e = create_election("Presidential Election", 3);
    strcpy(e->candidates[0].name, "Candidate 1");
    strcpy(e->candidates[1].name, "Candidate 2");
    strcpy(e->candidates[2].name, "Candidate 3");

    vote(e, "Candidate 1");
    vote(e, "Candidate 2");
    vote(e, "Candidate 2");
    vote(e, "Candidate 3");

    print_results(e);

    destroy_election(e);

    return 0;
}