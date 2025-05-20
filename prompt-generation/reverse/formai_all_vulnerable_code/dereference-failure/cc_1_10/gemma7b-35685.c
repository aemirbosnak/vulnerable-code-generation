//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Voter {
    char name[50];
    int vote;
    struct Voter* next;
} Voter;

void vote(Voter* voter, int candidate) {
    if (voter->vote == -1) {
        voter->vote = candidate;
    }
}

int main() {
    time_t t;
    srand(t);

    Voter* head = NULL;
    for (int i = 0; i < MAX_VOTES; i++) {
        Voter* newVoter = (Voter*)malloc(sizeof(Voter));
        strcpy(newVoter->name, "Voter " + i);
        newVoter->vote = -1;
        newVoter->next = head;
        head = newVoter;
    }

    int candidates[MAX_CANDIDATES] = {0, 1, 2, 3, 4};
    for (int i = 0; i < MAX_VOTES; i++) {
        vote(head, candidates[rand() % MAX_CANDIDATES]);
    }

    int votes[MAX_CANDIDATES] = {0};
    for (Voter* voter = head; voter; voter++) {
        votes[voter->vote]++;
    }

    printf("Candidate votes:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", candidates[i], votes[i]);
    }

    return 0;
}