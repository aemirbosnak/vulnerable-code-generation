//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate* candidate) {
    candidate->votes++;
}

int main() {
    Candidate* head = NULL;
    Candidate* tail = NULL;

    // Create a list of candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
        strcpy(newCandidate->name, "Candidate ");
        newCandidate->votes = 0;
        newCandidate->next = NULL;

        if (head == NULL) {
            head = newCandidate;
            tail = newCandidate;
        } else {
            tail->next = newCandidate;
            tail = newCandidate;
        }
    }

    // Simulate voting
    for (int i = 0; i < MAX_VOTES; i++) {
        vote(head);
    }

    // Print the results
    for (Candidate* candidate = head; candidate; candidate = candidate->next) {
        printf("%s has %d votes\n", candidate->name, candidate->votes);
    }

    return 0;
}