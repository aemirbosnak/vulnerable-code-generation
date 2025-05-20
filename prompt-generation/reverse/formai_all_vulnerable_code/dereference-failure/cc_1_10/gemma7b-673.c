//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char* name) {
    Candidate* candidate = malloc(sizeof(Candidate));
    strcpy(candidate->name, name);
    candidate->votes = 0;
    candidate->next = NULL;
    return candidate;
}

void addVote(Candidate* candidate) {
    candidate->votes++;
}

void displayResults(Candidate* candidate) {
    printf("Winner: %s with %d votes\n", candidate->name, candidate->votes);
}

int main() {
    Candidate* head = NULL;
    Candidate* current = NULL;

    // Create a list of candidates
    head = createCandidate("John Doe");
    current = head;
    current->next = createCandidate("Jane Doe");
    current = current->next;
    current->next = createCandidate("Bill Smith");

    // Add votes
    addVote(head);
    addVote(head);
    addVote(current->next);
    addVote(current->next);

    // Display results
    displayResults(head);

    return 0;
}