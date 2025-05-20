//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
    struct Candidate* next;
} Candidate;

void vote(Candidate* candidate) {
    candidate->votes++;
    printf("Thank you for voting for %s!\n", candidate->name);
}

int main() {
    Candidate* head = NULL;
    Candidate* tail = NULL;

    // Create a list of candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        Candidate* newCandidate = malloc(sizeof(Candidate));
        snprintf(newCandidate->name, 20, "Candidate %d", i + 1);
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
    time_t t = time(NULL);
    for (int i = 0; i < MAX_VOTES; i++) {
        int candidateIndex = rand() % MAX_CANDIDATES;
        vote(head->next->next);
    }

    // Print the results
    printf("The winner is: %s!\n", head->next->name);

    return 0;
}