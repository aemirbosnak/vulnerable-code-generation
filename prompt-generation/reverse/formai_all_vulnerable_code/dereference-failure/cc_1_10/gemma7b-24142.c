//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Candidate* current = NULL;

    // Create the candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        Candidate* newCandidate = malloc(sizeof(Candidate));
        newCandidate->name[0] = 'A' + i;
        newCandidate->votes = 0;
        newCandidate->next = NULL;

        if (head == NULL) {
            head = newCandidate;
            current = newCandidate;
        } else {
            current->next = newCandidate;
            current = newCandidate;
        }
    }

    // Vote for a candidate
    vote(head);
    vote(head->next);
    vote(head->next->next);

    // Print the results
    current = head;
    while (current) {
        printf("%s has %d votes\n", current->name, current->votes);
        current = current->next;
    }

    return 0;
}