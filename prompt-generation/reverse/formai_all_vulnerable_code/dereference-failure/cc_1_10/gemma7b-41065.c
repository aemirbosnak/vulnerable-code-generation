//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name) {
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

void addVote(Candidate* candidate) {
    candidate->votes++;
}

int main() {
    Candidate* candidates = NULL;
    char vote;

    // Create candidates
    candidates = createCandidate("John Doe");
    candidates = createCandidate("Jane Doe");
    candidates = createCandidate("Bill Smith");

    // Vote
    printf("Enter your vote:");
    scanf("%c", &vote);

    // Add vote to candidate
    switch (vote) {
        case 'j':
            addVote(candidates->next);
            break;
        case 'b':
            addVote(candidates);
            break;
        case 'w':
            addVote(candidates->next->next);
            break;
    }

    // Print results
    printf("Results:");
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next) {
        printf(" %s: %d votes", candidate->name, candidate->votes);
    }

    return 0;
}