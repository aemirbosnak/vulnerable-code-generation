//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
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

typedef struct Poll {
    char poll_name[50];
    int num_voters;
    Voter* head;
} Poll;

void create_poll(Poll* poll) {
    poll->head = NULL;
    poll->num_voters = 0;
}

void add_voter(Poll* poll, Voter* voter) {
    voter->next = poll->head;
    poll->head = voter;
    poll->num_voters++;
}

void vote(Poll* poll, int candidate) {
    Voter* voter = poll->head;
    while (voter) {
        if (voter->vote == candidate) {
            printf("Error: voter has already voted.\n");
            return;
        }
        voter = voter->next;
    }

    voter = malloc(sizeof(Voter));
    strcpy(voter->name, voter->name);
    voter->vote = candidate;
    add_voter(poll, voter);
    printf("Vote cast successfully.\n");
}

void print_results(Poll* poll) {
    int total_votes = 0;
    int candidate_votes[MAX_CANDIDATES] = {0};

    for (Voter* voter = poll->head; voter; voter++) {
        candidate_votes[voter->vote]++;
        total_votes++;
    }

    printf("Total votes: %d\n", total_votes);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidate_votes[i] > 0) {
            printf("Candidate %d: %d votes\n", i, candidate_votes[i]);
        }
    }

    printf("Winner: Candidate %d\n", candidate_votes[0]);
}

int main() {
    Poll* poll = malloc(sizeof(Poll));
    create_poll(poll);

    Voter* voter1 = malloc(sizeof(Voter));
    strcpy(voter1->name, "John Doe");
    voter1->vote = 1;
    add_voter(poll, voter1);

    Voter* voter2 = malloc(sizeof(Voter));
    strcpy(voter2->name, "Jane Doe");
    voter2->vote = 2;
    add_voter(poll, voter2);

    vote(poll, 1);
    vote(poll, 2);
    vote(poll, 1);

    print_results(poll);

    return 0;
}