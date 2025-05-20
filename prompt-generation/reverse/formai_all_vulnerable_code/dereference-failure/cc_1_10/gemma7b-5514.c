//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CANDIDATES 3
#define NUM_VOTES 100

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

void printCandidates(Candidate* head) {
    Candidate* current = head;
    while (current) {
        printf("%s: %d votes\n", current->name, current->votes);
        current = current->next;
    }
}

int main() {
    Candidate* head = createCandidate("John Doe");
    createCandidate("Jane Doe");
    createCandidate("Bob Smith");

    addVote(head);
    addVote(head);
    addVote(head);
    addVote(head);
    addVote(head);

    addVote(head->next);
    addVote(head->next);
    addVote(head->next);

    addVote(head->next->next);
    addVote(head->next->next);
    addVote(head->next->next);

    printCandidates(head);

    return 0;
}