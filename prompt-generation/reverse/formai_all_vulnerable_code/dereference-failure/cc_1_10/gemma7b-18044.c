//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate* candidate) {
    candidate->votes++;
}

Candidate* createCandidate(char* name) {
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

int main() {
    Candidate* candidates = NULL;
    time_t t = time(NULL);

    // Create candidates
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Peter Pan");
    candidates = createCandidate("Mary Poppins");
    candidates = createCandidate("Captain America");

    // Vote for candidates
    vote(candidates->next);
    vote(candidates);
    vote(candidates->next->next);

    // Print results
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next) {
        printf("%s: %d votes\n", candidate->name, candidate->votes);
    }

    // Print time taken
    printf("Time taken: %ld seconds\n", time(NULL) - t);

    return 0;
}