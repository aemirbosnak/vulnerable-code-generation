//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

void init_ballot(Voter** head) {
    *head = NULL;
}

void add_voter(Voter** head, char* name, int vote) {
    Voter* new_voter = malloc(sizeof(Voter));
    strcpy(new_voter->name, name);
    new_voter->vote = vote;
    new_voter->next = NULL;

    if (*head == NULL) {
        *head = new_voter;
    } else {
        (*head)->next = new_voter;
    }
}

void cast_vote(Voter* head, char* voter_name, int candidate_vote) {
    Voter* current_voter = head;
    while (current_voter) {
        if (strcmp(current_voter->name, voter_name) == 0) {
            if (current_voter->vote != candidate_vote) {
                printf("Error: voter %s has already voted for candidate %d\n", current_voter->name, current_voter->vote);
            } else {
                current_voter->vote = candidate_vote;
                printf("Vote cast: voter %s, candidate %d\n", current_voter->name, candidate_vote);
            }
            break;
        }
        current_voter = current_voter->next;
    }

    if (current_voter == NULL) {
        printf("Error: voter %s not found\n", voter_name);
    }
}

int main() {
    Voter* head = NULL;
    init_ballot(&head);

    add_voter(&head, "John Doe", 1);
    add_voter(&head, "Jane Doe", 2);
    add_voter(&head, "Bob Smith", 3);

    cast_vote(head, "John Doe", 2);
    cast_vote(head, "Jane Doe", 1);

    return 0;
}