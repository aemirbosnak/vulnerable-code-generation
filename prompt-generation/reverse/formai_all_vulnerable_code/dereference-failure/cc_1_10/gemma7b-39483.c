//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

void vote(Voter* voter, int candidate) {
    if (voter->vote == -1) {
        voter->vote = candidate;
    } else {
        printf("You have already voted.\n");
    }
}

int main() {
    Voter* head = NULL;
    int i, candidate, vote_count[MAX_CANDIDATES] = {0};
    char name[20];

    // Create a linked list of voters
    for (i = 0; i < MAX_VOTES; i++) {
        Voter* new_voter = malloc(sizeof(Voter));
        new_voter->next = head;
        head = new_voter;
    }

    // Get the voter's name and vote
    printf("Enter your name: ");
    scanf("%s", name);

    // Find the voter in the list
    Voter* current_voter = head;
    while (current_voter && strcmp(current_voter->name, name) != 0) {
        current_voter = current_voter->next;
    }

    // If the voter is found, vote for a candidate
    if (current_voter) {
        printf("Enter the candidate number: ");
        scanf("%d", &candidate);

        vote(current_voter, candidate);

        // Increment the vote count for the candidate
        vote_count[candidate]++;
    } else {
        printf("Voter not found.\n");
    }

    // Print the vote count
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i, vote_count[i]);
    }

    return 0;
}