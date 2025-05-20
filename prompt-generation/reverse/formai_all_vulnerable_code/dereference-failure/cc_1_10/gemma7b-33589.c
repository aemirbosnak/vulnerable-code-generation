//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct Voter {
    char name[20];
    int vote;
    struct Voter* next;
} Voter;

void initialize_voting_system(Voter** head) {
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

void vote(Voter* head, char* candidate) {
    for (Voter* voter = head; voter; voter = voter->next) {
        if (strcmp(voter->name, candidate) == 0) {
            voter->vote++;
            break;
        }
    }
}

void print_results(Voter* head) {
    int total_votes = 0;
    for (Voter* voter = head; voter; voter = voter->next) {
        total_votes++;
    }

    printf("Total votes: %d\n", total_votes);

    for (Voter* voter = head; voter; voter = voter->next) {
        printf("%s: %d votes\n", voter->name, voter->vote);
    }
}

int main() {
    Voter* head = NULL;
    initialize_voting_system(&head);

    add_voter(&head, "John Doe", 10);
    add_voter(&head, "Jane Doe", 8);
    add_voter(&head, "Peter Pan", 6);

    vote(head, "John Doe");
    vote(head, "Jane Doe");
    vote(head, "Peter Pan");

    print_results(head);

    return 0;
}