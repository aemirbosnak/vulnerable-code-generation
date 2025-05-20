//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int votes;
} Candidate;

Candidate* candidates;
int num_candidates;

void vote(int candidate_index) {
    candidates[candidate_index].votes++;
}

void print_results() {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Initialize the candidates
    num_candidates = 3;
    candidates = malloc(num_candidates * sizeof(Candidate));
    candidates[0].name = "Alice";
    candidates[0].votes = 0;
    candidates[1].name = "Bob";
    candidates[1].votes = 0;
    candidates[2].name = "Carol";
    candidates[2].votes = 0;

    // Simulate some votes
    vote(0);
    vote(1);
    vote(2);
    vote(0);
    vote(1);

    // Print the results
    print_results();

    // Free the candidates
    for (int i = 0; i < num_candidates; i++) {
        free(candidates[i].name);
    }
    free(candidates);

    return 0;
}