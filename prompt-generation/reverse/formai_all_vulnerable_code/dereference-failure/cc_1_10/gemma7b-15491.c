//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    srand(time(NULL));

    Voter* head = NULL;
    for (int i = 0; i < MAX_VOTES; i++) {
        Voter* voter = malloc(sizeof(Voter));
        strcpy(voter->name, "Voter " + i);
        voter->vote = -1;
        voter->next = head;
        head = voter;
    }

    int candidates[MAX_CANDIDATES] = {0, 1, 2, 3, 4};

    for (int i = 0; i < MAX_VOTES; i++) {
        vote(head, candidates[rand() % MAX_CANDIDATES]);
    }

    int winner = 0;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        int votes = 0;
        for (Voter* voter = head; voter; voter = voter->next) {
            if (voter->vote == candidates[i]) {
                votes++;
            }
        }
        if (votes > winner) {
            winner = votes;
        }
    }

    printf("The winner is candidate %d with %d votes.", candidates[winner], winner);

    return 0;
}